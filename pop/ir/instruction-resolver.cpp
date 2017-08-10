#ifdef HAVE_CONFIG_H
#include <pop/config.h>
#endif

#include <pop/ir/instruction-resolver.hpp>
#include <pop/ir/instructions.hpp>
#include <pop/ir/instruction-visitor.hpp>

#include <string>
#include <unordered_map>

namespace Pop {

  struct LabelOffsetTable {
    std::unordered_map< std::string, int > tab;
    void add_label(LabelInstruction &lbl) {
      tab.emplace(lbl.name, lbl.offset);
    }
    int resolve_label(const std::string &name) const {
      auto found = tab.find(name);
      if (found != tab.end())
        return found->second;
      return -1;
    }
  };

  struct LabelFinder : public InstructionVisitor {
    LabelOffsetTable &tab;
    LabelFinder(LabelOffsetTable &tab) : tab(tab) {
    }
    void visit_default(Instruction &) final {
    }
    void visit(LabelInstruction &n) final {
      tab.add_label(n);
    }
  };

  struct LabelResolver : public InstructionVisitor {
    LabelOffsetTable &tab;
    LabelResolver(LabelOffsetTable &tab) : tab(tab) {
    }
    void visit_default(Instruction &) final {
    }
    void visit(JumpInstruction &n) final {
      n.target = tab.resolve_label(n.label);
    }
    void visit(JumpIfTrueInstruction &n) final {
      n.target = tab.resolve_label(n.label);
    }
    void visit(JumpIfFalseInstruction &n) final {
      n.target = tab.resolve_label(n.label);
    }
    void visit(ClosureInstruction &n) final {
      n.target = tab.resolve_label(n.name);
    }
  };

  void resolve_instructions(InstructionList &instructions, bool prune_labels) {

    // calculate offsets
    int offset = 0;
    for (auto &inst : instructions) {
      inst->offset = offset;
      offset += inst->size();
    }

    LabelOffsetTable tab;

    LabelFinder finder(tab);
    for (auto &inst : instructions)
      inst->accept(finder);

    LabelResolver resolver(tab);
    for (auto &inst : instructions)
      inst->accept(resolver);

    if (prune_labels) {
      for (auto it = instructions.begin(); it != instructions.end();) {
        auto &inst = *it;
        if (isa< LabelInstruction * >(inst.get()))
          it = instructions.erase(it);
        else
          ++it;
      }
    }
  }

  // namespace Pop
}
