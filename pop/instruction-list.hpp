#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

#ifndef POP_INSTRUCTION_LIST_HPP
#define POP_INSTRUCTION_LIST_HPP

#include <memory>
#include <vector>

namespace Pop {

  struct Instruction;

  typedef std::unique_ptr< Instruction > InstructionPtr;
  typedef std::vector< InstructionPtr > InstructionList;

  // namespace Pop
}

#endif // POP_INSTRUCTION_LIST_HPP
