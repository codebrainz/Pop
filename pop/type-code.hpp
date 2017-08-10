#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

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
