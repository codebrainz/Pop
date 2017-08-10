#ifdef HAVE_CONFIG_H
#include <pop/config.h>
#endif

#include <pop/parse-state.hpp>
#include <pop/ast.hpp>
#include <pop/compiler.hpp>
#include <pop/grammar.hpp>
#include <pop/lexer.hpp>

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
