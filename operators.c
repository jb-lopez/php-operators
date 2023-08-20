#ifdef HAVE_CONFIG_H

#include <zend_interfaces.h>
#include "config.h"

#endif

#include "php.h"
#include "operators.h"
#include "operators_macros.h"

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
    zend_string * magic_method_name = zend_string_init(magic_method, strlen(magic_method), 0);

    fci.size = sizeof(zend_fcall_info);
    fci.retval = EX_VAR(opline->result.var);
    fci.param_count = op2 ? 1 : 0;
    fci.params = op2;
    fci.object = Z_OBJ_P(op1);

    fcc.called_scope = Z_OBJCE_P(op1);
    fcc.object = Z_OBJ_P(op1);
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
