AC_DEFUN([AX_PYTHON_MODULE], [
  AC_MSG_CHECKING([for python $1 module])
  pop_cv_python_have_module=$($PYTHON -c "import $1" 2>/dev/null 1>&2 && echo "yes")
  AS_IF([test "x$pop_cv_python_have_module" != "xyes"], [
    AC_MSG_RESULT([no])
    AC_MSG_ERROR([Python package $1 is missing, is it installed?])
  ], [
    AC_MSG_RESULT([yes])
  ])
])
