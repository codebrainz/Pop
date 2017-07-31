// This file is auto-generated from Validate.cpp.in, do not edit.
#include <Pop/Validate.hpp>
#include <Pop/AST.hpp>
#include <Pop/Logger.hpp>
#include <Pop/Visitor.hpp>
#include <cassert>
#include <vector>

namespace Pop {

  struct JumpStmtVisitor final : public VisitorBase {
    Logger &log;
    std::vector< bool > breakables;
    std::vector< bool > continuables;
    std::vector< bool > returnables;
    JumpStmtVisitor(Logger &log) : log(log) {
      breakables.push_back(false);
      continuables.push_back(false);
      returnables.push_back(false);
    }
    void begin_breakable() {
      breakables.push_back(true);
    }
    void end_breakable() {
      breakables.pop_back();
    }
    bool breakable() const {
      if (!breakables.empty())
        return breakables.back();
      return false;
    }
    void begin_continuable() {
      continuables.push_back(true);
    }
    void end_continuable() {
      continuables.pop_back();
    }
    bool continuable() const {
      if (!continuables.empty())
        return continuables.back();
      return false;
    }
    void begin_returnable() {
      returnables.push_back(true);
    }
    void end_returnable() {
      returnables.pop_back();
    }
    bool returnable() const {
      if (!returnables.empty())
        return returnables.back();
      return false;
    }
    void visit(Null &n) final {
      (void)n;
    }
    void visit(Bool &n) final {
      (void)n;
    }
    void visit(Int &n) final {
      (void)n;
    }
    void visit(Float &n) final {
      (void)n;
    }
    void visit(String &n) final {
      (void)n;
    }
    void visit(Symbol &n) final {
      (void)n;
    }
    void visit(Unary &n) final {
      if (n.operand)
        n.operand->accept(*this);
    }
    void visit(Binary &n) final {
      if (n.left)
        n.left->accept(*this);
      if (n.right)
        n.right->accept(*this);
    }
    void visit(IfExpr &n) final {
      if (n.predicate)
        n.predicate->accept(*this);
      if (n.consequence)
        n.consequence->accept(*this);
      if (n.alternative)
        n.alternative->accept(*this);
    }
    void visit(Call &n) final {
      if (n.callee)
        n.callee->accept(*this);
      if (n.arguments)
        n.arguments->accept(*this);
    }
    void visit(Function &n) final {
      begin_returnable();
      if (n.parameters)
        n.parameters->accept(*this);
      if (n.body)
        n.body->accept(*this);
      end_returnable();
    }
    void visit(Block &n) final {
      if (n.statements)
        n.statements->accept(*this);
    }
    void visit(ExprStmt &n) final {
      if (n.expression)
        n.expression->accept(*this);
    }
    void visit(EmptyStmt &n) final {
      (void)n;
    }
    void visit(Continue &n) final {
      if (!continuable()) {
        log.error(n.file(), n.line(), n.column(),
                  "continue statement in wrong context");
      }
    }
    void visit(Break &n) final {
      if (!breakable()) {
        log.error(n.file(), n.line(), n.column(),
                  "break statement in wrong context");
      }
    }
    void visit(Return &n) final {
      if (!returnable()) {
        log.error(n.file(), n.line(), n.column(),
                  "return statement in wrong context");
      }
    }
    void visit(Goto &n) final {
      (void)n;
    }
    void visit(IfStmt &n) final {
      if (n.predicate)
        n.predicate->accept(*this);
      if (n.consequence)
        n.consequence->accept(*this);
      if (n.alternative)
        n.alternative->accept(*this);
    }
    void visit(Case &n) final {
      begin_breakable();
      if (n.expression)
        n.expression->accept(*this);
      if (n.body)
        n.body->accept(*this);
      end_breakable();
    }
    void visit(Switch &n) final {
      if (n.expression)
        n.expression->accept(*this);
      if (n.cases)
        n.cases->accept(*this);
    }
    void visit(Do &n) final {
      begin_breakable();
      begin_continuable();
      if (n.body)
        n.body->accept(*this);
      if (n.expression)
        n.expression->accept(*this);
      end_continuable();
      end_breakable();
    }
    void visit(While &n) final {
      begin_breakable();
      begin_continuable();
      if (n.expression)
        n.expression->accept(*this);
      if (n.body)
        n.body->accept(*this);
      end_continuable();
      end_breakable();
    }
    void visit(For &n) final {
      begin_breakable();
      begin_continuable();
      if (n.initialize)
        n.initialize->accept(*this);
      if (n.test)
        n.test->accept(*this);
      if (n.increment)
        n.increment->accept(*this);
      if (n.body)
        n.body->accept(*this);
      end_continuable();
      end_breakable();
    }
    void visit(Label &n) final {
      (void)n;
    }
    void visit(Variable &n) final {
      if (n.initializer)
        n.initializer->accept(*this);
    }
    void visit(Class &n) final {
      if (n.members)
        n.members->accept(*this);
    }
    void visit(Module &n) final {
      if (n.body)
        n.body->accept(*this);
    }
    void visit(Program &n) final {
      if (n.modules)
        n.modules->accept(*this);
    }
  };

  void validate(Node *root, Logger &log) {
    assert(root);
    JumpStmtVisitor visitor(log);
    root->accept(visitor);
  }

  // namespace Pop
}
