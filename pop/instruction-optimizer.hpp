#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

#ifndef POP_INSTRUCTION_OPTIMIZER_HPP
#define POP_INSTRUCTION_OPTIMIZER_HPP

#include <pop/instruction-list.hpp>

namespace Pop {

  void optimize_instructions(InstructionList &instructions);

  // namespace Pop
}

#endif // POP_INSTRUCTION_OPTIMIZER_HPP
