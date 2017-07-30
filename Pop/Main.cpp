#include <Pop/Pop.hpp>
#include <iostream>

using namespace Pop;

int main() {
  Compiler cmp;
  cmp.parse_file("test.pop");
  cmp.generate_dot(std::cout);
  return 0;
}
