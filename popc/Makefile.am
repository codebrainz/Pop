AM_CPPFLAGS = -I$(top_srcdir) -I$(top_builddir)
bin_PROGRAMS = popc

popc_LDADD = \
	$(top_builddir)/pop/common/libpop-common.la \
	$(top_builddir)/pop/frontend/libpop-frontend.la \
	$(top_builddir)/pop/ir/libpop-ir.la

popc_SOURCES = \
	compiler.cpp \
	compiler.hpp \
	main.cpp \
	options.cpp \
	options.hpp
