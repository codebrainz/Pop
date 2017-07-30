#ifndef POP_COMPILER_HPP
#define POP_COMPILER_HPP

#include <Pop/AST.hpp>
#include <Pop/Logger.hpp>
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
    void link_parents();
    void define_symbols();
    void generate_dot(std::ostream &os, const std::string &indent_token = "  ");
    void report_diagnostics(int max_errors = -1);
    void report_diagnostics(std::ostream &os, int max_errors = -1);

  private:
    Program *program;
    std::vector< char * > filenames;
    const char *add_fn(const std::string &fn);
  };

  // namespace Pop
}

#endif // POP_COMPILER_HPP
