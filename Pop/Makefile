CXXFLAGS_ = $(CPPFLAGS) -I.. $(CXXFLAGS) -g -std=c++14 -Wall -Wextra -Werror -fmax-errors=2
LDFLAGS_ = $(LDFLAGS)

NODEGEN_SCRIPT = ../scripts/nodegen.py
DATAFILE = ../data.xml
NODEGEN = python3 $(NODEGEN_SCRIPT)
NODEGEN_DEPS = $(NODEGEN_SCRIPT) $(DATAFILE)

GEN_SOURCES = \
	AST.cpp \
	Operators.cpp \
	Transformer.cpp \
	Visitor.cpp

GEN_HEADERS = $(GEN_SOURCES:.cpp=.hpp)
GEN_FILES = $(GEN_SOURCES) $(GEN_HEADERS)

SOURCES = Main.cpp $(GEN_SOURCES)
OBJECTS = $(SOURCES:.cpp=.o)
DEPENDS = $(SOURCES:.cpp=.d)

all: pop

clean:
	$(RM) *.o pop $(GEN_SOURCES)

deps-clean: clean
	$(RM) *.d

pop: $(GEN_FILES) $(OBJECTS)
	$(CXX) $(strip $(CXXFLAGS_) -o $@ $(OBJECTS) $(LDFLAGS_))

.cpp.o:
	$(CXX) $(strip $(CXXFLAGS_) -c -MMD -o $@ $<)

AST.cpp: AST.cpp.in AST.hpp $(NODEGEN_DEPS)
	$(NODEGEN) -d $(DATAFILE) -o $@ AST.cpp.in

AST.hpp: AST.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -d $(DATAFILE) -o $@ AST.hpp.in

Operators.cpp: Operators.cpp.in Operators.hpp $(NODEGEN_DEPS)
	$(NODEGEN) -d $(DATAFILE) -o $@ Operators.cpp.in

Operators.hpp: Operators.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -d $(DATAFILE) -o $@ Operators.hpp.in

Transformer.cpp: Transformer.cpp.in Transformer.hpp $(NODEGEN_DEPS)
	$(NODEGEN) -d $(DATAFILE) -o $@ Transformer.cpp.in

Transformer.hpp: Transformer.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -d $(DATAFILE) -o $@ Transformer.hpp.in

Visitor.cpp: Visitor.cpp.in Visitor.hpp $(NODEGEN_DEPS)
	$(NODEGEN) -d $(DATAFILE) -o $@ Visitor.cpp.in

Visitor.hpp: Visitor.hpp.in $(NODEGEN_DEPS)
	$(NODEGEN) -d $(DATAFILE) -o $@ Visitor.hpp.in

-include $(DEPENDS)

.PHONY: all clean
