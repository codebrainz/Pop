#ifndef POPDIS_OPTIONS_HPP
#define POPDIS_OPTIONS_HPP

#include <string>
#include <vector>

namespace Pop {

  struct Options {
    std::vector< std::string > args;
    std::string program_name;
    std::string output_filename;
    std::vector< std::string > input_filenames;
    int exit_code;

    Options() : exit_code(0) {
    }

    bool parse(int argc, char **argv);
  };

  // namespace Pop
}

#endif // POPDIS_OPTIONS_HPP
