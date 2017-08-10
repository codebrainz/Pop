#ifndef POP_TYPEINFO_HPP
#define POP_TYPEINFO_HPP

#include <cassert>
#include <type_traits>

namespace Pop {

  template < class T, class U >
  inline bool isa(const U n) {
    typedef
        typename std::remove_pointer< typename std::remove_cv< T >::type >::type
            BaseT;
    if (!n)
      return false;
    return BaseT::classof(n);
  }

  template < class T, class U >
  inline T cast(U n) {
    assert(isa< T >(n));
    return static_cast< T >(n);
  }

  template < class T, class U >
  inline T dyn_cast(U n) {
    if (isa< T >(n))
      return cast< T >(n);
    return nullptr;
  }

  // namespace Pop
}

#endif // POP_TYPEINFO_HPP
