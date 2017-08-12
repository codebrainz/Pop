#include <pop/frontend/parser.hpp>
#include <pop/frontend/grammar.hpp>
#include <pop/frontend/parse-state.hpp>
#include <pop/ir/ast.hpp>

namespace Pop {

  Node *parse_file(Program *program, Logger &log, std::istream &is,
                   const char *fn) {
    ParseState state(fn, is, log);
    yyparse(&state);
    auto mod = new Module(fn, 0, 0, state.roots);
    state.roots = nullptr;
    dynamic_cast< NodeList * >(program->modules)->append_take(mod);
    return mod;
  }

  // namepace Pop
}
