dnl $Id$
dnl config.m4 for extension operator

PHP_ARG_ENABLE([operator],
  [whether to enable operator support],
  [AS_HELP_STRING([--enable-operator],
    [Enable operator support])],
  [no])

if test "$PHP_OPERATOR" != "no"; then
  AC_DEFINE(HAVE_OPERATOR, 1, [ Have operator support ])
  PHP_NEW_EXTENSION(operator, operator.c, $ext_shared)
fi
