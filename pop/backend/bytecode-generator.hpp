#ifndef POP_BYTECODE_GENERATOR_HPP
#define POP_BYTECODE_GENERATOR_HPP

#include <pop/ir/constants-table.hpp>
#include <pop/ir/instruction-list.hpp>
#include <ostream>

namespace Pop {

  void generate_bytecode(const ConstantsTable &constants,
                         const InstructionList &instructions,
                         std::ostream &output);

  // namespace Pop
}

#endif // POP_BYTECODE_GENERATOR_HPP
