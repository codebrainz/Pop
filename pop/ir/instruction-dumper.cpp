#ifdef HAVE_CONFIG_H
#include <pop/config.h>
#endif

#include <pop/ir/instruction-dumper.hpp>
#include <pop/ir/ast.hpp>
#include <pop/ir/ast-visitor.hpp>
#include <pop/ir/constants-table.hpp>
#include <pop/ir/instructions.hpp>
#include <pop/ir/instruction-visitor.hpp>

#include <cstring>
#include <string>

namespace Pop {

  static void dump_constants(ConstantsTable &const_tab, std::ostream &os) {
    os << ";\n; Constants Table:\n;\n";
    for (size_t i = 0; i < const_tab.size(); i++)
      os << "#constant " << i << ' ' << *(const_tab.constant(i)) << '\n';
  }

  struct InstructionDumper : public InstructionVisitor {
    std::ostream &os;
    bool show_offsets;
    InstructionDumper(std::ostream &os) : os(os), show_offsets(true) {
    }
    std::string addr(Instruction &i) {
      if (show_offsets) {
        char buf[64] = { 0 };
        std::snprintf(buf, 63, "  %8XH", i.offset);
        return std::string(buf) + "    ";
      }
      return "    ";
    }
    void visit_default(Instruction &i) final {
      os << addr(i) << i.mnemonic() << '\n';
    }
    void visit(LabelInstruction &i) final {
      os << i.name << ":\n";
    }
    void visit(CommentInstruction &i) final {
      os << "; " << i.text << '\n';
    }
    void visit(LineInstruction &i) final {
      if (i.file.empty() && i.line < 0)
        return;
      os << "#line";
      if (!i.file.empty())
        os << " \"" << i.file << "\"";
      if (i.line >= 0) {
        os << ' ' << i.line;
        if (i.column >= 0)
          os << ' ' << i.column;
      }
      os << '\n';
    }
    void visit(PushConstInstruction &i) final {
      os << addr(i) << i.mnemonic() << ' ' << i.const_id << '\n';
    }
    template < class T >
    void visit_jump(T &i) {
      if (!i.label.empty()) {
        os << addr(i) << i.mnemonic() << ' ' << i.label << '\n';
      } else {
        char buf[64] = { 0 };
        std::snprintf(buf, 63, "%XH", i.target);
        os << addr(i) << i.mnemonic() << ' ' << buf << '\n';
      }
    }
    void visit(JumpInstruction &i) final {
      visit_jump(i);
    }
    void visit(JumpIfTrueInstruction &i) final {
      visit_jump(i);
    }
    void visit(JumpIfFalseInstruction &i) final {
      visit_jump(i);
    }
    void visit(ClosureInstruction &i) final {
      if (!i.name.empty()) {
        os << addr(i) << i.mnemonic() << ' ' << i.name << '\n';
      } else {
        char buf[64] = { 0 };
        std::snprintf(buf, 63, "%XH", i.target);
        os << addr(i) << i.mnemonic() << ' ' << buf << '\n';
      }
    }
  };

  void dump_instructions(const InstructionList &instructions,
                         ConstantsTable &const_tab, std::ostream &os) {
    dump_constants(const_tab, os);
    os << "\n;\n; Program:\n;\n";
    InstructionDumper dumper(os);
    for (auto &inst : instructions)
      inst->accept(dumper);
  }

  // namespace Pop
}
