#ifdef HAVE_CONFIG_H
#include <Pop/Config.h>
#endif

#include <Pop/ByteCodeCompiler.hpp>
#include <Pop/AST.hpp>
#include <Pop/ConstantsTable.hpp>
#include <Pop/Instructions.hpp>
#include <Pop/InstructionVisitor.hpp>
#include <Pop/Serialization.hpp>
#include <Pop/Visitor.hpp>
#include <cassert>
#include <cstdint>
#include <sstream>

#define MAGIC_BYTES "\xAA\x55POP"

namespace Pop {

  enum class TC : std::uint8_t {
    NIL = 1,
    BLN,
    INT,
    FLT,
    STR,
    SYM,
  };

  struct ConstSerializeVisitor final : public DefaultPostOrderVisitor {
    std::ostream &os;
    ConstSerializeVisitor(std::ostream &os) : os(os) {
    }
    void process(Null &n) final {
      serialize8(os, TC::NIL);
    }
    void process(Bool &n) final {
      serialize8(os, TC::BLN);
      serialize8(os, n.value ? 1 : 0);
    }
    void process(Int &n) final {
      serialize8(os, TC::INT);
      serialize64(os, n.value);
    }
    void process(Float &n) final {
      serialize8(os, TC::FLT);
      serialize_raw(os, n.value);
    }
    void process(String &n) final {
      serialize8(os, TC::STR);
      serialize_str(os, n.value);
    }
    void process(Symbol &n) final {
      serialize8(os, TC::SYM);
      serialize_str(os, n.value);
    }
  };

  static void serialize_magic(std::ostream &os) {
    static const std::string magic = MAGIC_BYTES;
    for (auto ch : magic)
      serialize8(os, ch);
  }

  static void serialize_constants(std::ostream &os, ConstantsTable &const_tab) {
    serialize32(os, static_cast< std::uint32_t >(const_tab.size()));
    ConstSerializeVisitor visitor(os);
    for (const auto n : const_tab) {
      assert(n);
      n->accept(visitor);
    }
  }

  static void serialize_header(std::ostream &os, ConstantsTable &const_tab) {
    std::stringstream ss_magic;
    serialize_magic(ss_magic);
    auto str_magic = ss_magic.str();

    std::stringstream ss_const;
    serialize_constants(ss_const, const_tab);
    auto str_const = ss_const.str();

    std::uint32_t bc_offset =
        str_magic.size() + str_const.size() + sizeof(std::uint64_t);

    os.write(str_magic.data(), str_magic.size());
    serialize32(os, bc_offset);
    os.write(str_const.data(), str_const.size());
  }

  struct ByteCodeCompileVisitor : public InstructionVisitor {
    std::ostream &os;
    ByteCodeCompileVisitor(std::ostream &os) : os(os) {
    }
    void write_code(Instruction &inst) {
      serialize8(os, static_cast< std::uint8_t >(inst.code));
    }
    void visit_default(Instruction &inst) final {
      assert(inst.size() == 1);
      write_code(inst);
    }
    void visit(PushConstInstruction &inst) final {
      write_code(inst);
      serialize32(os, inst.const_id);
    }
    void visit(ClosureInstruction &inst) final {
      write_code(inst);
      serialize32(os, inst.target);
    }
    void visit(JumpInstruction &inst) final {
      write_code(inst);
      serialize32(os, inst.target);
    }
    void visit(JumpIfTrueInstruction &inst) final {
      write_code(inst);
      serialize32(os, inst.target);
    }
    void visit(JumpIfFalseInstruction &inst) final {
      write_code(inst);
      serialize32(os, inst.target);
    }
    void visit(LabelInstruction &) final {
    }
  };

  static void serialize_instructions(std::ostream &os,
                                     const InstructionList &instructions) {
    ByteCodeCompileVisitor visitor(os);
    for (auto &inst : instructions)
      inst->accept(visitor);
  }

  void compile_bytecode(const InstructionList &instructions,
                        ConstantsTable &const_tab, std::ostream &out) {
    serialize_header(out, const_tab);
    serialize_instructions(out, instructions);
  }

  // namespace Pop
}
