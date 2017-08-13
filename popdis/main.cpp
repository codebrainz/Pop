#include <pop/pop.hpp>
#include <popdis/options.hpp>

#include <fstream>
#include <iostream>

using namespace Pop;

int main(int argc, char **argv) {
  Options opts;
  Logger log;
  ConstantsTable constants;
  InstructionList instructions;

  if (!opts.parse(argc, argv))
    return opts.exit_code;

  if (opts.input_filenames[0] == "-") {
    disassemble_bytecode(log, std::cin, "<stdin>", constants, instructions);
  } else {
    for (const auto &input_file : opts.input_filenames) {
      std::ifstream f(input_file, std::ios_base::binary);
      disassemble_bytecode(log, f, input_file, constants, instructions);
    }
  }

  if (opts.output_filename == "-") {
    dump_instructions(instructions, constants, std::cout);
  } else {
    std::ofstream f(opts.output_filename, std::ios_base::binary);
    dump_instructions(instructions, constants, f);
  }

  return log.report_messages(std::cerr);
}
