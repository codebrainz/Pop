#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

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
