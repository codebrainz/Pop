#include <pop/pop.hpp>
#include <popc/compiler.hpp>
#include <popc/options.hpp>

#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace Pop;

int main(int argc, char **argv) {
  Compiler cmp;
  Options opts;

  if (!opts.parse(argc, argv))
    return opts.exit_code;

  if (opts.input_filenames[0] == "-") {
    cmp.parse_file("<stdin>", std::cin);
  } else {
    for (const auto &input_file : opts.input_filenames)
      cmp.parse_file(input_file);
  }

  cmp.compile(!opts.no_line_directives);

  if (opts.dump_ast_dot) {
    if (opts.output_filename == "-") {
      cmp.dump_dot(std::cout);
    } else {
      std::ofstream f(opts.output_filename);
      cmp.dump_dot(f);
    }
  } else if (opts.dump_instructions) {
    if (opts.output_filename == "-") {
      cmp.dump_asm(std::cout);
    } else {
      std::ofstream f(opts.output_filename);
      cmp.dump_asm(f);
    }
  } else if (opts.dump_bytecode) {
    if (opts.output_filename == "-") {
      cmp.dump_bytecode(std::cout);
    } else {
      std::ofstream f(opts.output_filename, std::ios_base::binary);
      cmp.dump_bytecode(f);
    }
  } else {
    assert(false);
  }

  return cmp.report_diagnostics(std::cerr);
}
