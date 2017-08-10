#ifndef POP_PARSE_STATE_HPP
#define POP_PARSE_STATE_HPP

#include <istream>

namespace Pop {

  class Compiler;
  struct Node;

  struct ParseState {
    const char *file;
    std::istream &is;
    Compiler &cmp;
    Node *roots;
    void *scanner;
    ParseState(const char *file, std::istream &is, Compiler &cmp);
    ~ParseState();
  };

  // namespace Pop
}

#endif // POP_PARSE_STATE_HPP
