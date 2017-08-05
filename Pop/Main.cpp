#include <Pop/Pop.hpp>
#include <cassert>
#include <iostream>

using namespace Pop;

int main(int argc, char **argv) {

  if (argc < 2) {
    std::cerr << "error: not enough arguments" << std::endl;
    return 1;
  }

  Compiler cmp;

  for (int i = 1; i < argc; i++)
    cmp.parse_file(argv[i]);

  cmp.patch_locations(true);
  cmp.link_parents(true);
  cmp.define_symbols();
  cmp.resolve_symbols();
  cmp.validate();
  cmp.compile_instructions();
  cmp.optimize_instructions();
  cmp.dump_instructions(std::cout);

  assert(cmp.report_diagnostics(std::cerr) == 0);
  return 0;
}
