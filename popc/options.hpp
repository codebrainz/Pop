#ifndef POPC_OPTIONS_HPP

#include <string>
#include <vector>

namespace Pop {

  struct Options {
    std::vector< std::string > args;
    std::string program_name;
    std::string output_filename;
    std::vector< std::string > input_filenames;
    bool dump_ast_dot;
    bool dump_instructions;
    bool no_line_directives;
    int exit_code;

    Options() : dump_ast_dot(false), dump_instructions(false) {
    }

    bool parse(int argc, char **argv);
  };

  // namespace Pop
}

#endif // POPC_OPTIONS_HPP
