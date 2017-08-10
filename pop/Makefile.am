AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_builddir) \
	-DPOP_LIB_COMPILATION_=1

noinst_LIBRARIES = libpop.a

NODEGEN_SOURCES = \
	ast.hpp \
	define-symbols.cpp \
	dot.cpp \
	grammar.cpp \
	grammar.hpp \
	instructions.hpp \
	instruction-visitor.cpp \
	instruction-visitor.hpp \
	lexer.cpp \
	lexer.hpp \
	link-parents.cpp \
	location-patcher.cpp \
	operators.cpp \
	operators.hpp \
	resolve-symbols.cpp \
	validate.cpp \
	visitor.cpp \
	visitor.hpp

libpop_a_SOURCES = \
	$(NODEGEN_SOURCES) \
	compiler.cpp \
	compiler.hpp \
	constant.cpp \
	constant.hpp \
	constants-table.cpp \
	constants-table.hpp \
	crc32.cpp \
	crc32.hpp \
	define-symbols.hpp \
	dot.hpp \
	formatter.hpp \
	instruction-compiler.cpp \
	instruction-compiler.hpp \
	instruction-dumper.cpp \
	instruction-dumper.hpp \
	instruction-list.hpp \
	instruction-optimizer.cpp \
	instruction-optimizer.hpp \
	instruction-resolver.cpp \
	instruction-resolver.hpp \
	link-parents.hpp \
	location-patcher.hpp \
	logger.cpp \
	logger.hpp \
	parse-state.cpp \
	parse-state.hpp \
	pop.hpp \
	resolve-symbols.hpp \
	symbol-table.cpp \
	symbol-table.hpp \
	type-code.hpp \
	type-info.hpp \
	utils.cpp \
	utils.hpp \
	validate.hpp

NODEGEN_DATA_FILE = $(srcdir)/data.xml
NODEGEN_SCRIPT = $(top_srcdir)/scripts/nodegen.py
NODEGEN_DEPS = $(NODEGEN_DATA_FILE) $(NODEGEN_SCRIPT)
NODEGEN = $(AM_V_GEN)$(PYTHON) $(NODEGEN_SCRIPT) -d $(NODEGEN_DATA_FILE)

EXTRA_DIST = \
	$(NODEGEN_DATA_FILE) \
	ast.hpp.in \
	define-symbols.cpp.in \
	dot.cpp.in \
	grammar.y \
	instructions.hpp.in \
	instruction-visitor.cpp.in \
	instruction-visitor.hpp.in \
	lexer.l \
	link-parents.cpp.in \
	location-patcher.cpp.in \
	operators.cpp.in \
	operators.hpp.in \
	resolve-symbols.cpp.in \
	validate.cpp.in \
	visitor.cpp.in \
	visitor.hpp.in

if MAINTAINER_MODE

BUILT_SOURCES = $(NODEGEN_SOURCES)

DISTCLEANFILES = $(BUILT_SOURCES)

#
# Lex/YACC grammars
#

lexer.cpp: $(srcdir)/lexer.l
	$(AM_V_GEN)$(FLEX) --header-file=lexer.hpp -o $@ $(srcdir)/lexer.l

lexer.hpp: lexer.cpp

grammar.cpp: $(srcdir)/grammar.y
	$(AM_V_GEN)$(BISON) --defines=grammar.hpp -o $@ $(srcdir)/grammar.y

grammar.hpp: grammar.cpp

#
# Generated C++ files
#

ast.hpp: $(srcdir)/ast.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/ast.hpp.in

define-symbols.cpp: $(srcdir)/define-symbols.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/define-symbols.cpp.in

dot.cpp: $(srcdir)/dot.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/dot.cpp.in

instructions.hpp: $(srcdir)/instructions.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/instructions.hpp.in

instruction-visitor.cpp: $(srcdir)/instruction-visitor.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/instruction-visitor.cpp.in

instruction-visitor.hpp: $(srcdir)/instruction-visitor.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/instruction-visitor.hpp.in

link-parents.cpp: $(srcdir)/link-parents.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/link-parents.cpp.in

location-patcher.cpp: $(srcdir)/location-patcher.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/location-patcher.cpp.in

operators.cpp: $(srcdir)/operators.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/operators.cpp.in

operators.hpp: $(srcdir)/operators.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/operators.hpp.in

resolve-symbols.cpp: $(srcdir)/resolve-symbols.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/resolve-symbols.cpp.in

validate.cpp: $(srcdir)/validate.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/validate.cpp.in

visitor.cpp: $(srcdir)/visitor.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/visitor.cpp.in

visitor.hpp: $(srcdir)/visitor.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/visitor.hpp.in

# MAINTAINER_MODE
endif
