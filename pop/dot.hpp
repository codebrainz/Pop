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
