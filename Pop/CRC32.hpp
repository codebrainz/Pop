#ifndef POP_CRC32_HPP
#define POP_CRC32_HPP

#include <cstdint>
#include <string>
#include <type_traits>

namespace Pop {

  uint32_t crc32(uint32_t crc, const void *buf, size_t size);

  template < class T >
  inline uint32_t crc32(uint32_t crc, const T &v) {
    static_assert(std::is_standard_layout< T >::value,
                  "Value must be a standard layout type");
    return crc32(crc, &v, sizeof(T));
  }

  template <>
  inline uint32_t crc32(uint32_t crc, const std::string &str) {
    return crc32(crc, str.data(), str.size());
  }

  // namespace Pop
}

#endif // POP_CRC32_HPP
