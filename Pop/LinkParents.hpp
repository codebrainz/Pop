#ifndef POP_LINKPARENTS_HPP
#define POP_LINKPARENTS_HPP

namespace Pop {

  class Logger;
  struct Node;

  void link_parents(Node *root, Logger &log, bool verify = false);

  // namespace Pop
}

#endif // POP_LINKPARENTS_HPP
