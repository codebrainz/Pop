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
    void visit(Null &n) override final {
      (void)n;
    }
    void visit(Bool &n) override final {
      (void)n;
    }
    void visit(Int &n) override final {
      (void)n;
    }
    void visit(Float &n) override final {
      (void)n;
    }
    void visit(String &n) override final {
      (void)n;
    }
    void visit(Symbol &n) override final {
      (void)n;
    }
    void visit(Unary &n) override final {
      if (n.operand)
        n.operand->accept(*this);
    }
    void visit(Binary &n) override final {
      if (n.left)
        n.left->accept(*this);
      if (n.right)
        n.right->accept(*this);
    }
    void visit(IfExpr &n) override final {
      if (n.predicate)
        n.predicate->accept(*this);
      if (n.consequence)
        n.consequence->accept(*this);
      if (n.alternative)
        n.alternative->accept(*this);
    }
    void visit(Call &n) override final {
      if (n.callee)
        n.callee->accept(*this);
      if (n.arguments)
        n.arguments->accept(*this);
    }
    void visit(Function &n) override final {
      begin_returnable();
      if (n.parameters)
        n.parameters->accept(*this);
      if (n.body)
        n.body->accept(*this);
      end_returnable();
    }
    void visit(Block &n) override final {
      if (n.statements)
        n.statements->accept(*this);
    }
    void visit(ExprStmt &n) override final {
      if (n.expression)
        n.expression->accept(*this);
    }
    void visit(EmptyStmt &n) override final {
      (void)n;
    }
    void visit(Continue &n) override final {
      if (!continuable()) {
        log.error(n.file(), n.line(), n.column(),
                  "continue statement in wrong context");
      }
    }
    void visit(Break &n) override final {
      if (!breakable()) {
        log.error(n.file(), n.line(), n.column(),
                  "break statement in wrong context");
      }
    }
    void visit(Return &n) override final {
      if (!returnable()) {
        log.error(n.file(), n.line(), n.column(),
                  "return statement in wrong context");
      }
    }
    void visit(Goto &n) override final {
      (void)n;
    }
    void visit(IfStmt &n) override final {
      if (n.predicate)
        n.predicate->accept(*this);
      if (n.consequence)
        n.consequence->accept(*this);
      if (n.alternative)
        n.alternative->accept(*this);
    }
    void visit(Case &n) override final {
      begin_breakable();
      if (n.expression)
        n.expression->accept(*this);
      if (n.body)
        n.body->accept(*this);
      end_breakable();
    }
    void visit(Switch &n) override final {
      if (n.expression)
        n.expression->accept(*this);
      if (n.cases)
        n.cases->accept(*this);
    }
    void visit(Do &n) override final {
      begin_breakable();
      begin_continuable();
      if (n.body)
        n.body->accept(*this);
      if (n.expression)
        n.expression->accept(*this);
      end_continuable();
      end_breakable();
    }
    void visit(While &n) override final {
      begin_breakable();
      begin_continuable();
      if (n.expression)
        n.expression->accept(*this);
      if (n.body)
        n.body->accept(*this);
      end_continuable();
      end_breakable();
    }
    void visit(For &n) override final {
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
    void visit(Label &n) override final {
      (void)n;
    }
    void visit(Variable &n) override final {
      if (n.initializer)
        n.initializer->accept(*this);
    }
    void visit(Class &n) override final {
      if (n.members)
        n.members->accept(*this);
    }
    void visit(Module &n) override final {
      if (n.body)
        n.body->accept(*this);
    }
    void visit(Program &n) override final {
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
