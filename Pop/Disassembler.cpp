#ifdef HAVE_CONFIG_H
#include <Pop/Config.h>
#endif

#include <Pop/Disassembler.hpp>
#include <Pop/Constant.hpp>
#include <Pop/InstructionList.hpp>
#include <Pop/Instructions.hpp>
#include <Pop/InstructionVisitor.hpp>
#include <Pop/Serialization.hpp>
#include <Pop/TypeCode.hpp>
#include <Pop/Utils.hpp>
#include <cassert>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

namespace Pop {

  static bool check_magic_bytes(std::istream &is) {
    static const std::string magic = POP_MAGIC_BYTES;
    std::string test_magic;
    test_magic.reserve(magic.size());
    for (size_t i = 0; i < magic.size(); i++)
      test_magic += static_cast< char >(deserialize8(is));
    return (magic == test_magic);
  }

  struct DisDumpVisitor final : public InstructionVisitor {
    std::ostream &os;
    DisDumpVisitor(std::ostream &os) : os(os) {
    }
    std::string fmt_hex(int v) const {
      char buf[16] = { 0 };
      std::snprintf(buf, 15, "%XH", v);
      return buf;
    }
    std::string fmt_offset(Instruction &i) const {
      return fmt_hex(i.offset);
    }
    void visit_default(Instruction &i) final {
      os << fmt_offset(i) << '\t' << i.mnemonic() << '\n';
    }
    void visit(PushConstInstruction &i) final {
      os << fmt_offset(i) << '\t' << i.mnemonic() << ' ' << i.const_id << '\n';
    }
    template < class T >
    void visit_target_ref(T &i) const {
      os << fmt_offset(i) << '\t' << i.mnemonic() << ' ' << fmt_hex(i.target)
         << '\n';
    }
    void visit(JumpInstruction &i) final {
      visit_target_ref(i);
    }
    void visit(JumpIfTrueInstruction &i) final {
      visit_target_ref(i);
    }
    void visit(JumpIfFalseInstruction &i) final {
      visit_target_ref(i);
    }
    void visit(ClosureInstruction &i) final {
      visit_target_ref(i);
    }
    void visit(LabelInstruction &) final {
      assert(false);
    }
  };

  bool disassemble(std::istream &is, std::ostream &os, std::ostream &err) {
    return disassemble("<stream>", is, os, err);
  }

  bool disassemble(const std::string &fn, std::istream &is, std::ostream &os,
                   std::ostream &err) {
    if (!check_magic_bytes(is)) {
      err << fn << ": error: invalid magic bytes" << std::endl;
      return false;
    }

    size_t bytecode_offset = deserialize32(is);
    size_t num_constants = deserialize32(is);

    std::vector< Constant > constants;
    for (size_t i = 0; i < num_constants; i++) {
      switch (auto tc = static_cast< TC >(deserialize8(is))) {
        case TC::NIL:
          constants.emplace_back(Constant::new_nil());
          break;
        case TC::BLN:
          constants.emplace_back(Constant::new_bool(deserialize8(is)));
          break;
        case TC::INT:
          constants.emplace_back(Constant::new_int(deserialize64(is)));
          break;
        case TC::FLT:
          constants.emplace_back(
              Constant::new_float(deserialize_raw< long double >(is)));
          break;
        case TC::STR:
          constants.emplace_back(Constant::new_string(deserialize_str(is)));
          break;
        case TC::SYM:
          constants.emplace_back(Constant::new_symbol(deserialize_str(is)));
          break;
      }
    }

    auto crc32_in = deserialize32(is);

    if (is.tellg() != bytecode_offset) {
      err << fn << ": error: constants table is corrupted\n"
          << "current offset after constants table is '" << is.tellg()
          << "' but was supposed to be '" << bytecode_offset << "'"
          << std::endl;
      return false;
    }

    std::stringstream bytecode;
    std::copy(std::istreambuf_iterator< char >(is),
              std::istreambuf_iterator< char >(),
              std::ostreambuf_iterator< char >(bytecode));

    auto bc_str = bytecode.str();
    auto crc32_calc = crc32(0, bc_str);

#if 0
    if (crc32_in != crc32_calc) {
      err << fn << ": error: CRC32 failed, bytecode is corrupted" << std::endl;
      return false;
    }
#endif

    InstructionList instructions;
    while (!bytecode.eof()) {
      auto inst = Instruction::deserialize(bytecode);
      inst->offset -= bytecode_offset;
      instructions.push_back(std::move(inst));
    }

    DisDumpVisitor visitor(os);
    for (auto &inst : instructions)
      inst->accept(visitor);

    return true;
  }

  // namespace Pop
}
