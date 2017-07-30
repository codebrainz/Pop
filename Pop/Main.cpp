#include <Pop/Pop.hpp>
#include <iostream>

using namespace Pop;

int main() {
  Compiler cmp;
  cmp.parse_file("test.pop"); // 0
  cmp.link_parents();         // 1
  cmp.define_symbols();       // 2
  cmp.resolve_symbols();      // 3
  cmp.patch_locations();      // 4
  cmp.generate_dot(std::cout);
  return 0;
}
