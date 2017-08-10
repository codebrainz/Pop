#ifdef HAVE_CONFIG_H
#include <pop/config.h>
#endif

#include <pop/utils.hpp>

#include <cstring>
#include <stdexcept>

namespace Pop {

  static int int_base(const std::string &s, const char **start) {
    *start = s.c_str();
    if (s.size() == 1 || s.size() == 2) {
      if (s[0] == '0')
        return 8;
      else
        return 10;
    } else if (s.size() > 2) {
      if (s[0] == '0') {
        switch (s[1]) {
          case 'b':
          case 'B':
            *start = s.c_str() + 2;
            return 2;
          case 'd':
          case 'D':
            *start = s.c_str() + 2;
            return 10;
          case 'h':
          case 'H':
            *start = s.c_str() + 2;
            return 16;
          case 'o':
          case 'O':
            *start = s.c_str() + 2;
            return 8;
          default:
            return 0;
        }
      } else {
        return 10;
      }
    } else {
      return 0;
    }
  }

  long long int parse_int(const std::string &s) {
    const char *start = s.c_str();
    const size_t len = strlen(start);
    const auto base = int_base(s, &start);
    size_t pos = 0;
    auto val = std::stoll(start, &pos, base);
    if (pos != len)
      throw std::runtime_error("invalid integer");
    return val;
  }

  long double parse_float(const std::string &s) {
    size_t pos = 0;
    auto val = std::stold(s, &pos);
    if (pos != s.size())
      throw std::runtime_error("invalid float");
    return val;
  }

  char *strdup(const char *s) {
    if (!s)
      return nullptr;
    return Pop::strndup(s, strlen(s));
  }

  char *strndup(const char *s, size_t n) {
    if (!s) {
      return nullptr;
    } else if (n == 0) {
      return reinterpret_cast< char * >(std::calloc(1, sizeof(char)));
    } else {
      auto buf = reinterpret_cast< char * >(std::malloc(n + 1));
      if (!buf)
        return nullptr;
      std::memcpy(buf, s, n);
      buf[n] = '\0';
      return buf;
    }
  }

  // namespace Pop
}
