#include <pop/backend/bytecode-generator.hpp>
#include <pop/ir/instruction-visitor.hpp>
#include <pop/ir/instructions.hpp>
#include <pop/common/crc32.hpp>

#include <iostream>

namespace Pop {

  struct ByteCodeGenerator final : public InstructionVisitor {
    typedef std::uint8_t u8;
    typedef std::uint32_t u32;
    typedef std::uint64_t u64;
    typedef double f64;
    typedef std::string str;

    const ConstantsTable &constants;
    std::ostream &output;
    u32 checksum;

    ByteCodeGenerator(const ConstantsTable &constants, std::ostream &output)
        : constants(constants), output(output), checksum(1) {
    }

    void put8(u8 v) {
      output.write(reinterpret_cast< const char * >(&v), sizeof(u8));
    }

    template < class T >
    void crc32(const T &v) {
      checksum = Pop::crc32(checksum, v);
    }

    void ser_u8(u8 v) {
      crc32(v);
      put8(v);
    }

    void ser_u32(u32 v) {
      crc32(v);
      put8(v >> 24);
      put8(v >> 16);
      put8(v >> 8);
      put8(v);
    }

    void ser_u64(u64 v) {
      crc32(v);
      put8(v >> 56);
      put8(v >> 48);
      put8(v >> 40);
      put8(v >> 32);
      put8(v >> 24);
      put8(v >> 16);
      put8(v >> 8);
      put8(v);
    }

    void ser_f64(f64 v) {
      union {
        f64 f;
        u64 i;
      } u = { v };
      ser_u64(u.i);
    }

    void ser_str(const str &v) {
      ser_u32(v.size());
      crc32(v);
      for (const auto &ch : v)
        put8(ch);
    }

    void ser_type(TC ty) {
      ser_u8(static_cast< u8 >(ty));
    }

    void ser_opcode(OpCode code) {
      ser_u8(static_cast< u8 >(code));
    }

    void ser_inst5(Instruction &n, u32 i) {
      ser_opcode(n.code);
      ser_u32(i);
    }

    void put_constants() {
      ser_u32(constants.size());
      for (const auto &cnst : constants) {
        ser_type(cnst->type);
        switch (cnst->type) {
          case TC::NIL:
            break;
          case TC::BLN:
            ser_u8(cnst->u.as_bool);
            break;
          case TC::INT:
            ser_u64(cnst->u.as_int);
            break;
          case TC::FLT:
            ser_f64(cnst->u.as_float);
            break;
          case TC::STR:
            ser_str(*(cnst->u.as_str));
            break;
          case TC::SYM:
            ser_str(*(cnst->u.as_str));
            break;
        }
      }
    }

    void put_checksum() {
      put8(checksum >> 24);
      put8(checksum >> 16);
      put8(checksum >> 8);
      put8(checksum);
    }

    void visit_default(Instruction &inst) final {
      ser_opcode(inst.code);
    }

    void visit(PushConstInstruction &inst) final {
      ser_inst5(inst, inst.const_id);
    }

    void visit(ClosureInstruction &inst) final {
      ser_inst5(inst, inst.target);
    }

    void visit(JumpInstruction &inst) final {
      ser_inst5(inst, inst.target);
    }

    void visit(JumpIfTrueInstruction &inst) final {
      ser_inst5(inst, inst.target);
    }

    void visit(JumpIfFalseInstruction &inst) final {
      ser_inst5(inst, inst.target);
    }

    void visit(LabelInstruction &) final {
    }

    void visit(CommentInstruction &) final {
    }

    void visit(LineInstruction &) final {
    }
  };

  void generate_bytecode(const ConstantsTable &constants,
                         const InstructionList &instructions,
                         std::ostream &output) {
    ByteCodeGenerator visitor(constants, output);
    visitor.put_constants();
    for (auto &inst : instructions)
      inst->accept(visitor);
    visitor.put_checksum();
  }

  // namespace Pop
}
