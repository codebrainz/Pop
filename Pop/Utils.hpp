#ifndef POP_UTILS_HPP
#define POP_UTILS_HPP

#include <cstddef>
#include <string>

namespace Pop {

  long long int parse_int(const std::string &s);
  long double parse_float(const std::string &s);

  char *strdup(const char *s);
  char *strndup(const char *s, size_t n);

  // namespace Pop
}

#endif // POP_UTILS_HPP
