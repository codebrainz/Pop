#ifdef HAVE_CONFIG_H
#include <Pop/Config.h>
#endif

#include <Pop/Disassembler.hpp>
#include <Pop/Constant.hpp>
#include <Pop/CRC32.hpp>
#include <Pop/Instructions.hpp>
#include <Pop/Serialization.hpp>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <sstream>

namespace Pop {

  struct DisData {
    const std::string &in_fn;
    std::istream &in;
    std::ostream &out;
    std::ostream &err;
    uint32_t constants_offset;
    uint32_t bytecode_offset;
    uint32_t checksum;

    DisData(const std::string &in_fn, std::istream &in, std::ostream &out,
            std::ostream &err)
        : in_fn(in_fn), in(in), out(out), err(err), constants_offset(0),
          bytecode_offset(0) {
      assert(in.good());
      assert(out.good());
      assert(err.good());
    }

    void dump() {
      std::string as_str(std::istreambuf_iterator< char >(in), {});
      std::stringstream ss(as_str);

      uint32_t crc_in = 0;
      uint32_t s_size = as_str.size();
      crc_in |= uint32_t(uint8_t(as_str.back()));
      as_str.pop_back();
      crc_in |= uint32_t(uint8_t(as_str.back())) << 8;
      as_str.pop_back();
      crc_in |= uint32_t(uint8_t(as_str.back())) << 16;
      as_str.pop_back();
      crc_in |= uint32_t(uint8_t(as_str.back())) << 24;
      as_str.pop_back();
      s_size = as_str.size();

      auto crc = crc32(0, as_str);
      assert(crc == crc_in);

      out << "; MAGIC = ";
      for (auto i = 0; i < 4; i++)
        out << static_cast< char >(deserialize8(ss));
      out << '\n';

      out << "; VERSION = " << deserialize32(ss) << '\n';

      for (auto i = 0; i < 4; i++) {
        out << "; RESERVED #" << (i + 1) << " = " << deserialize32(ss) << '\n';
      }

      auto const_offset = deserialize32(ss);
      auto instr_offset = deserialize32(ss);
      out << "; CONSTANTS = " << const_offset << '\n';
      out << "; BYTECODE = " << instr_offset << '\n';
      out << ";\n";

      auto n_constants = deserialize32(ss);
      for (uint32_t i = 0; i < n_constants; i++) {
        auto c = Constant::deserialize(ss);
        out << "; CONST " << i << " = " << c << '\n';
      }

      out << "; CRC32 = in:" << crc_in << ", out:" << crc << '\n';

      for (size_t i = ss.tellp(); i < s_size; i++) {
        if (auto instruction = Instruction::deserialize(ss)) {
          if (instruction->code == OpCode::LBL)
            continue;
          char buf[32] = { 0 };
          std::snprintf(buf, 31, "%8d", instruction->offset - instr_offset);
          out << buf << '\t' << instruction->to_string();
        }
      }
    }
  };

  bool disassemble(std::istream &is, std::ostream &os, std::ostream &err) {
    return disassemble("<stream>", is, os, err);
  }

  bool disassemble(const std::string &fn, std::istream &is, std::ostream &os,
                   std::ostream &err) {
    DisData dat(fn, is, os, err);
    dat.dump();
    return true;
  }

  // namespace Pop
}
