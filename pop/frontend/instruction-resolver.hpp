#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

#ifndef POP_INSTRUCTION_RESOLVER_HPP
#define POP_INSTRUCTION_RESOLVER_HPP

#include <pop/frontend/instruction-list.hpp>

namespace Pop {

  void resolve_instructions(InstructionList &instructions,
                            bool prune_labels = false);

  // namespace Pop
}

#endif // POP_INSTRUCTION_RESOLVER_HPP
