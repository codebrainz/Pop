#ifndef POP_TYPECODE_HPP
#define POP_TYPECODE_HPP

#include <cstdint>

namespace Pop {

  enum class TC : std::uint8_t {
    NIL = 1,
    BLN,
    INT,
    FLT,
    STR,
    SYM,
  };

  // namespace Pop
}

#endif // POP_TYPECODE_HPP
