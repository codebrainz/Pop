AM_CPPFLAGS = -I$(top_srcdir) -I$(top_builddir)

noinst_LIBRARIES = libpop.a

NODEGEN_SOURCES = \
	AST.cpp \
	AST.hpp \
	DefineSymbols.cpp \
	DOT.cpp \
	Grammar.cpp \
	Grammar.hpp \
	Instructions.hpp \
	InstructionVisitor.cpp \
	InstructionVisitor.hpp \
	Lexer.cpp \
	Lexer.hpp \
	LinkParents.cpp \
	LocationPatcher.cpp \
	Operators.cpp \
	Operators.hpp \
	ResolveSymbols.cpp \
	Validate.cpp \
	Visitor.cpp \
	Visitor.hpp

libpop_a_SOURCES = \
	$(NODEGEN_SOURCES) \
	ByteCodeCompiler.cpp \
	ByteCodeCompiler.hpp \
	Compiler.cpp \
	Compiler.hpp \
	Constant.cpp \
	Constant.hpp \
	ConstantsTable.cpp \
	ConstantsTable.hpp \
	DefineSymbols.hpp \
	Disassembler.cpp \
	Disassembler.hpp \
	DOT.hpp \
	Formatter.hpp \
	InstructionCompiler.cpp \
	InstructionCompiler.hpp \
	InstructionDumper.cpp \
	InstructionDumper.hpp \
	InstructionList.hpp \
	InstructionOptimizer.cpp \
	InstructionOptimizer.hpp \
	InstructionResolver.cpp \
	InstructionResolver.hpp \
	Instructions.cpp \
	LinkParents.hpp \
	LocationPatcher.hpp \
	Logger.cpp \
	Logger.hpp \
	OptionParser.cpp \
	OptionParser.hpp \
	ParseState.cpp \
	ParseState.hpp \
	Pop.hpp \
	ResolveSymbols.hpp \
	Serialization.hpp \
	SymbolTable.cpp \
	SymbolTable.hpp \
	TypeCode.hpp \
	TypeInfo.hpp \
	Utils.cpp \
	Utils.hpp \
	Validate.hpp

NODEGEN_DATA_FILE = $(srcdir)/data.xml
NODEGEN_SCRIPT = $(top_srcdir)/scripts/nodegen.py
NODEGEN_DEPS = $(NODEGEN_DATA_FILE) $(NODEGEN_SCRIPT)
NODEGEN = $(AM_V_GEN)$(PYTHON) $(NODEGEN_SCRIPT) -d $(NODEGEN_DATA_FILE)

EXTRA_DIST = \
	$(NODEGEN_DATA_FILE) \
	AST.cpp.in \
	AST.hpp.in \
	DefineSymbols.cpp.in \
	DOT.cpp.in \
	Grammar.y \
	Instructions.hpp.in \
	InstructionVisitor.cpp.in \
	InstructionVisitor.hpp.in \
	Lexer.l \
	LinkParents.cpp.in \
	LocationPatcher.cpp.in \
	Operators.cpp.in \
	Operators.hpp.in \
	ResolveSymbols.cpp.in \
	Validate.cpp.in \
	Visitor.cpp.in \
	Visitor.hpp.in

if MAINTAINER_MODE

BUILT_SOURCES = $(NODEGEN_SOURCES)

DISTCLEANFILES = $(BUILT_SOURCES)

#
# Lex/YACC grammars
#

Lexer.cpp: $(srcdir)/Lexer.l
	$(AM_V_GEN)$(FLEX) --header-file=Lexer.hpp -o $@ $(srcdir)/Lexer.l

Lexer.hpp: Lexer.cpp

Grammar.cpp: $(srcdir)/Grammar.y
	$(AM_V_GEN)$(BISON) --defines=Grammar.hpp -o $@ $(srcdir)/Grammar.y

Grammar.hpp: Grammar.cpp

#
# Generated C++ files
#

AST.cpp: $(srcdir)/AST.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/AST.cpp.in

AST.hpp: $(srcdir)/AST.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/AST.hpp.in

DefineSymbols.cpp: $(srcdir)/DefineSymbols.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/DefineSymbols.cpp.in

DOT.cpp: $(srcdir)/DOT.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/DOT.cpp.in

Instructions.hpp: $(srcdir)/Instructions.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/Instructions.hpp.in

InstructionVisitor.cpp: $(srcdir)/InstructionVisitor.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/InstructionVisitor.cpp.in

InstructionVisitor.hpp: $(srcdir)/InstructionVisitor.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/InstructionVisitor.hpp.in

LinkParents.cpp: $(srcdir)/LinkParents.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/LinkParents.cpp.in

LocationPatcher.cpp: $(srcdir)/LocationPatcher.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/LocationPatcher.cpp.in

Operators.cpp: $(srcdir)/Operators.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/Operators.cpp.in

Operators.hpp: $(srcdir)/Operators.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/Operators.hpp.in

ResolveSymbols.cpp: $(srcdir)/ResolveSymbols.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/ResolveSymbols.cpp.in

Validate.cpp: $(srcdir)/Validate.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/Validate.cpp.in

Visitor.cpp: $(srcdir)/Visitor.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/Visitor.cpp.in

Visitor.hpp: $(srcdir)/Visitor.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/Visitor.hpp.in

# MAINTAINER_MODE
endif
