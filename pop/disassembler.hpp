#ifndef POP_DISASSEMBLER_HPP
#define POP_DISASSEMBLER_HPP

#include <istream>
#include <ostream>
#include <string>

namespace Pop {

  bool disassemble(std::istream &is, std::ostream &os, std::ostream &err);
  bool disassemble(const std::string &fn, std::istream &is, std::ostream &os,
                   std::ostream &err);

  // namespace Pop
}

#endif // POP_DISASSEMBLER_HPP
