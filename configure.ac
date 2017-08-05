AC_INIT([pop], [0.1])

AC_CONFIG_HEADERS([Pop/Config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AM_SILENT_RULES([yes])

AC_PATH_PROG([FLEX], [flex])
AC_PATH_PROG([BISON], [bison])
AM_PATH_PYTHON([3.0])
AX_PYTHON_MODULE([jinja2])
AX_CXX_COMPILE_STDCXX_14([noext], [mandatory])

AC_CONFIG_FILES([
 Makefile
 Pop/Makefile
 scripts/Makefile
 tests/Makefile
])
AC_OUTPUT
