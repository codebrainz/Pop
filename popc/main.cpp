#include <pop/pop.hpp>
#include <popc/compiler.hpp>
#include <popc/options.hpp>

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

  cmp.patch_locations(true);
  cmp.link_parents(true);
  cmp.define_symbols();
  cmp.resolve_symbols();
  cmp.validate();
  cmp.compile_instructions(!opts.no_line_directives);
  cmp.resolve_instructions();
  cmp.optimize_instructions();

  if (opts.dump_ast_dot) {
    if (opts.output_filename == "-") {
      cmp.generate_dot(std::cout);
    } else {
      std::ofstream f(opts.output_filename);
      cmp.generate_dot(f);
    }
  } else if (opts.dump_instructions) {
    if (opts.output_filename == "-") {
      cmp.dump_instructions(std::cout);
    } else {
      std::ofstream f(opts.output_filename);
      cmp.dump_instructions(f);
    }
  }

  return cmp.report_diagnostics(std::cerr);
}
