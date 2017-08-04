#include <Pop/InstructionCompiler.hpp>
#include <Pop/AST.hpp>
#include <Pop/Visitor.hpp>
#include <cassert>

namespace Pop {

  struct InstructionCompiler : public DefaultPostOrderVisitor {
    ConstantsTable &const_tab;
    InstructionList &list;
    InstructionCompiler(ConstantsTable &const_tab, InstructionList &list)
        : const_tab(const_tab), list(list) {
    }
  };

  void compile_instructions(Node *root, ConstantsTable &const_tab,
                            InstructionList &list) {
    assert(root);
    InstructionCompiler visitor(const_tab, list);
    root->accept(visitor);
  }

  // namespace Pop
}
