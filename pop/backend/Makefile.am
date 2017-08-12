AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_builddir) \
	-DPOP_LIB_COMPILATION_=1 \
	-DPOP_LIB_BACKEND_COMPILATION_=1

lib_LTLIBRARIES = libpop-backend.la

libpop_backend_la_SOURCES = \
	bytecode-generator.cpp \
	bytecode-generator.hpp

libpop_backend_la_LIBADD = \
	$(top_builddir)/pop/common/libpop-common.la \
	$(top_builddir)/pop/ir/libpop-ir.la

popcodegenincludedir = $(includedir)/pop/backend
popcodegeninclude_HEADERS = bytecode-generator.hpp
