#ifdef HAVE_CONFIG_H
#include <pop/config.h>
#endif

#include <pop/bytecode-compiler.hpp>
#include <pop/bytecode-file.hpp>
#include <pop/constants-table.hpp>
#include <pop/instruction-list.hpp>
#include <pop/instructions.hpp>

#include <sstream>

namespace Pop {

  class ByteCodeCompiler {
  public:
    ByteCodeCompiler(const InstructionList &instructions,
                     const ConstantsTable &constants, std::ostream &output)
        : instructions(instructions), constants(constants), output(output) {
    }

    void compile() {
      bcf.seek(0);

      for (const auto &c : POP_MAGIC_BYTES)
        bcf.set_u8(c);

      bcf.set_u32(POP_BYTECODE_VERSION);

      for (int i = 0; i < 4; i++)
        bcf.set_u32(0);

      bcf.set_u32(0); // constants offset (filled in later)
      bcf.set_u32(0); // bytecode offset (filled in later)

      // write out constants
      U32 constants_offset = bcf.tell();
      bcf.set_u32(constants.size());
      for (const auto &con : constants)
        con->serialize(bcf);

      // write out instructions
      U32 bytecode_offset = bcf.tell();
      for (const auto &inst : instructions)
        inst->serialize(bcf);

      U32 checksum_offset = bcf.tell();

      // fill in constants/bytecode offsets
      bcf.seek(POP_BYTECODE_CONSTANTS_OFFSET);
      bcf.insert_u32(constants_offset);
      bcf.seek(POP_BYTECODE_BYTECODE_OFFSET);
      bcf.insert_u32(bytecode_offset);

      // compute and append the checksum
      U32 checksum = bcf.checksum_range(0, checksum_offset);
      bcf.seek(checksum_offset);
      bcf.set_u32(checksum);

      bcf.save(output);
    }

  private:
    ByteCodeFile bcf;
    const InstructionList &instructions;
    const ConstantsTable &constants;
    std::ostream &output;
  };

  void compile_bytecode(const InstructionList &instructions,
                        const ConstantsTable &const_tab, std::ostream &out) {
    ByteCodeCompiler comp(instructions, const_tab, out);
    comp.compile();
  }

  // namespace Pop
}
