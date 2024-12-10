#ifndef OPERATOR_OPERATOR_H
#define OPERATOR_OPERATOR_H

#include "php.h"
#include "ext/standard/info.h"
#include "operator_macros.h"

extern zend_module_entry operator_module_entry;
# define phpext_operator_ptr &operator_module_entry

# define PHP_OPERATOR_VERSION "0.5.0"

# if defined(ZTS) && defined(COMPILE_DL_OPERATOR)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

ZEND_BEGIN_MODULE_GLOBALS(operator)
    zend_bool debug;
    OPERATOR(OPERATOR_GLOBAL)
ZEND_END_MODULE_GLOBALS(operator)

zend_operator_globals operator_globals;

OPERATOR(OPERATOR_LOCAL)

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION (operator) {
    operator_globals.debug = 0;

    OPERATOR(OPERATOR_MINIT)

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION (operator) {
    OPERATOR(OPERATOR_MSHUTDOWN)

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION (operator) {
    php_info_print_table_start();
    php_info_print_table_header(2, "operator support", "enabled");
    php_info_print_table_row(2, "operator version", PHP_OPERATOR_VERSION);
    php_info_print_table_end();
}
/* }}} */

#endif //OPERATOR_OPERATOR_H
