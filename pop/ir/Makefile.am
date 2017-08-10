AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_builddir) \
	-DPOP_LIB_COMPILATION_=1 \
	-DPOP_LIB_IR_COMPILATION_=1

lib_LTLIBRARIES = libpop-ir.la

NODEGEN_SOURCES = \
	ast.hpp \
	ast-visitor.cpp \
	ast-visitor.hpp \
	instructions.hpp \
	instruction-visitor.cpp \
	instruction-visitor.hpp \
	operators.cpp \
	operators.hpp

libpop_ir_la_SOURCES = \
	$(NODEGEN_SOURCES) \
	constant.cpp \
	constant.hpp \
	constants-table.cpp \
	constants-table.hpp \
	instruction-dumper.cpp \
	instruction-dumper.hpp \
	instruction-list.hpp \
	instruction-optimizer.cpp \
	instruction-optimizer.hpp \
	instruction-resolver.cpp \
	instruction-resolver.hpp \
	type-code.hpp

libpop_ir_la_LIBADD = $(top_builddir)/pop/common/libpop-common.la

NODEGEN_DATA_FILE = $(top_srcdir)/pop/data.xml
NODEGEN_SCRIPT = $(top_srcdir)/scripts/nodegen.py
NODEGEN_DEPS = $(NODEGEN_DATA_FILE) $(NODEGEN_SCRIPT)
NODEGEN = $(AM_V_GEN)$(PYTHON) $(NODEGEN_SCRIPT) -d $(NODEGEN_DATA_FILE)

EXTRA_DIST = \
	$(NODEGEN_DATA_FILE) \
	ast.hpp.in \
	ast-visitor.cpp.in \
	ast-visitor.hpp.in \
	instructions.hpp.in \
	instruction-visitor.cpp.in \
	instruction-visitor.hpp.in \
	operators.cpp.in \
	operators.hpp.in

popirincludedir = $(includedir)/pop/ir
popirinclude_HEADERS = \
	ast.hpp \
	ast-visitor.hpp \
	constant.hpp \
	constants-table.hpp \
	instruction-dumper.hpp \
	instruction-list.hpp \
	instruction-optimizer.hpp \
	instruction-resolver.hpp \
	instructions.hpp \
	instruction-visitor.hpp \
	operators.hpp \
	type-code.hpp

if MAINTAINER_MODE

BUILT_SOURCES = $(NODEGEN_SOURCES)

DISTCLEANFILES = $(BUILT_SOURCES)

#
# Generated C++ files
#

ast.hpp: $(srcdir)/ast.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/ast.hpp.in

ast-visitor.cpp: $(srcdir)/ast-visitor.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/ast-visitor.cpp.in

ast-visitor.hpp: $(srcdir)/ast-visitor.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/ast-visitor.hpp.in

instructions.hpp: $(srcdir)/instructions.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/instructions.hpp.in

instruction-visitor.cpp: $(srcdir)/instruction-visitor.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/instruction-visitor.cpp.in

instruction-visitor.hpp: $(srcdir)/instruction-visitor.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/instruction-visitor.hpp.in

operators.cpp: $(srcdir)/operators.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/operators.cpp.in

operators.hpp: $(srcdir)/operators.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/operators.hpp.in

# MAINTAINER_MODE
endif
