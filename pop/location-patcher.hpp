#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

#ifndef POP_LOCATIONPATCHER_HPP
#define POP_LOCATIONPATCHER_HPP

namespace Pop {

  class Logger;
  struct Node;

  void patch_locations(Node *root, Logger &log, bool verify = false);

  // namespace Pop
}

#endif // POP_LOCATIONPATCHER_HPP
