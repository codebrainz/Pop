#ifndef POP_BYTECODE_COMPILER_HPP
#define POP_BYTECODE_COMPILER_HPP

#include <Pop/InstructionList.hpp>
#include <ostream>

namespace Pop {

  class ConstantsTable;

  void compile_bytecode(const InstructionList &instructions,
                        const ConstantsTable &const_tab, std::ostream &out);

  // namespace Pop
}

#endif // POP_BYTECODE_COMPILER_HPP
