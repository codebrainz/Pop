#ifndef POP_SERIALIZATION_HPP
#define POP_SERIALIZATION_HPP

#include <cstdint>
#include <ostream>
#include <string>

namespace Pop {

  template < class ValueT >
  inline void serialize8(std::ostream &os, ValueT v) {
    os.put(static_cast< std::uint8_t >(v));
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
  inline void serialize_raw(std::ostream &os, ValueT v) {
    union {
      ValueT value;
      std::uint8_t buffer[sizeof(ValueT)];
    } u = { v };
    for (size_t i = 0; i < sizeof(ValueT); i++)
      serialize8(os, u.buffer[i]);
  }

  inline void serialize_str(std::ostream &os, const std::string &s) {
    serialize64(os, s.size());
    for (size_t i = 0; i < s.size(); i++)
      serialize8(os, s[i]);
  }

  // namespace Pop
}

#endif // POP_SERIALIZATION_HPP
