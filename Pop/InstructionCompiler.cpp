#include <Pop/InstructionCompiler.hpp>
#include <Pop/AST.hpp>
#include <Pop/ConstantsTable.hpp>
#include <Pop/Visitor.hpp>
#include <cassert>
#include <stack>
#include <string>

namespace Pop {

  struct InstructionCompiler : public VisitorBase {
    int count;
    ConstantsTable &const_tab;
    std::stack< InstructionList * > inst_stack;
    std::stack< std::string > return_stack;
    std::stack< std::string > break_stack;
    std::stack< std::string > continue_stack;

    InstructionCompiler(ConstantsTable &const_tab, InstructionList &list)
        : count(0), const_tab(const_tab) {
      inst_stack.push(&list);
      return_stack.push(prefix_internal("invalid_return"));
      break_stack.push(prefix_internal("invalid_break"));
      continue_stack.push(prefix_internal("invalid_continue"));
    }

    ~InstructionCompiler() {
      continue_stack.pop();
      break_stack.pop();
      return_stack.pop();
      inst_stack.pop();
    }

    std::string new_name(const std::string &prefix = "tmp") {
      int id = count++;
      return prefix_internal(prefix) + std::to_string(id);
    }
    std::string prefix_internal(const std::string &name) {
      return "__internal_" + name;
    }

    InstructionList &list() {
      assert(!inst_stack.empty());
      return *(inst_stack.top());
    }
    void begin_instructions(InstructionList &lst) {
      inst_stack.push(&lst);
    }
    void end_instructions(InstructionList &lst) {
      assert(!inst_stack.empty());
      assert(inst_stack.top() == &lst);
      inst_stack.pop();
    }

    void begin_return_context(const std::string &name) {
      return_stack.push(name);
    }
    void end_return_context(const std::string &name) {
      assert(!return_stack.empty());
      assert(return_stack.top() == name);
      return_stack.pop();
    }
    std::string current_return_context() const {
      assert(!return_stack.empty());
      return return_stack.top();
    }

    void begin_break_context(const std::string &name) {
      break_stack.push(name);
    }
    void end_break_context(const std::string &name) {
      assert(!break_stack.empty());
      assert(break_stack.top() == name);
      break_stack.pop();
    }
    std::string current_break_context() const {
      assert(!break_stack.empty());
      return break_stack.top();
    }

    void begin_continue_context(const std::string &name) {
      continue_stack.push(name);
    }
    void end_continue_context(const std::string &name) {
      assert(!continue_stack.empty());
      assert(continue_stack.top() == name);
      continue_stack.pop();
    }
    std::string current_continue_context() const {
      assert(!continue_stack.empty());
      return continue_stack.top();
    }

    template < class T, class... Args >
    T *add_instruction(Args &&... args) {
      auto inst = new T(std::forward< Args >(args)...);
      list().emplace_back(inst);
      return inst;
    }
    int intern(Node &n) {
      return const_tab.intern(&n);
    }
    void add_constant(Node &n) {
      add_instruction< PushConstInstruction >(intern(n), &n);
    }

