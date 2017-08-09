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
    ByteCodeFile bcf;
    const std::string &in_fn;
    std::ostream &out;
    std::ostream &err;

    DisData(const std::string &in_fn, std::istream &in, std::ostream &out,
            std::ostream &err)
        : in_fn(in_fn), out(out), err(err) {
      assert(in.good());
      assert(out.good());
      assert(err.good());
      bcf.load(in);
      err << "Size: " << bcf.size() << '\n';
    }

    void get_magic(std::string &s) {
      s.reserve(s.size() + sizeof(POP_MAGIC_BYTES));
      bcf.seek(POP_BYTECODE_MAGIC_OFFSET);
      s.push_back(bcf.get_u8());
      s.push_back(bcf.get_u8());
      s.push_back(bcf.get_u8());
      s.push_back(bcf.get_u8());
    }

    void dump() {

      // get magic bytes
      std::string magic_str;
      assert(bcf.tell() == POP_BYTECODE_MAGIC_OFFSET);
      get_magic(magic_str);
      out << ";\tMAGIC: " << magic_str << '\n';

      // get bytecode version
      assert(bcf.tell() == POP_BYTECODE_VERSION_OFFSET);
      U32 version = bcf.get_u32();
      out << ";\tVERSION: " << version << '\n';

      // skip 4 reserved 32-bit fields
      for (int i = 0; i < 4; i++)
        bcf.get_u32();

      // constants offset
      assert(bcf.tell() == POP_BYTECODE_CONSTANTS_OFFSET);
      U32 const_offset = bcf.get_u32();
      out << ";\tCONSTANTS: " << const_offset << '\n';

      // bytecode offset
      assert(bcf.tell() == POP_BYTECODE_BYTECODE_OFFSET);
      U32 bc_offset = bcf.get_u32();
      out << ";\tBYTECODE: " << bc_offset << '\n';

      // constants table
      assert(bcf.tell() == const_offset);
      U32 n_constants = bcf.get_u32();
      for (U32 i = 0; i < n_constants; i++) {
        auto con = Constant::deserialize(bcf);
        out << ";\t CONST " << i << ": " << con.to_string() << '\n';
      }

      // get the checksum
      auto save_off = bcf.tell();
      bcf.seek(4, ByteCodeFile::Origin::END);
      U32 end = bcf.tell();
      U32 checksum_in = bcf.get_u32();
      bcf.resize(bcf.size() - 4);
      bcf.seek(save_off);
      U32 checksum_out = bcf.checksum_range(0, end);

      // bytecode instructions
      assert(bcf.tell() == bc_offset);
      for (U32 i = bcf.tell(); i < end; i = bcf.tell()) {
        auto inst = Instruction::deserialize(bcf);
        assert(inst);
        assert(inst->code != OpCode::LBL);
        out << inst->to_string();
      }

      assert(checksum_in == checksum_out);
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
