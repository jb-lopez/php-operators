/*
   +----------------------------------------------------------------------+
   | Copyright (c) The PHP Group                                          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | https://www.php.net/license/3_01.txt                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Joshua Lopez <lopezcoder@gmail.com>                          |
   +----------------------------------------------------------------------+
*/
#ifdef HAVE_CONFIG_H

#include <zend_interfaces.h>
# include "config.h"

#endif

#include "php.h"
#include "operators.h"
#include "operators_macros.h"

static int handle_operator(zend_execute_data *execute_data, char *magic_method) {
    if (operators_globals.debug) {
        printf("Checking if %s is callable\n", magic_method);
    }
    USE_OPLINE;
    zval * op1, *op2 = NULL;

    if (strcmp(magic_method, "__assign_op") == 0) {
        if (operators_globals.debug) {
            printf("This is an assignment with an operation\n");
        }
        switch (opline->extended_value) {
            ASSIGN_OPERATORS(ASSIGN_OPERATORS_METHOD_SWITCH)
            default:
                return ZEND_USER_OPCODE_DISPATCH;
        }
    }

    op1 = zend_get_zval_ptr(execute_data->opline, execute_data->opline->op1_type, &execute_data->opline->op1, execute_data);
    op2 = zend_get_zval_ptr(execute_data->opline, execute_data->opline->op2_type, &execute_data->opline->op2, execute_data);

    if ((Z_TYPE_P(op1) != IS_OBJECT)) {
        /* op1 is not an object */
        if (operators_globals.debug) {
            printf("op1 is not an object\n");
        }
        return ZEND_USER_OPCODE_DISPATCH;
    }

    if (operators_globals.debug) {
        printf("op1 is an object\n");
    }

    zend_fcall_info fci = empty_fcall_info;
    zend_fcall_info_cache fcc = empty_fcall_info_cache;

    zend_class_entry * ce = Z_OBJCE_P(op1);
    zend_string * magic_method_name = zend_string_init(magic_method, strlen(magic_method), 0);
    zval params[1];
    ZVAL_COPY(&params[0], op2);

    fci.size = sizeof(zend_fcall_info);
    fci.retval = EX_VAR(opline->result.var);
    fci.param_count = 1;
    fci.params = params;
    fci.object = Z_OBJ_P(op1);

    fcc.called_scope = ce;
    fcc.object = Z_OBJ_P(op1);
    fcc.function_handler = zend_hash_find_ptr(&ce->function_table, magic_method_name);

    if (fcc.function_handler == NULL) {
        if (operators_globals.debug) {
            printf("Function handler is null\n");
        }
        return ZEND_USER_OPCODE_DISPATCH;
    }

    if (operators_globals.debug) {
        printf("Calling %s\n", magic_method);
    }

    if (zend_call_function(&fci, &fcc) == FAILURE) {
        if (operators_globals.debug) {
            printf("Function call failed\n");
        }
        return ZEND_USER_OPCODE_DISPATCH;
    }

    if (operators_globals.debug) {
        printf("Function call succeeded\n");
    }

    EX(opline) = opline + 1;
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
