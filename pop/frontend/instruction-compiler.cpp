#ifdef HAVE_CONFIG_H
#include <pop/config.h>
#endif

#include <pop/frontend/instruction-compiler.hpp>
#include <pop/frontend/ast.hpp>
#include <pop/frontend/constants-table.hpp>
#include <pop/frontend/instructions.hpp>
#include <pop/frontend/visitor.hpp>

#include <cassert>
#include <stack>
#include <string>
#include <vector>

namespace Pop {

  struct InstructionCompiler final : public VisitorBase {

    struct Context {
      std::string name;
      int scope_depth;
      Context(const std::string &name) : name(name), scope_depth(0) {
      }
    };

    struct ContextStack {
      std::vector< Context > stack;
      size_t size() const {
        return stack.size();
      }
      bool empty() const {
        return stack.empty();
      }
      void push(const std::string &name) {
        stack.emplace_back(name);
      }
      int pop(const std::string &name) {
        assert(!stack.empty());
        assert(stack.back().name == name);
        return pop();
      }
      int pop() {
        assert(!stack.empty());
        int depth = stack.back().scope_depth;
        stack.pop_back();
        return depth;
      }
      Context &top() {
        assert(!stack.empty());
        return stack.back();
      }
      const Context &top() const {
        assert(!stack.empty());
        return stack.back();
      }
    };

    struct LineInfo {
      std::string file;
      int line;
      int column;
      LineInfo(const std::string &file = std::string(), int line = -1,
               int column = -1)
          : file(file), line(line), column(column) {
      }
      bool operator==(const LineInfo &other) const {
        return (file == other.file && line == other.line &&
                column == other.column);
      }
      bool operator!=(const LineInfo &other) const {
        return !operator==(other);
      }
      bool operator!() const {
        return (file.empty() && line < 0 && column < 0);
      }
      operator bool() const {
        return !(operator!());
      }
    };

    struct AtomToConstVisitor final : public DefaultPostOrderVisitor {
      Constant constant;
      AtomToConstVisitor() {
      }
      void process(Null &) final {
        constant = Constant::new_nil();
      }
      void process(Bool &n) final {
        constant = Constant::new_bool(n.value);
      }
      void process(Int &n) final {
        constant = Constant::new_int(n.value);
      }
      void process(Float &n) final {
        constant = Constant::new_float(n.value);
      }
      void process(String &n) final {
        constant = Constant::new_string(n.value);
      }
      void process(Symbol &n) final {
        constant = Constant::new_symbol(n.value);
      }
    };

    int count;
    int scope_depth;
    bool line_control;
    ConstantsTable &const_tab;
    std::stack< InstructionList * > inst_stack;
    ContextStack return_stack;
    ContextStack break_stack;
    ContextStack continue_stack;
    LineInfo last_line;

