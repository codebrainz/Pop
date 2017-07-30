#include <Pop/Pop.hpp>
#include <iostream>

using namespace Pop;

int main() {
  Compiler cmp;
  cmp.parse_file("test.pop");
  cmp.link_parents();
  cmp.define_symbols();
  cmp.resolve_symbols();
  cmp.generate_dot(std::cout);
  return 0;
}
