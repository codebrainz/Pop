#ifdef HAVE_CONFIG_H
#include <Pop/Config.h>
#endif

#include <Pop/InstructionDumper.hpp>
#include <Pop/AST.hpp>
#include <Pop/ConstantsTable.hpp>
#include <Pop/Instructions.hpp>
#include <Pop/InstructionVisitor.hpp>
#include <Pop/Visitor.hpp>
#include <string>

namespace Pop {

  struct ConstantStringVisitor : public DefaultPreOrderVisitor {
    std::string &str;
    ConstantStringVisitor(std::string &str) : str(str) {
    }
    void process(Null &) final {
      str = "null";
    }
    void process(Bool &n) final {
      str = n.value ? "true" : "false";
    }
    void process(Int &n) final {
      str = std::to_string(n.value);
    }
    void process(Float &n) final {
      str = std::to_string(n.value);
    }
    void process(String &n) final {
      str = n.value;
    }
    void process(Symbol &n) final {
      str = n.value;
    }
  };

  static std::string constant_string(Node &n) {
    std::string str;
    ConstantStringVisitor visitor(str);
    n.accept(visitor);
    assert(!str.empty());
    return str;
  }

  static void dump_constants(ConstantsTable &const_tab, std::ostream &os) {
    int i = 0;
    while (1) {
      auto n = const_tab.node(i);
      if (!n)
        break;
      os << "; " << i << ": " << constant_string(*n) << '\n';
      i++;
    }
  }

  struct InstructionDumper : public InstructionVisitor {
    std::ostream &os;
    InstructionDumper(std::ostream &os) : os(os) {
    }
    void visit_default(Instruction &i) final {
      os << '\t' << i.mnemonic() << '\n';
    }
    void visit(LabelInstruction &i) final {
      os << i.name << ":\n";
    }
    void visit(PushConstInstruction &i) final {
      os << '\t' << i.mnemonic() << ' ' << i.const_id << '\n';
    }
    template < class T >
    void visit_jump(T &i) {
      os << '\t' << i.mnemonic() << ' ' << i.label << '\n';
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
      os << '\t' << i.mnemonic() << ' ' << i.name << '\n';
    }
  };

  void dump_instructions(const InstructionList &instructions,
                         ConstantsTable &const_tab, std::ostream &os) {
    dump_constants(const_tab, os);

    InstructionDumper dumper(os);
    for (auto &inst : instructions)
      inst->accept(dumper);
  }

  // namespace Pop
}
