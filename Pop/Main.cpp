#include <Pop/Pop.hpp>
#include <cassert>
#include <iostream>

using namespace Pop;

int main() {
  Compiler cmp;
  cmp.parse_file("test.pop");
  cmp.patch_locations(true);
  cmp.link_parents(true);
  cmp.define_symbols();
  cmp.resolve_symbols();
  cmp.validate();
  cmp.generate_dot(std::cout);
  assert(cmp.report_diagnostics(std::cerr) == 0);
  return 0;
}
