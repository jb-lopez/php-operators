dnl $Id$
dnl config.m4 for extension operators

PHP_ARG_ENABLE([operators],
  [whether to enable operators support],
  [AS_HELP_STRING([--enable-operators],
    [Enable operators support])],
  [no])

if test "$PHP_OPERATORS" != "no"; then
  AC_DEFINE(HAVE_OPERATORS, 1, [ Have operators support ])
  PHP_NEW_EXTENSION(operators, operators.c, $ext_shared)
fi
