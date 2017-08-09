#ifdef HAVE_CONFIG_H
#include <Pop/Config.h>
#endif

#include <Pop/ByteCodeCompiler.hpp>
#include <Pop/AST.hpp>
#include <Pop/ConstantsTable.hpp>
#include <Pop/Instructions.hpp>
#include <Pop/InstructionVisitor.hpp>
#include <Pop/Serialization.hpp>
#include <Pop/TypeCode.hpp>
#include <Pop/Utils.hpp>
#include <Pop/Visitor.hpp>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

namespace Pop {

  struct ByteCodeData {
    const InstructionList &instructions;
    const ConstantsTable &constants;
    std::ostream &output;
    uint32_t constants_offset;
    uint32_t bytecode_offset;
    uint32_t total_size;

    ByteCodeData(const InstructionList &instructions,
                 const ConstantsTable &constants, std::ostream &output)
        : instructions(instructions), constants(constants), output(output),
          constants_offset(0), bytecode_offset(0), total_size(0) {
    }

    void serialize_pre(std::ostream &os) {
      static const std::string magic = POP_MAGIC_BYTES;
      for (size_t i = 0; i < magic.size(); i++)
        serialize8(os, magic[i]);
      serialize32(os, POP_BYTECODE_VERSION);
      for (auto i = 0; i < 4; i++) // 4x reserved
        serialize32(os, 0);
    }

    void serialize_constants(std::ostream &os) {
      serialize32(os, static_cast< uint32_t >(constants.size()));
      for (const auto &c : constants)
        c->serialize(os);
    }

    void serialize_instructions(std::ostream &os) {
      for (const auto &iptr : instructions)
        iptr->serialize(os);
    }

    void pass1() {
      std::stringstream ss;
      serialize_pre(ss);
      serialize32(ss, 0); // constants offset
      serialize32(ss, 0); // bytecodes offset
      constants_offset = ss.tellp();
      serialize_constants(ss);
      bytecode_offset = ss.tellp();
      serialize_instructions(ss);
      total_size = ss.str().size() + sizeof(uint32_t) /*crc32*/;
    }

    void pass2() {
      std::stringstream ss;
      serialize_pre(ss);
      serialize32(ss, constants_offset);
      serialize32(ss, bytecode_offset);
      assert(constants_offset == ss.tellp());
      serialize_constants(ss);
      assert(bytecode_offset == ss.tellp());
      serialize_instructions(ss);
      auto bc_str = ss.str();
      auto crc = crc32(0, bc_str);
      output.write(bc_str.data(), bc_str.size());
      serialize32(output, crc);
      assert(total_size == output.tellp());
    }
  };

  void compile_bytecode(const InstructionList &instructions,
                        ConstantsTable &const_tab, std::ostream &out) {
    ByteCodeData bcd(instructions, const_tab, out);
    bcd.pass1();
    bcd.pass2();
  }

  // namespace Pop
}
