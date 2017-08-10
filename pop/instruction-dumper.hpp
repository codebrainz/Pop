#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

#ifndef POP_INSTRUCTION_DUMPER_HPP
#define POP_INSTRUCTION_DUMPER_HPP

#include <pop/instruction-list.hpp>
#include <ostream>

namespace Pop {

  class ConstantsTable;

  void dump_instructions(const InstructionList &instructions,
                         ConstantsTable &const_tab, std::ostream &os);

  // namespace Pop
}

#endif // POP_INSTRUCTION_DUMPER_HPP
