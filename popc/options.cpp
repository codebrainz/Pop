#ifdef HAVE_CONFIG_H
#include <pop/config.h>
#endif

#include <popc/options.hpp>
#include <iostream>

namespace Pop {

  static void show_help(void) {
    // clang-format off
    std::cout
      << "Usage: popc [options] FILES...\n"
      << "\n"
      << "Compiles Pop source FILES... to byte code\n"
      << "\n"
      << "Options:\n"
      << "--------\n"
      << "  -h, --help              Show this message and exit\n"
      << "  -o FILE, --output=FILE  Write output to file (default '-' for stdout)\n"
      << "  --dump-dot              Write a Graphviz DOT graph of the AST\n"
      << "  --dump-asm              Write an ASM-like representation of the IR\n"
      << "  --no-line-directives    Don't print #line directives in output\n"
      << "\n"
      << "Written and maintained by Matthew Brush <mbrush@codebrainz.ca>\n";
    // clang-format on
  }

  bool Options::parse(int argc, char **argv) {
    for (int i = 0; i < argc; i++)
      args.push_back(argv[i]);

    size_t offset = 0;
    program_name = args[offset++];

    output_filename.clear();

    for (size_t i = offset, last = (args.size() - 1); i < args.size(); i++) {
      if (args[i] == "-h" || args[i] == "--help") {
        show_help();
        exit_code = 0;
        return false;
      } else if (args[i] == "-o" || args[i] == "--output") {
        if (i != last) {
          output_filename = argv[i + 1];
          i++;
          continue;
        } else {
          std::cerr << "error: missing argument to '-o' ('--output') option"
                    << std::endl;
          exit_code = 1;
          return false;
        }
      } else if (args[i] == "--dump-dot") {
        dump_ast_dot = true;
      } else if (args[i] == "--dump-asm") {
        dump_instructions = true;
      } else if (args[i] == "--no-line-directives") {
        no_line_directives = true;
      } else {
        input_filenames.push_back(argv[i]);
      }
    }

    if (dump_ast_dot && dump_instructions) {
      std::cerr << "error: --dump-dot and --dump-asm are mutually exclusive"
                << std::endl;
      exit_code = 1;
      return false;
    } else if (!dump_ast_dot && !dump_instructions) {
      dump_bytecode = true;
    }

    if (output_filename.empty())
      output_filename = "-";

    if (input_filenames.empty())
      input_filenames.push_back("-");

    exit_code = 0;
    return true;
  }

  // namespace Pop
}
