#ifndef POP_INSTRUCTION_COMPILER_HPP
#define POP_INSTRUCTION_COMPILER_HPP

#include <Pop/Instructions.hpp>

namespace Pop {

  struct Node;

  void compile_instructions(Node *root, InstructionList &list);

  // namespace Pop
}

#endif // POP_INSTRUCTION_COMPILER_HPP
