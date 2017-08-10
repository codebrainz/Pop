#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

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
