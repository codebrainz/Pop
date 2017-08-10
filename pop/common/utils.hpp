#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

#ifndef POP_UTILS_HPP
#define POP_UTILS_HPP

#include <pop/common/crc32.hpp>

#include <cstddef>
#include <string>
#include <utility>

namespace Pop {

  long long int parse_int(const std::string &s);
  long double parse_float(const std::string &s);

  char *strdup(const char *s);
  char *strndup(const char *s, size_t n);

  template < class T >
  inline void hash_combine(std::size_t &seed, const T &v) {
    std::hash< T > hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  }

  // namespace Pop
}

#endif // POP_UTILS_HPP
