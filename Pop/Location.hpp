#pragma once

#include <memory>
#include <string>

namespace Pop {

  typedef std::shared_ptr< std::string > StringPtr;

  struct Location {
    StringPtr file;
    int line, column;
    Location(StringPtr file, int line = -1, int column = 0)
        : file(file), line(line), column(column) {
    }
    Location(const std::string &file, int line = -1, int column = 0)
        : Location(std::make_shared< std::string >(file), line, column) {
    }
    std::string to_string() const {
      std::string s;
      if (file)
        s += *file + ':';
      if (line >= 0 && column >= 0)
        s += std::to_string(line) + ':' + std::to_string(column);
      return s;
    }
  };

  // namespace Pop
}
