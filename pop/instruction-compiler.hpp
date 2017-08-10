#ifndef POP_INSTRUCTION_COMPILER_HPP
#define POP_INSTRUCTION_COMPILER_HPP

#include <pop/instruction-list.hpp>

namespace Pop {

  class ConstantsTable;
  struct Node;

  void compile_instructions(Node *root, ConstantsTable &const_tab,
                            InstructionList &list);

  // namespace Pop
}

#endif // POP_INSTRUCTION_COMPILER_HPP
