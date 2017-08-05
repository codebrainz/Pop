#ifndef POP_INSTRUCTION_DUMPER_HPP
#define POP_INSTRUCTION_DUMPER_HPP

#include <Pop/InstructionList.hpp>
#include <ostream>

namespace Pop {

  class ConstantsTable;

  void dump_instructions(const InstructionList &instructions,
                         ConstantsTable &const_tab, std::ostream &os);

  // namespace Pop
}

#endif // POP_INSTRUCTION_DUMPER_HPP
