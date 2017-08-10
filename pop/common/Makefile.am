AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_builddir) \
	-DPOP_LIB_COMPILATION_=1 \
	-DPOP_LIB_COMMON_COMPILATION_=1

lib_LTLIBRARIES = libpop-common.la

libpop_common_la_SOURCES = \
	crc32.cpp \
	crc32.hpp \
	formatter.hpp \
	logger.cpp \
	logger.hpp \
	utils.cpp \
	utils.hpp

popcommonincludedir = $(includedir)/pop/common
popcommoninclude_HEADERS = \
	crc32.hpp \
	formatter.hpp \
	logger.hpp \
	utils.hpp
