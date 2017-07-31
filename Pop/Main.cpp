#include <Pop/Pop.hpp>
#include <cassert>
#include <iostream>

using namespace Pop;

int main() {
  Compiler cmp;
  cmp.parse_file("test.pop"); // 0
  cmp.link_parents(true);     // 1
  cmp.define_symbols();       // 2
  cmp.resolve_symbols();      // 3
  cmp.patch_locations(true);  // 4
  cmp.validate();             // 5
  cmp.generate_dot(std::cout);
  assert(cmp.report_diagnostics(std::cerr) == 0);
  return 0;
}
