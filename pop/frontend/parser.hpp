#ifndef POP_PARSER_HPP
#define POP_PARSER_HPP

#include <fstream>
#include <istream>
#include <string>

namespace Pop {

  class Logger;
  struct Node;
  struct Program;

  Node *parse_file(Program *program, Logger &log, std::istream &is,
                   const char *fn = "<stream>");

  inline Node *parse_file(Program *program, Logger &log, const char *fn) {
    if (!fn)
      return nullptr;
    std::ifstream f(fn);
    return parse_file(program, log, f, fn);
  }

  // namespace Pop
}

#endif // POP_PARSER_HPP
