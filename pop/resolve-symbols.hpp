#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

#ifndef POP_RESOLVESYMBOLS_HPP
#define POP_RESOLVESYMBOLS_HPP

namespace Pop {

  class Logger;
  struct Node;

  void resolve_symbols(Node *root, Logger &log);

  // namespace Pop
}

#endif // POP_RESOLVESYMBOLS_HPP