    InstructionCompiler(ConstantsTable &const_tab, InstructionList &list,
                        bool line_control = false)
        : count(0),
          scope_depth(0),
          line_control(line_control),
          const_tab(const_tab) {
      inst_stack.push(&list);
      begin_return_context(prefix_internal("invalid_return"));
      begin_break_context(prefix_internal("invalid_break"));
      begin_continue_context(prefix_internal("invalid_continue"));
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

    //
    // Instructions stack
    //
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

    //
    // Return context stack
    //
    void begin_return_context(const std::string &name) {
      return_stack.push(name);
    }
    void end_return_context(const std::string &name) {
      return_stack.pop(name);
    }
    Context &current_return_context() {
      return return_stack.top();
    }

    //
    // Break context stack
    //
    void begin_break_context(const std::string &name) {
      break_stack.push(name);
    }
    void end_break_context(const std::string &name) {
      break_stack.pop();
    }
    Context &current_break_context() {
      return break_stack.top();
    }

    //
    // Continue context stack
    //
    void begin_continue_context(const std::string &name) {
      continue_stack.push(name);
    }
    void end_continue_context(const std::string &name) {
      continue_stack.pop();
    }
    Context &current_continue_context() {
      return continue_stack.top();
    }

    //
    // Scope management
    //
    void begin_scope(Node &n) {
      add_instruction< OpenEnvironmentInstruction >(&n);
      if (!break_stack.empty())
        break_stack.top().scope_depth++;
      if (!continue_stack.empty())
        continue_stack.top().scope_depth++;
      if (!return_stack.empty())
        return_stack.top().scope_depth++;
    }
    void end_scope(Node &n) {
      if (!return_stack.empty())
        return_stack.top().scope_depth--;
      if (!continue_stack.empty())
        continue_stack.top().scope_depth--;
      if (!break_stack.empty())
        break_stack.top().scope_depth--;
      add_instruction< CloseEnvironmentInstruction >(&n);
    }

    template < class T, class... Args >
    T *add_instruction(Args &&... args) {
      auto inst = new T(std::forward< Args >(args)...);
      list().emplace_back(inst);
      return inst;
    }
    int intern(Node &n) {
      AtomToConstVisitor visitor;
      n.accept(visitor);
      return const_tab.intern(std::move(visitor.constant));
    }
    void add_constant(Node &n) {
      add_instruction< PushConstInstruction >(intern(n), &n);
    }
    void add_line_info(Node &n) {
      if (line_control) {
        const char *file = n.file() ? n.file() : "";
        LineInfo line_info(file, n.line(), n.column());
        if (last_line != line_info) {
          add_instruction< LineInstruction >(file, n.line(), n.column());
          last_line = std::move(line_info);
        }
      }
    }

    void visit(NodeList &n) final {
      for (auto elem : n.elements)
        elem->accept(*this);
    }
    void visit(Null &n) final {
      add_line_info(n);
      add_constant(n);
    }
    void visit(Bool &n) final {
      add_line_info(n);
      add_constant(n);
    }
    void visit(Int &n) final {
      add_line_info(n);
      add_constant(n);
    }
    void visit(Float &n) final {
      add_line_info(n);
      add_constant(n);
    }
    void visit(String &n) final {
      add_line_info(n);
      add_constant(n);
    }
    void visit(Symbol &n) final {
      add_line_info(n);
      add_constant(n);
    }
    void visit(Unary &n) final {
      n.operand->accept(*this);
      add_line_info(n);
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
      add_line_info(n);
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
      add_line_info(n);
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
      add_line_info(n);
      add_instruction< CallInstruction >(&n);
    }
    std::string parent_name(Node &n) const {
      if (auto var = dyn_cast< Variable * >(n.parent))
        return var->name;
      return "";
    }
    void visit(Function &n) final {
      add_line_info(n);
      auto var_name = parent_name(n);
      auto name = var_name.empty() ? new_name("lambda") : new_name(var_name);
      add_instruction< JumpInstruction >(name + "_after", &n);
      add_instruction< LabelInstruction >(name, &n);
      begin_scope(n);
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
      end_scope(n);
      add_instruction< ReturnInstruction >(&n);
      add_instruction< LabelInstruction >(name + "_after", &n);
      add_line_info(n);
      add_instruction< ClosureInstruction >(name, &n);
    }
    void visit(Block &n) final {
      add_line_info(n);
      auto name = new_name("block");
      begin_scope(n);
      n.statements->accept(*this);
      end_scope(n);
    }
    void visit(ExprStmt &n) final {
      add_line_info(n);
      n.expression->accept(*this);
      add_instruction< PopInstruction >(&n);
    }
    void visit(EmptyStmt &) final {
    }
    void visit(Continue &n) final {
      add_line_info(n);
      // int depth = current_continue_context().scope_depth;
      // for (int i = 0; i < depth; i++)
      //  add_instruction< CloseEnvironmentInstruction >(&n);
      add_instruction< JumpInstruction >(current_continue_context().name, &n);
    }
    void visit(Break &n) final {
      add_line_info(n);
      int depth = current_break_context().scope_depth;
      for (int i = 0; i < depth; i++)
        add_instruction< CloseEnvironmentInstruction >(&n);
      add_instruction< JumpInstruction >(current_break_context().name, &n);
    }
    void visit(Return &n) final {
      add_line_info(n);
      if (n.expression) {
        n.expression->accept(*this);
      } else {
        auto nul = new Null(n.file(), n.line(), n.column());
        add_constant(*nul);
        node_unref(nul);
      }
      // int depth = current_return_context().scope_depth;
      // for (int i = 0; i < depth; i++)
      //  add_instruction< CloseEnvironmentInstruction >(&n);
      add_instruction< JumpInstruction >(current_return_context().name, &n);
    }
    void visit(Goto &) final {
      // TODO
    }
    void visit(IfStmt &n) final {
      add_line_info(n);
      auto name = new_name("if");
      n.predicate->accept(*this);
      add_instruction< JumpIfTrueInstruction >(name + "_cons", &n);
      if (n.alternative)
        n.alternative->accept(*this);
      add_instruction< JumpInstruction >(name + "_end", &n);
      add_instruction< LabelInstruction >(name + "_cons", &n);
      n.consequence->accept(*this);
      add_instruction< LabelInstruction >(name + "_end", &n);
    }
    void visit(Case &) final {
      // see visit(Switch&)
    }
    void visit(Switch &n) final {
      add_line_info(n);
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
            add_line_info(*cse);
            if (cse->expression) {
              auto case_name = name + "_case_" + std::to_string(cnt);
              add_instruction< LabelInstruction >(case_name, cse);
              add_instruction< DuplicateTopInstruction >(cse);
              cse->expression->accept(*this);
              add_instruction< EqualInstruction >(cse);
              add_instruction< JumpIfFalseInstruction >(
                  name + "_case_" + std::to_string(cnt + 1), cse);
              begin_scope(*cse);
              begin_break_context(case_name + "_break");
              cse->body->accept(*this);
              end_break_context(case_name + "_break");
              end_scope(*cse);
              add_instruction< JumpInstruction >(name + "_case_" +
                                                 std::to_string(cnt + 1));
              add_instruction< LabelInstruction >(case_name + "_break", cse);
              add_instruction< CloseEnvironmentInstruction >(cse);
              add_instruction< JumpInstruction >(case_name + "_end", cse);
            } else {
              auto case_name = name + "_default_case";
              assert(!have_default);
              add_instruction< LabelInstruction >(case_name, cse);
              begin_scope(*cse);
              begin_break_context(case_name + "_break");
              cse->body->accept(*this);
              end_break_context(case_name + "_break");
              end_scope(*cse);
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
      add_line_info(n);
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
      add_line_info(n);
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
      add_line_info(n);
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
      add_line_info(n);
      auto name = new_name("module");
      begin_scope(n);
      if (n.body)
        n.body->accept(*this);
      end_scope(n);
    }
    void visit(Program &n) final {
      n.modules->accept(*this);
      // TODO: main, jump to start, etc.
      add_instruction< HaltInstruction >(&n);
    }
  };

  void compile_instructions(Node *root, ConstantsTable &const_tab,
                            InstructionList &list) {
    assert(root);
    InstructionCompiler visitor(const_tab, list, true);
    root->accept(visitor);
  }

  // namespace Pop
}
