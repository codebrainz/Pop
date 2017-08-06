#ifndef POP_OPTION_PARSER_HPP
#define POP_OPTION_PARSER_HPP

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
    bool dump_bytecode;
    int exit_code;

    Options()
        : dump_ast_dot(false), dump_instructions(false), dump_bytecode(false) {
    }

    bool parse(int argc, char **argv);
  };

  // namespace Pop
}

#endif // POP_OPTION_PARSER_HPP
