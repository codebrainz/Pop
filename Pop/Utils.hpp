#ifndef POP_UTILS_HPP
#define POP_UTILS_HPP

#include <cstddef>
#include <string>
#include <utility>

namespace Pop {

  long long int parse_int(const std::string &s);
  long double parse_float(const std::string &s);

  char *strdup(const char *s);
  char *strndup(const char *s, size_t n);

  template < class T >
  static inline void hash_combine(std::size_t &seed, const T &v) {
    std::hash< T > hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }

  // namespace Pop
}

#endif // POP_UTILS_HPP
