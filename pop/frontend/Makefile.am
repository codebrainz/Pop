AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_builddir) \
	-DPOP_LIB_COMPILATION_=1 \
	-DPOP_LIB_FRONTEND_COMPILATION_=1

lib_LTLIBRARIES = libpop-frontend.la

CODEGEN_SOURCES = \
	define-symbols.cpp \
	dot.cpp \
	grammar.cpp \
	grammar.hpp \
	lexer.cpp \
	lexer.hpp \
	link-parents.cpp \
	location-patcher.cpp \
	resolve-symbols.cpp \
	validate.cpp

libpop_frontend_la_SOURCES = \
	$(CODEGEN_SOURCES) \
	compiler.cpp \
	compiler.hpp \
	define-symbols.hpp \
	dot.hpp \
	instruction-compiler.cpp \
	instruction-compiler.hpp \
	link-parents.hpp \
	location-patcher.hpp \
	parse-state.cpp \
	parse-state.hpp \
	resolve-symbols.hpp \
	symbol-table.cpp \
	symbol-table.hpp \
	validate.hpp

libpop_frontend_la_LIBADD = \
	$(top_builddir)/pop/common/libpop-common.la \
	$(top_builddir)/pop/ir/libpop-ir.la

CODEGEN_DATA_FILE = $(top_srcdir)/scripts/codegen-data.xml
CODEGEN_SCRIPT = $(top_srcdir)/scripts/codegen.py
CODEGEN_DEPS = $(CODEGEN_DATA_FILE) $(CODEGEN_SCRIPT)
CODEGEN = $(AM_V_GEN)$(PYTHON) $(CODEGEN_SCRIPT) -d $(CODEGEN_DATA_FILE)

EXTRA_DIST = \
	$(CODEGEN_DATA_FILE) \
	define-symbols.cpp.in \
	dot.cpp.in \
	grammar.y \
	lexer.l \
	link-parents.cpp.in \
	location-patcher.cpp.in \
	resolve-symbols.cpp.in \
	validate.cpp.in

popfrontendincludedir = $(includedir)/pop/frontend
popfrontendinclude_HEADERS = \
	compiler.hpp \
	define-symbols.hpp \
	dot.hpp \
	instruction-compiler.hpp \
	link-parents.hpp \
	location-patcher.hpp \
	resolve-symbols.hpp \
	symbol-table.hpp \
	validate.hpp

if MAINTAINER_MODE

BUILT_SOURCES = $(CODEGEN_SOURCES)

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

define-symbols.cpp: $(srcdir)/define-symbols.cpp.in $(CODEGEN_DEPS)
	$(CODEGEN) -o $@ $(srcdir)/define-symbols.cpp.in

dot.cpp: $(srcdir)/dot.cpp.in $(CODEGEN_DEPS)
	$(CODEGEN) -o $@ $(srcdir)/dot.cpp.in

link-parents.cpp: $(srcdir)/link-parents.cpp.in $(CODEGEN_DEPS)
	$(CODEGEN) -o $@ $(srcdir)/link-parents.cpp.in

location-patcher.cpp: $(srcdir)/location-patcher.cpp.in $(CODEGEN_DEPS)
	$(CODEGEN) -o $@ $(srcdir)/location-patcher.cpp.in

resolve-symbols.cpp: $(srcdir)/resolve-symbols.cpp.in $(CODEGEN_DEPS)
	$(CODEGEN) -o $@ $(srcdir)/resolve-symbols.cpp.in

validate.cpp: $(srcdir)/validate.cpp.in $(CODEGEN_DEPS)
	$(CODEGEN) -o $@ $(srcdir)/validate.cpp.in

# MAINTAINER_MODE
endif
