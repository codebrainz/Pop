CXXFLAGS_ = $(CPPFLAGS) -I.. $(CXXFLAGS) -g -std=c++14 -Wall -Wextra -Werror -fmax-errors=2
LDFLAGS_ = $(LDFLAGS)

NODEGEN_SCRIPT = ../scripts/nodegen.py
DATAFILE = ../data.xml
NODEGEN = python3 $(NODEGEN_SCRIPT)
NODEGEN_DEPS = $(NODEGEN_SCRIPT) $(DATAFILE)

ifeq ($(V),1)
	vCXX     = $(CXX) -c -MMD
	vCXXLD   = $(CXX)
	vNODEGEN = $(NODEGEN)
	vLEX     = $(LEX)
	vYACC    = $(YACC)
else
	vCXX     = @echo "  [CXX]   $@" && $(CXX) -c -MMD
	vCXXLD   = @echo "  [CXXLD] $@" && $(CXX)
	vNODEGEN = @echo "  [GEN]   $@" && $(NODEGEN)
	vLEX     = @echo "  [LEX]   $@" && $(LEX)
	vYACC    = @echo "  [YACC]  $@" && $(YACC)
endif

GEN_SOURCES = \
	AST.cpp \
	DOT.cpp \
	Grammar.cpp \
	Lexer.cpp \
	Operators.cpp \
	Transformer.cpp \
	Visitor.cpp

GEN_HEADERS = $(GEN_SOURCES:.cpp=.hpp)
GEN_FILES = $(GEN_SOURCES) $(GEN_HEADERS)

SOURCES = \
	Compiler.cpp \
	Logger.cpp \
	Main.cpp \
	ParseState.cpp \
	Utils.cpp \
	$(GEN_SOURCES)

OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = $(SOURCES:.cpp=.d)

all: pop

clean:
	$(RM) *.o pop $(GEN_SOURCES)

deps-clean: clean
	$(RM) *.d

pop: $(GEN_FILES) $(OBJECTS)
	$(vCXXLD) $(strip $(CXXFLAGS_) -o $@ $(OBJECTS) $(LDFLAGS_))

.cpp.o:
	$(vCXX) $(strip $(CXXFLAGS_) -o $@ $<)

# squelch a warning in flex output
Lexer.o: Lexer.cpp
	$(vCXX) $(strip $(CXXFLAGS_) -Wno-sign-compare -o $@ Lexer.cpp)

Lexer.cpp: Grammar.hpp Lexer.l
	$(vLEX) --header-file=Lexer.hpp -o $@ Lexer.l

Grammar.cpp: Grammar.y
	$(vYACC) --verbose --defines=Grammar.hpp -o $@ Grammar.y

Lexer.hpp: Lexer.cpp
Grammar.hpp: Grammar.cpp
ParseState.cpp: Lexer.hpp
ParseState.cpp: Grammar.hpp
Compiler.cpp: Grammar.hpp

AST.cpp: AST.cpp.in AST.hpp $(NODEGEN_DEPS)
	$(vNODEGEN) -d $(DATAFILE) -o $@ AST.cpp.in

AST.hpp: AST.hpp.in $(NODEGEN_DEPS)
	$(vNODEGEN) -d $(DATAFILE) -o $@ AST.hpp.in

DOT.cpp: DOT.cpp.in $(NODEGEN_DEPS)
	$(vNODEGEN) -d $(DATAFILE) -o $@ DOT.cpp.in

Operators.cpp: Operators.cpp.in Operators.hpp $(NODEGEN_DEPS)
	$(vNODEGEN) -d $(DATAFILE) -o $@ Operators.cpp.in

Operators.hpp: Operators.hpp.in $(NODEGEN_DEPS)
	$(vNODEGEN) -d $(DATAFILE) -o $@ Operators.hpp.in

Transformer.cpp: Transformer.cpp.in Transformer.hpp $(NODEGEN_DEPS)
	$(vNODEGEN) -d $(DATAFILE) -o $@ Transformer.cpp.in

Transformer.hpp: Transformer.hpp.in $(NODEGEN_DEPS)
	$(vNODEGEN) -d $(DATAFILE) -o $@ Transformer.hpp.in

Visitor.cpp: Visitor.cpp.in Visitor.hpp $(NODEGEN_DEPS)
	$(vNODEGEN) -d $(DATAFILE) -o $@ Visitor.cpp.in

Visitor.hpp: Visitor.hpp.in $(NODEGEN_DEPS)
	$(vNODEGEN) -d $(DATAFILE) -o $@ Visitor.hpp.in

-include $(DEPENDS)

.PHONY: all clean
