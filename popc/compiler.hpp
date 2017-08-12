#ifndef POP_COMPILER_HPP
#define POP_COMPILER_HPP

#include <pop/pop.hpp>

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
    void compile(bool line_directives = true);
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

    void link_parents(bool verify = false);
    void define_symbols();
    void resolve_symbols();
    void patch_locations(bool verify = false);
    void validate();
    void compile_instructions(bool line_directives = true);
    void resolve_instructions(bool prune_labels = false);
    void optimize_instructions();
  };

  // namespace Pop
}

#endif // POP_COMPILER_HPP
