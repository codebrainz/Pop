#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

#ifndef POP_COMPILER_HPP
#define POP_COMPILER_HPP

#include <pop/common/logger.hpp>
#include <pop/ir/ast.hpp>
#include <pop/ir/constants-table.hpp>
#include <pop/ir/instructions.hpp>

#include <ostream>
#include <string>
#include <vector>

namespace Pop {

  class Compiler {
  public:
    Logger log;

    Compiler();
    ~Compiler();

    Node *parse_file(const std::string &fn);
    Node *parse_file(const std::string &fn, std::istream &is);
    void link_parents(bool verify = false);
    void define_symbols();
    void resolve_symbols();
    void patch_locations(bool verify = false);
    void validate();
    void compile_instructions(bool line_directives = true);
    void resolve_instructions(bool prune_labels = false);
    void optimize_instructions();

    void generate_dot(std::ostream &os, const std::string &indent_token = "  ");
    void dump_instructions(std::ostream &out);

    int report_diagnostics(int max_errors = -1);
    int report_diagnostics(std::ostream &os, int max_errors = -1);

  private:
    Program *program;
    std::vector< char * > filenames;
    ConstantsTable const_tab;
    InstructionList instructions;
    const char *add_fn(const std::string &fn);
  };

  // namespace Pop
}

#endif // POP_COMPILER_HPP
