#ifndef POP_LOCATIONPATCHER_HPP
#define POP_LOCATIONPATCHER_HPP

namespace Pop {

  class Logger;
  struct Node;

  void patch_locations(Node *root, Logger &log, bool verify = false);

  // namespace Pop
}

#endif // POP_LOCATIONPATCHER_HPP
