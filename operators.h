#ifndef OPERATORS_OPERATORS_H
#define OPERATORS_OPERATORS_H

#include "php.h"
#include "ext/standard/info.h"
#include "operators_macros.h"

extern zend_module_entry operators_module_entry;
# define phpext_operators_ptr &operators_module_entry

# define PHP_OPERATORS_VERSION "0.5.0"

# if defined(ZTS) && defined(COMPILE_DL_OPERATORS)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

ZEND_BEGIN_MODULE_GLOBALS(operators)
    zend_bool debug;

    OPERATORS(OPERATOR_GLOBAL)
ZEND_END_MODULE_GLOBALS(operators)

zend_operators_globals operators_globals;

OPERATORS(OPERATOR_LOCAL)

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION (operators) {
    operators_globals.debug = 0;

    OPERATORS(OPERATOR_MINIT)

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION (operators) {
    OPERATORS(OPERATOR_MSHUTDOWN)

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION (operators) {
    php_info_print_table_start();
    php_info_print_table_header(2, "operators support", "enabled");
    php_info_print_table_row(2, "operators version", PHP_OPERATORS_VERSION);
    php_info_print_table_end();
}
/* }}} */

#endif //OPERATORS_OPERATORS_H
