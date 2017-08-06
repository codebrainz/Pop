#include <Pop/Disassembler.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace Pop;

int main(int argc, char **argv) {

  std::vector< std::string > input_filenames;

  for (int i = 1; i < argc; i++) {
    input_filenames.push_back(argv[i]);
    if (input_filenames.back() == "-h" || input_filenames.back() == "--help") {
      std::cout
          << "Usage: popdis FILES...\n"
          << "\n"
          << "Disassembles bytecode FILES... and writes to stdout.\n"
          << "\n"
          << "Written and maintained by Matthew Brush <mbrush@codebrainz.ca>\n";
      return 0;
    }
  }

  if (input_filenames.empty() || input_filenames[0] == "-") {
    disassemble(std::cin, std::cout);
  } else {
    for (const auto &fn : input_filenames) {
      std::ifstream f(fn);
      disassemble(f, std::cout);
    }
  }

  return 0;
}