    void visit(NodeList &n) final {
      for (auto elem : n.elements)
        elem->accept(*this);
    }
    void visit(Null &n) final {
      add_constant(n);
    }
    void visit(Bool &n) final {
      add_constant(n);
    }
    void visit(Int &n) final {
      add_constant(n);
    }
    void visit(Float &n) final {
      add_constant(n);
    }
    void visit(String &n) final {
      add_constant(n);
    }
    void visit(Symbol &n) final {
      add_constant(n);
    }
    void visit(Unary &n) final {
      n.operand->accept(*this);
      switch (n.op) {
        case Operator::POS:
          add_instruction< PositiveInstruction >(&n);
          break;
        case Operator::NEG:
          add_instruction< NegativeInstruction >(&n);
          break;
        case Operator::NOT:
          add_instruction< LogicalNotInstruction >(&n);
          break;
        case Operator::COMPL:
          add_instruction< BitwiseNotInstruction >(&n);
          break;
        case Operator::PREINC:
          add_instruction< IncrementInstruction >(&n);
          break;
        case Operator::PREDEC:
          add_instruction< DecrementInstruction >(&n);
          break;
        case Operator::POSTINC:
          add_instruction< DuplicateTopInstruction >(&n);
          add_instruction< IncrementInstruction >(&n);
          add_instruction< PopInstruction >(&n);
          break;
        case Operator::POSTDEC:
          add_instruction< DuplicateTopInstruction >(&n);
          add_instruction< DecrementInstruction >(&n);
          add_instruction< PopInstruction >(&n);
          break;
        default:
          assert(false);
          break;
      }
    }
    template < class T >
    void inplace_op(Node &n) {
      add_instruction< Duplicate2ndTopInstruction >(&n);
      add_instruction< SwapTopInstruction >(&n);
      add_instruction< T >(&n);
      add_instruction< BindInstruction >(&n);
    }
    void visit(Binary &n) final {
      n.left->accept(*this);
      n.right->accept(*this);
      switch (n.op) {
        case Operator::ADD:
          add_instruction< AddInstruction >(&n);
          break;
        case Operator::SUB:
          add_instruction< SubtractInstruction >(&n);
          break;
        case Operator::MUL:
          add_instruction< MultiplyInstruction >(&n);
          break;
        case Operator::DIV:
          add_instruction< DivideInstruction >(&n);
          break;
        case Operator::MOD:
          add_instruction< ModuloInstruction >(&n);
          break;
        case Operator::LSHIFT:
          add_instruction< LeftShiftInstruction >(&n);
          break;
        case Operator::RSHIFT:
          add_instruction< RightShiftInstruction >(&n);
          break;
        case Operator::LAND:
          add_instruction< LogicalAndInstruction >(&n);
          break;
        case Operator::LOR:
          add_instruction< LogicalOrInstruction >(&n);
          break;
        case Operator::BAND:
          add_instruction< BitwiseAndInstruction >(&n);
          break;
        case Operator::BOR:
          add_instruction< BitwiseOrInstruction >(&n);
          break;
        case Operator::BXOR:
          add_instruction< BitwiseXorInstruction >(&n);
          break;
        case Operator::LE:
          add_instruction< LessOrEqualInstruction >(&n);
          break;
        case Operator::GE:
          add_instruction< GreaterOrEqualInstruction >(&n);
          break;
        case Operator::LT:
          add_instruction< LessThanInstruction >(&n);
          break;
        case Operator::GT:
          add_instruction< GreaterThanInstruction >(&n);
          break;
        case Operator::EQ:
          add_instruction< EqualInstruction >(&n);
          break;
        case Operator::NE:
          add_instruction< NotEqualInstruction >(&n);
          break;
        case Operator::INDEX:
          add_instruction< IndexInstruction >(&n);
          break;
        case Operator::MEMBER:
          add_instruction< MemberInstruction >(&n);
          break;
        case Operator::ASSIGN:
          add_instruction< BindInstruction >(&n);
          break;
        case Operator::LSHIFT_ASSIGN:
          inplace_op< LeftShiftInstruction >(n);
          break;
        case Operator::RSHIFT_ASSIGN:
          inplace_op< RightShiftInstruction >(n);
          break;
        case Operator::ADD_ASSIGN:
          inplace_op< AddInstruction >(n);
          break;
        case Operator::SUB_ASSIGN:
          inplace_op< SubtractInstruction >(n);
          break;
        case Operator::MUL_ASSIGN:
          inplace_op< MultiplyInstruction >(n);
          break;
        case Operator::DIV_ASSIGN:
          inplace_op< DivideInstruction >(n);
          break;
        case Operator::MOD_ASSIGN:
          inplace_op< ModuloInstruction >(n);
          break;
        case Operator::AND_ASSIGN:
          inplace_op< BitwiseAndInstruction >(n);
          break;
        case Operator::OR_ASSIGN:
          inplace_op< BitwiseOrInstruction >(n);
          break;
        case Operator::XOR_ASSIGN:
          inplace_op< BitwiseXorInstruction >(n);
          break;
        case Operator::PTR_MEMBER:
        default:
          assert(false);
          break;
      }
    }
    void visit(IfExpr &n) final {
      auto name = new_name("ifexp");
      n.predicate->accept(*this);
      add_instruction< JumpIfTrueInstruction >(name + "_cons", &n);
      if (n.alternative) {
        auto sym = new Symbol(n.file(), n.line(), n.column(), name + "_result");
        add_constant(*sym);
        node_unref(sym);
        n.alternative->accept(*this);
        add_instruction< BindInstruction >(&n);
      }
      add_instruction< JumpInstruction >(name + "_end", &n);
      add_instruction< LabelInstruction >(name + "_cons", &n);
      auto sym = new Symbol(n.file(), n.line(), n.column(), name + "_result");
      add_constant(*sym);
      node_unref(sym);
      n.consequence->accept(*this);
      add_instruction< BindInstruction >(&n);
      add_instruction< LabelInstruction >(name + "_end", &n);
    }
    void visit(Call &n) final {
      if (auto arglist = dynamic_cast< NodeList * >(n.arguments)) {
        for (auto it = arglist->elements.rbegin();
             it != arglist->elements.rend(); ++it) {
          (*it)->accept(*this);
        }
        auto cnt = new Int(arglist->file(), arglist->line(), arglist->column(),
                           arglist->elements.size());
        add_constant(*cnt);
        node_unref(cnt);
      } else {
        auto cnt = new Int(n.file(), n.line(), n.column(), 0);
        add_constant(*cnt);
        node_unref(cnt);
      }
      n.callee->accept(*this);
      add_instruction< CallInstruction >(&n);
    }
    void visit(Function &n) final {
      auto name = new_name("lambda");
      add_instruction< JumpInstruction >(name + "_after", &n);
      add_instruction< LabelInstruction >(name, &n);
      add_instruction< OpenEnvironmentInstruction >(&n);
      begin_return_context(name + "_return");
      // todo: use the argument count
      add_instruction< PopInstruction >(&n);
      if (auto params = dynamic_cast< NodeList * >(n.parameters)) {
        for (auto param : params->elements) {
          if (auto var = dynamic_cast< Variable * >(param)) {
            auto sym =
                new Symbol(var->file(), var->line(), var->column(), var->name);
            add_constant(*sym);
            node_unref(sym);
            add_instruction< BindInstruction >(var);
          } else {
            assert(false);
          }
        }
      }
      if (n.body)
        n.body->accept(*this);
      end_return_context(name + "_return");
      add_instruction< LabelInstruction >(name + "_return", &n);
      add_instruction< CloseEnvironmentInstruction >(&n);
      add_instruction< ReturnInstruction >(&n);
      add_instruction< LabelInstruction >(name + "_after", &n);
      add_instruction< ClosureInstruction >(name, &n);
    }
    void visit(Block &n) final {
      add_instruction< OpenEnvironmentInstruction >(&n);
      n.statements->accept(*this);
      add_instruction< CloseEnvironmentInstruction >(&n);
    }
    void visit(ExprStmt &n) final {
      n.expression->accept(*this);
      add_instruction< PopInstruction >(&n);
    }
    void visit(EmptyStmt &) final {
    }
    void visit(Continue &n) final {
      add_instruction< JumpInstruction >(current_continue_context(), &n);
    }
    void visit(Break &n) final {
      add_instruction< JumpInstruction >(current_break_context(), &n);
    }
    void visit(Return &n) final {
      if (n.expression) {
        n.expression->accept(*this);
      } else {
        auto nul = new Null(n.file(), n.line(), n.column());
        add_constant(*nul);
        node_unref(nul);
      }
      add_instruction< JumpInstruction >(current_return_context(), &n);
    }
    void visit(Goto &) final {
      // TODO
    }
    void visit(IfStmt &n) final {
      auto name = new_name("if");
      n.predicate->accept(*this);
      add_instruction< JumpIfTrueInstruction >(name + "_cons", &n);
      if (n.alternative) {
        n.alternative->accept(*this);
        add_instruction< JumpInstruction >(name + "_end", &n);
      }
      add_instruction< LabelInstruction >(name + "_cons", &n);
      n.consequence->accept(*this);
      add_instruction< LabelInstruction >(name + "_end", &n);
    }
    void visit(Case &) final {
      // see visit(Switch&)
    }
    void visit(Switch &n) final {
      auto name = new_name("switch");
      auto switch_sym =
          new Symbol(n.file(), n.line(), n.column(), name + "_test");
      add_constant(*switch_sym);
      node_unref(switch_sym);
      n.expression->accept(*this);
      add_instruction< BindInstruction >(&n);
      int cnt = 0;
      bool have_default = false;
      if (auto cases = dynamic_cast< NodeList * >(n.cases)) {
        for (auto celem : cases->elements) {
          if (auto cse = dynamic_cast< Case * >(celem)) {
            if (cse->expression) {
              auto case_name = name + "_case_" + std::to_string(cnt);
              add_instruction< LabelInstruction >(case_name, cse);
              add_instruction< DuplicateTopInstruction >(cse);
              cse->expression->accept(*this);
              add_instruction< EqualInstruction >(cse);
              add_instruction< JumpIfFalseInstruction >(
                  name + "_case_" + std::to_string(cnt + 1), cse);
              add_instruction< OpenEnvironmentInstruction >(cse);
              begin_break_context(case_name + "_break");
              cse->body->accept(*this);
              end_break_context(case_name + "_break");
              add_instruction< CloseEnvironmentInstruction >(cse);
              add_instruction< JumpInstruction >(name + "_case_" +
                                                 std::to_string(cnt + 1));
              add_instruction< LabelInstruction >(case_name + "_break", cse);
              add_instruction< CloseEnvironmentInstruction >(cse);
              add_instruction< JumpInstruction >(case_name + "_end", cse);
            } else {
              auto case_name = name + "_default_case";
              assert(!have_default);
              add_instruction< LabelInstruction >(case_name, cse);
              add_instruction< OpenEnvironmentInstruction >(cse);
              begin_break_context(case_name + "_break");
              cse->body->accept(*this);
              end_break_context(case_name + "_break");
              add_instruction< CloseEnvironmentInstruction >(cse);
              add_instruction< JumpInstruction >(name + "_case_" +
                                                 std::to_string(cnt + 1));
              add_instruction< LabelInstruction >(case_name + "_break", cse);
              add_instruction< CloseEnvironmentInstruction >(cse);
              add_instruction< JumpInstruction >(case_name + "_end", cse);
              have_default = true;
            }
            cnt++;
          }
        }
      }
      if (!have_default)
        add_instruction< LabelInstruction >(name + "_default_case", &n);
      add_instruction< LabelInstruction >(name + "_case_" +
                                          std::to_string(cnt));
      add_instruction< LabelInstruction >(name + "_end", &n);
      add_instruction< PopInstruction >(&n);
    }
    void visit(Do &n) final {
      auto name = new_name("do");
      add_instruction< LabelInstruction >(name + "_continue", &n);
      begin_continue_context(name + "_continue");
      begin_break_context(name + "_break");
      n.body->accept(*this);
      end_break_context(name + "_break");
      end_continue_context(name + "_continue");
      n.expression->accept(*this);
      add_instruction< JumpIfFalseInstruction >(name + "_break", &n);
      add_instruction< JumpInstruction >(name + "_continue", &n);
      add_instruction< LabelInstruction >(name + "_break", &n);
    }
    void visit(While &n) final {
      auto name = new_name("while");
      add_instruction< LabelInstruction >(name + "_continue", &n);
      n.expression->accept(*this);
      add_instruction< JumpIfFalseInstruction >(name + "_break", &n);
      begin_continue_context(name + "_continue");
      begin_break_context(name + "_break");
      n.body->accept(*this);
      end_break_context(name + "_break");
      end_continue_context(name + "_continue");
      add_instruction< JumpInstruction >(name + "_continue", &n);
      add_instruction< LabelInstruction >(name + "_break", &n);
    }
    void visit(For &) final {
      // TODO
    }
    void visit(Label &) final {
      // TODO
    }
    void visit(Variable &n) final {
      auto sym = new Symbol(n.file(), n.line(), n.column(), n.name);
      add_constant(*sym);
      node_unref(sym);
      if (n.initializer) {
        n.initializer->accept(*this);
      } else {
        auto nul = new Null(n.file(), n.line(), n.column());
        add_constant(*nul);
        node_unref(nul);
      }
      add_instruction< BindInstruction >(&n);
    }
    void visit(Class &) final {
      // TODO
    }
    void visit(Module &n) final {
      add_instruction< OpenEnvironmentInstruction >(&n);
      n.body->accept(*this);
      add_instruction< CloseEnvironmentInstruction >(&n);
    }
    void visit(Program &n) final {
      n.modules->accept(*this);
      // TODO: main, jump to start, etc.
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
