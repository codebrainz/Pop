#ifndef POP_LIB_COMPILATION_
#error \
    "Inclusion of private header, use '<pop/pop.hpp>' instead to include all public headers."
#endif

#ifndef POP_PARSE_STATE_HPP
#define POP_PARSE_STATE_HPP

#include <istream>

namespace Pop {

  class Logger;
  struct Node;

  struct ParseState {
    const char *file;
    std::istream &is;
    Logger &log;
    Node *roots;
    void *scanner;
    ParseState(const char *file, std::istream &is, Logger &log);
    ~ParseState();
  };

  // namespace Pop
}

#endif // POP_PARSE_STATE_HPP
