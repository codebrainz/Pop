#include <pop/backend/bytecode-disassembler.hpp>
#include <pop/common/logger.hpp>
#include <pop/common/utils.hpp>
#include <pop/ir/constant.hpp>
#include <pop/ir/instructions.hpp>

namespace Pop {

  struct Deserializer {
    typedef std::uint8_t u8;
    typedef std::uint32_t u32;
    typedef std::uint64_t u64;
    typedef double f64;
    typedef std::string str;

    Logger &log;
    std::istream &input;
    const std::string &fn;
    ConstantsTable &constants;
    InstructionList &instructions;
    u32 checksum;

    Deserializer(Logger &log, std::istream &input, const std::string &fn,
                 ConstantsTable &constants, InstructionList &instructions)
        : log(log),
          input(input),
          fn(fn),
          constants(constants),
          instructions(instructions),
          checksum(0) {
    }

    template < class T >
    void crc32(const T &v) {
      checksum = Pop::crc32(checksum, v);
    }

    u8 get8() {
      u8 v = 0;
      input.read(reinterpret_cast< char * >(&v), sizeof(u8));
      return v;
    }

    u8 des_u8() {
      u8 v = get8();
      crc32(v);
      return v;
    }

    u32 des_u32() {
      u32 v = 0;
      v |= u32(get8()) << 24;
      v |= u32(get8()) << 16;
      v |= u32(get8()) << 8;
      v |= u32(get8());
      crc32(v);
      return v;
    }

    u64 des_u64() {
      u64 v = 0;
      v |= u64(get8()) << 56;
      v |= u64(get8()) << 48;
      v |= u64(get8()) << 40;
      v |= u64(get8()) << 32;
      v |= u64(get8()) << 24;
      v |= u64(get8()) << 16;
      v |= u64(get8()) << 8;
      v |= u64(get8());
      crc32(v);
      return v;
    }

    f64 des_f64() {
      union {
        u64 i;
        f64 f;
      } u = { 0 };
      u.i = des_u64();
      return u.f;
    }

    str des_str() {
      u32 len = des_u32();
      str res;
      res.reserve(len);
      for (u32 i = 0; i < len; i++)
        res += static_cast< char >(get8());
      crc32(res);
      return res;
    }

    TC des_type() {
      return static_cast< TC >(des_u8());
    }

    OpCode des_opcode() {
      return static_cast< OpCode >(des_u8());
    }

    void des_inst5(OpCode &code, u32 &i) {
      code = des_opcode();
      i = des_u32();
    }

    void deserialize_constants() {
      auto n = des_u32();
      for (auto i = 0u; i < n; i++) {
        auto ty = des_type();
        switch (ty) {
          case TC::NIL:
            constants.intern(Constant::new_nil());
            break;
          case TC::BLN:
            constants.intern(Constant::new_bool(des_u8()));
            break;
          case TC::INT:
            constants.intern(Constant::new_int(des_u64()));
            break;
          case TC::FLT:
            constants.intern(Constant::new_float(des_f64()));
            break;
          case TC::STR:
            constants.intern(Constant::new_string(des_str()));
            break;
          case TC::SYM:
            constants.intern(Constant::new_symbol(des_str()));
            break;
        }
      }
    }

    void deserialize_instructions() {
    }

    bool verify_checksum() {
      u32 v = 0;
      v |= u32(get8()) << 24;
      v |= u32(get8()) << 16;
      v |= u32(get8()) << 8;
      v |= u32(get8());
      return (v == checksum);
    }

    void deserialize() {
      deserialize_constants();
      deserialize_instructions();

      if (!verify_checksum()) {
        log.error(fn.c_str(), -1, -1,
                  "CRC32 does not match, bytecode is corrupted");
      }
    }
  };

  void disassemble_bytecode(Logger &log, std::istream &input,
                            const std::string &fn, ConstantsTable &constants,
                            InstructionList &instructions) {
    Deserializer des(log, input, fn, constants, instructions);
    des.deserialize();
  }

  // namespace Pop
}
