AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_builddir) \
	-DPOP_LIB_COMPILATION_=1 \
	-DPOP_LIB_BACKEND_COMPILATION_=1

lib_LTLIBRARIES = libpop-backend.la

CODEGEN_SOURCES = \
	bytecode-disassembler.cpp

libpop_backend_la_SOURCES = \
	$(CODEGEN_SOURCES) \
	bytecode-disassembler.hpp \
	bytecode-generator.cpp \
	bytecode-generator.hpp

libpop_backend_la_LIBADD = \
	$(top_builddir)/pop/common/libpop-common.la \
	$(top_builddir)/pop/ir/libpop-ir.la

CODEGEN_DATA_FILE = $(top_srcdir)/scripts/codegen-data.xml
CODEGEN_SCRIPT = $(top_srcdir)/scripts/codegen.py
CODEGEN_DEPS = $(CODEGEN_DATA_FILE) $(CODEGEN_SCRIPT)
CODEGEN = $(AM_V_GEN)$(PYTHON) $(CODEGEN_SCRIPT) -d $(CODEGEN_DATA_FILE)

EXTRA_DIST = \
	$(CODEGEN_DATA_FILE) \
	bytecode-disassembler.cpp.in

popcodegenincludedir = $(includedir)/pop/backend
popcodegeninclude_HEADERS = \
	bytecode-disassembler.hpp \
	bytecode-generator.hpp

if MAINTAINER_MODE

BUILT_SOURCES = $(CODEGEN_SOURCES)

DISTCLEANFILES = $(BUILT_SOURCES)

#
# Generated C++ files
#

bytecode-disassembler.cpp: $(srcdir)/bytecode-disassembler.cpp.in $(CODEGEN_DEPS)
	$(CODEGEN) -o $@ $(srcdir)/bytecode-disassembler.cpp.in

# MAINTAINER_MODE
endif
