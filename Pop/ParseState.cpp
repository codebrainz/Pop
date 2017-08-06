#ifdef HAVE_CONFIG_H
#include <Pop/Config.h>
#endif

#include <Pop/ParseState.hpp>
#include <Pop/AST.hpp>
#include <Pop/Compiler.hpp>
#include <Pop/Grammar.hpp>
#include <Pop/Lexer.hpp>

namespace Pop {

  ParseState::ParseState(const char *file, std::istream &is, Compiler &cmp)
      : file(file), is(is), cmp(cmp), roots(nullptr), scanner(nullptr) {
    yylex_init(&scanner);
    yyset_extra(this, scanner);
    // yylex_init_extra(this, &scanner);
  }

  ParseState::~ParseState() {
    yylex_destroy(scanner);
    node_unref(roots);
  }

  // namespace Pop
}
