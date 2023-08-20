#ifdef HAVE_CONFIG_H

#include <zend_interfaces.h>
#include "config.h"

#endif

#include "php.h"
#include "operators.h"
#include "operators_macros.h"

PHP_FUNCTION(register_operator_overload) {
    zend_string *class_name;
    zend_long operator;
    zval *callable;

    ZEND_PARSE_PARAMETERS_START(3, 3)
            Z_PARAM_STR(class_name)
            Z_PARAM_LONG(operator)
            Z_PARAM_ZVAL(callable)
    ZEND_PARSE_PARAMETERS_END();

    if (Z_TYPE_P(callable) != IS_CALLABLE) {
        zend_error(E_WARNING, "The callable argument is not a valid callable");
        RETURN_FALSE;
    }

    // Get the registered overloads for this class
    zval * registered_overloads = zend_hash_find(Z_ARRVAL(operators_globals.registered_overloads), class_name);
    if (registered_overloads == NULL) {
        // If there are no overloads registered for this class, create a new array
        array_init(registered_overloads);
        zend_hash_add(Z_ARRVAL(operators_globals.registered_overloads), class_name, registered_overloads);
    }
    // Add the callable to the array
    zend_hash_index_add(Z_ARRVAL_P(registered_overloads), operator, callable);

    RETURN_TRUE;
}

static int handle_operator(zend_execute_data *execute_data, char *magic_method) {
    DEBUG_PRINTF("Checking if %s is callable\n", magic_method)
    USE_OPLINE;
    zval * op1, *op2 = NULL;

    if (strcmp(magic_method, "__assign_op") == 0) {
        DEBUG_PRINTF("This is an assignment with an operation\n")
        switch (opline->extended_value) {
            ASSIGN_OPERATORS(ASSIGN_OPERATORS_METHOD_SWITCH)
            default:
                return ZEND_USER_OPCODE_DISPATCH;
        }
    }

    if (opline->op1_type == IS_UNUSED) {
        op1 = EX_VAR(opline->result.var);
    } else {
        op1 = zend_get_zval_ptr(execute_data->opline, execute_data->opline->op1_type, &execute_data->opline->op1, execute_data);
    }
    op2 = zend_get_zval_ptr(execute_data->opline, execute_data->opline->op2_type, &execute_data->opline->op2, execute_data);

    if ((Z_TYPE_P(op1) != IS_OBJECT)) {
        DEBUG_PRINTF("op1 is not an object\n")
        return ZEND_USER_OPCODE_DISPATCH;
    }

    DEBUG_PRINTF("op1 is an object\n")

    zend_fcall_info fci = empty_fcall_info;
    zend_fcall_info_cache fcc = empty_fcall_info_cache;
    fci.size = sizeof(zend_fcall_info);
    fci.retval = EX_VAR(opline->result.var);
    fci.param_count = op2 ? 1 : 0;
    fci.params = op2;
    fci.object = Z_OBJ_P(op1);

    fcc.called_scope = Z_OBJCE_P(op1);
    fcc.object = Z_OBJ_P(op1);

    // Check if there are any overloads registered for this class
    zval * registered_overloads = zend_hash_find(Z_ARRVAL(operators_globals.registered_overloads), Z_OBJCE_P(op1)->name);
    // If there are not we continue as normal
    // If there are we check if there is an overload for this operator
    if (registered_overloads != NULL) {
        zval * registered_overload = zend_hash_index_find(Z_ARRVAL_P(registered_overloads), opline->opcode);
        if (registered_overload != NULL) {
            // If there is an overload we call it
            DEBUG_PRINTF("Calling registered overload\n")
            if (zend_call_function(&fci, &fcc) == FAILURE) {
                DEBUG_PRINTF("Function call failed\n")
                return ZEND_USER_OPCODE_DISPATCH;
            }
            DEBUG_PRINTF("Function call succeeded\n")

            execute_data->opline++;
            return ZEND_USER_OPCODE_CONTINUE;
        }
    }

    zend_string * magic_method_name = zend_string_init(magic_method, strlen(magic_method), 0);
    fcc.function_handler = zend_hash_find_ptr(&Z_OBJCE_P(op1)->function_table, magic_method_name);

    if (fcc.function_handler == NULL) {
        DEBUG_PRINTF("Function handler is null\n")
        return ZEND_USER_OPCODE_DISPATCH;
    }

    DEBUG_PRINTF("Calling %s\n", magic_method)
    if (zend_call_function(&fci, &fcc) == FAILURE) {
        DEBUG_PRINTF("Function call failed\n")
        return ZEND_USER_OPCODE_DISPATCH;
    }
    DEBUG_PRINTF("Function call succeeded\n")

    execute_data->opline++;
    return ZEND_USER_OPCODE_CONTINUE;
}

OPERATORS(OPERATOR_HANDLE)

/* {{{ operators_module_entry */
zend_module_entry operators_module_entry = {
        STANDARD_MODULE_HEADER,
        "operators",                    /* Extension name */
        NULL,                           /* zend_function_entry */
        PHP_MINIT(operators),           /* PHP_MINIT - Module initialization */
        PHP_MSHUTDOWN(operators),       /* PHP_MSHUTDOWN - Module shutdown */
        NULL,                           /* PHP_RINIT - Request initialization */
        NULL,                           /* PHP_RSHUTDOWN - Request shutdown */
        PHP_MINFO(operators),           /* PHP_MINFO - Module info */
        PHP_OPERATORS_VERSION,          /* Version */
        STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_OPERATORS
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif

ZEND_GET_MODULE(operators)

#endif
