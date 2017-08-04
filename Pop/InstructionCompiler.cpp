#include <Pop/InstructionCompiler.hpp>
#include <Pop/AST.hpp>
#include <Pop/Visitor.hpp>
#include <cassert>

namespace Pop {

  struct InstructionCompiler : public DefaultPostOrderVisitor {
    InstructionList &list;
    InstructionCompiler(InstructionList &list) : list(list) {
    }
  };

  void compile_instructions(Node *root, InstructionList &list) {
    assert(root);
    InstructionCompiler visitor(list);
    root->accept(visitor);
  }

  // namespace Pop
}
