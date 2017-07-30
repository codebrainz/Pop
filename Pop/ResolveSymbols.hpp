#ifndef POP_RESOLVESYMBOLS_HPP
#define POP_RESOLVESYMBOLS_HPP

namespace Pop {

  class Logger;
  struct Node;

  void resolve_symbols(Node *root, Logger &log);

  // namespace Pop
}

#endif // POP_RESOLVESYMBOLS_HPP
