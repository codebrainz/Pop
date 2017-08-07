AC_INIT([pop], [0.1], [https://github.com/codebrainz/pop/issues])

AC_CONFIG_HEADERS([Pop/Config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AM_SILENT_RULES([yes])
AM_MAINTAINER_MODE

AC_PROG_RANLIB
AM_PROG_AR
AX_CXX_COMPILE_STDCXX_14([noext], [mandatory])

AS_IF([test "x$enable_maintainer_mode" = "xyes"], [
  AC_PATH_PROG([FLEX], [flex], [no])
  AS_IF([test "x$FLEX" = "xno"], [
    AC_MSG_ERROR([unable to locate flex, is it installed?])
  ])
  AC_PATH_PROG([BISON], [bison], [no])
  AS_IF([test "x$BISON" = "xno"], [
    AC_MSG_ERROR([unable to locate bison, is it installed?])
  ])
  AM_PATH_PYTHON([3.0])
  AX_PYTHON_MODULE([jinja2])
])

AC_CONFIG_FILES([
 Makefile
 Pop/Makefile
 Compiler/Makefile
 Disassembler/Makefile
 docs/Makefile
 scripts/Makefile
 tests/Makefile
])
AC_OUTPUT
