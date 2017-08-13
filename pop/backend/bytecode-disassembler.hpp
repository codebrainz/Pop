#ifndef POP_BYTECODE_DISASSEMBLER_HPP
#define POP_BYTECODE_DISASSEMBLER_HPP

#include <pop/ir/constants-table.hpp>
#include <pop/ir/instruction-list.hpp>
#include <istream>

namespace Pop {

  class Logger;

  void disassemble_bytecode(Logger &log, std::istream &input,
                            const std::string &fn, ConstantsTable &constants,
                            InstructionList &instructions);

  // namespace Pop
}

#endif // POP_BYTECODE_DISASSEMBLER_HPP
