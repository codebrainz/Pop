#ifndef POP_SERIALIZATION_HPP
#define POP_SERIALIZATION_HPP

#include <cstdint>
#include <istream>
#include <ostream>
#include <string>

namespace Pop {

  template < class ValueT >
  inline void serialize8(std::ostream &os, ValueT v) {
    os.put(static_cast< std::uint8_t >(v));
  }

  template < class ValueT >
  inline void deserialize8(std::istream &is, ValueT &v) {
    v = static_cast< ValueT >(is.get());
  }

  inline std::uint8_t deserialize8(std::istream &is) {
    std::uint8_t b = 0;
    deserialize8(is, b);
    return b;
  }

  template < class ValueT >
  inline void serialize32(std::ostream &os, ValueT v) {
    static_assert(sizeof(ValueT) <= sizeof(std::uint32_t),
                  "wrong size for serialize32");
    auto ui = static_cast< std::uint32_t >(v);
    serialize8(os, 0xFF & (ui >> 24));
    serialize8(os, 0xFF & (ui >> 16));
    serialize8(os, 0xFF & (ui >> 8));
    serialize8(os, 0xFF & ui);
  }

  template < class ValueT >
  inline void deserialize32(std::istream &is, ValueT &v) {
    static_assert(sizeof(ValueT) >= sizeof(std::uint32_t),
                  "wrong size for deserialize32");
    std::uint32_t u = 0;
    u |= static_cast< std::uint32_t >(deserialize8(is)) << 24;
    u |= static_cast< std::uint32_t >(deserialize8(is)) << 16;
    u |= static_cast< std::uint32_t >(deserialize8(is)) << 8;
    u |= static_cast< std::uint32_t >(deserialize8(is));
    v = static_cast< ValueT >(u);
  }

  inline std::uint32_t deserialize32(std::istream &is) {
    std::uint32_t v = 0;
    deserialize32(is, v);
    return v;
  }

  template < class ValueT >
  inline void serialize64(std::ostream &os, ValueT v) {
    static_assert(sizeof(ValueT) <= sizeof(std::uint64_t),
                  "wrong size for serialize64");
    auto ui = static_cast< std::uint64_t >(v);
    serialize8(os, 0xFF & (ui >> 56));
    serialize8(os, 0xFF & (ui >> 48));
    serialize8(os, 0xFF & (ui >> 40));
    serialize8(os, 0xFF & (ui >> 32));
    serialize8(os, 0xFF & (ui >> 24));
    serialize8(os, 0xFF & (ui >> 16));
    serialize8(os, 0xFF & (ui >> 8));
    serialize8(os, 0xFF & ui);
  }

  template < class ValueT >
  inline void deserialize64(std::istream &is, ValueT &v) {
    static_assert(sizeof(ValueT) >= sizeof(std::uint64_t),
                  "wrong size for deserialize64");
    std::uint64_t u = 0;
    u |= static_cast< std::uint64_t >(deserialize8(is)) << 56;
    u |= static_cast< std::uint64_t >(deserialize8(is)) << 48;
    u |= static_cast< std::uint64_t >(deserialize8(is)) << 40;
    u |= static_cast< std::uint64_t >(deserialize8(is)) << 32;
    u |= static_cast< std::uint64_t >(deserialize8(is)) << 24;
    u |= static_cast< std::uint64_t >(deserialize8(is)) << 16;
    u |= static_cast< std::uint64_t >(deserialize8(is)) << 8;
    u |= static_cast< std::uint64_t >(deserialize8(is));
    v = static_cast< ValueT >(u);
  }

  inline std::uint64_t deserialize64(std::istream &is) {
    std::uint64_t v = 0;
    deserialize64(is, v);
    return v;
  }

  template < class ValueT >
  inline void serialize_raw(std::ostream &os, ValueT v) {
    union {
      ValueT value;
      std::uint8_t buffer[sizeof(ValueT)];
    } u = { v };
    for (size_t i = 0; i < sizeof(ValueT); i++)
      serialize8(os, u.buffer[i]);
  }

  template < class ValueT >
  inline void deserialize_raw(std::istream &is, ValueT &v) {
    union {
      ValueT value;
      std::uint8_t buffer[sizeof(ValueT)];
    } u;
    for (size_t i = 0; i < sizeof(ValueT); i++) {
      u.buffer[i] = deserialize8(is);
    }
    v = u.value;
  }

  inline void serialize_str(std::ostream &os, const std::string &s) {
    serialize64(os, s.size());
    for (size_t i = 0; i < s.size(); i++)
      serialize8(os, s[i]);
  }

  inline void deserialize_str(std::istream &is, std::string &s) {
    auto len = deserialize64(is);
    s.reserve(s.size() + len);
    for (size_t i = 0; i < len; i++)
      s += static_cast< char >(deserialize8(is));
  }

  inline std::string deserialize_str(std::istream &is) {
    std::string s;
    deserialize_str(is, s);
    return s;
  }

  // namespace Pop
}

#endif // POP_SERIALIZATION_HPP
