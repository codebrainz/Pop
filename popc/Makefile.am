AM_CPPFLAGS = -I$(top_srcdir) -I$(top_builddir)
bin_PROGRAMS = popc
popc_LDADD = \
	$(top_builddir)/pop/frontend/libpop-frontend.a \
	$(top_builddir)/pop/common/libpop-common.a
popc_SOURCES = main.cpp options.cpp options.hpp
