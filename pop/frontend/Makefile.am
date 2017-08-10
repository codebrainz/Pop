AM_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_builddir) \
	-DPOP_LIB_COMPILATION_=1 \
	-DPOP_LIB_FRONTEND_COMPILATION_=1

lib_LTLIBRARIES = libpop-frontend.la

NODEGEN_SOURCES = \
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
	$(NODEGEN_SOURCES) \
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

NODEGEN_DATA_FILE = $(top_srcdir)/pop/data.xml
NODEGEN_SCRIPT = $(top_srcdir)/scripts/nodegen.py
NODEGEN_DEPS = $(NODEGEN_DATA_FILE) $(NODEGEN_SCRIPT)
NODEGEN = $(AM_V_GEN)$(PYTHON) $(NODEGEN_SCRIPT) -d $(NODEGEN_DATA_FILE)

EXTRA_DIST = \
	$(NODEGEN_DATA_FILE) \
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

define-symbols.cpp: $(srcdir)/define-symbols.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/define-symbols.cpp.in

dot.cpp: $(srcdir)/dot.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/dot.cpp.in

link-parents.cpp: $(srcdir)/link-parents.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/link-parents.cpp.in

location-patcher.cpp: $(srcdir)/location-patcher.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/location-patcher.cpp.in

resolve-symbols.cpp: $(srcdir)/resolve-symbols.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/resolve-symbols.cpp.in

validate.cpp: $(srcdir)/validate.cpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -o $@ $(srcdir)/validate.cpp.in

# MAINTAINER_MODE
endif
