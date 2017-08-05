#ifndef POP_INSTRUCTION_RESOLVER_HPP
#define POP_INSTRUCTION_RESOLVER_HPP

#include <Pop/InstructionList.hpp>

namespace Pop {

  void resolve_instructions(InstructionList &instructions,
                            bool prune_labels = false);

  // namespace Pop
}

#endif // POP_INSTRUCTION_RESOLVER_HPP
