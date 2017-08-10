#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

#ifndef POP_DOT_HPP
#define POP_DOT_HPP

#include <ostream>
#include <string>

namespace Pop {

  struct Node;

  void generate_dot(Node *root, std::ostream &os,
                    const std::string &indent_token = "  ");

  // namespace Pop
}

#endif // POP_DOT_HPP
