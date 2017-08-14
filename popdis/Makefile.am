AM_CPPFLAGS = -I$(top_srcdir) -I$(top_builddir)
bin_PROGRAMS = popdis

popdis_LDADD = \
	$(top_builddir)/pop/backend/libpop-backend.la \
	$(top_builddir)/pop/common/libpop-common.la \
	$(top_builddir)/pop/ir/libpop-ir.la

popdis_SOURCES = \
	main.cpp \
	options.cpp \
	options.hpp
