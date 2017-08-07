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
#include <sstream>

namespace Pop {

  static void serialize_magic(std::ostream &os) {
    static const std::string magic = POP_MAGIC_BYTES;
    for (auto ch : magic)
      serialize8(os, ch);
  }

  static void serialize_constants(std::ostream &os, ConstantsTable &const_tab) {
    serialize32(os, static_cast< std::uint32_t >(const_tab.size()));
    for (const auto &c : const_tab)
      c->serialize(os);
  }

  static void serialize_header(std::ostream &os, ConstantsTable &const_tab) {
    std::stringstream ss_magic;
    serialize_magic(ss_magic);
    auto str_magic = ss_magic.str();

    std::stringstream ss_const;
    serialize_constants(ss_const, const_tab);
    auto str_const = ss_const.str();

    std::uint32_t bc_offset =
        str_magic.size() + str_const.size() + (2 * sizeof(std::uint32_t));

    os.write(str_magic.data(), str_magic.size());
    serialize32(os, bc_offset);
    os.write(str_const.data(), str_const.size());
  }

  static void serialize_instructions(std::ostream &os,
                                     const InstructionList &instructions) {
    std::stringstream ss;
    for (auto &inst : instructions)
      inst->serialize(ss);
    auto inst_str = ss.str();
    serialize32(os, crc32(0, inst_str));
    serialize_str(os, inst_str);
  }

  void compile_bytecode(const InstructionList &instructions,
                        ConstantsTable &const_tab, std::ostream &out) {
    serialize_header(out, const_tab);
    serialize_instructions(out, instructions);
  }

  // namespace Pop
}
