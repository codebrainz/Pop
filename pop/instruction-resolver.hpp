#ifndef POP_INSTRUCTION_RESOLVER_HPP
#define POP_INSTRUCTION_RESOLVER_HPP

#include <pop/instruction-list.hpp>

namespace Pop {

  void resolve_instructions(InstructionList &instructions,
                            bool prune_labels = false);

  // namespace Pop
}

#endif // POP_INSTRUCTION_RESOLVER_HPP
