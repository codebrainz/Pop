#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

#ifndef POP_LINKPARENTS_HPP
#define POP_LINKPARENTS_HPP

namespace Pop {

  class Logger;
  struct Node;

  void link_parents(Node *root, Logger &log, bool verify = false);

  // namespace Pop
}

#endif // POP_LINKPARENTS_HPP
