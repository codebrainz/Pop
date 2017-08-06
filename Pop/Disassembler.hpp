#ifndef POP_DISASSEMBLER_HPP
#define POP_DISASSEMBLER_HPP

#include <istream>
#include <ostream>

namespace Pop {

  bool disassemble(std::istream &is, std::ostream &os, std::ostream &err);

  // namespace Pop
}

#endif // POP_DISASSEMBLER_HPP
