#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

#ifndef POP_CONSTANTS_TABLE_HPP
#define POP_CONSTANTS_TABLE_HPP

#include <pop/frontend/constant.hpp>

#include <cassert>
#include <unordered_map>
#include <vector>

namespace Pop {

  class ConstantsTable {

    struct Hasher {
      size_t operator()(const Constant *cptr) const {
        assert(cptr);
        return cptr->hash();
      }
    };

    struct Comparator {
      bool operator()(const Constant *cp1, const Constant *cp2) const {
        assert(cp1);
        assert(cp2);
        return cp1->operator==(*cp2);
      }
    };

    typedef std::unordered_map< Constant *, int, Hasher, Comparator >
        ConstantIdMap;

  public:
    int intern(const Constant &c);
    int intern(Constant &&c);
    Constant *constant(int id);

    size_t size() const {
      return constants.size();
    }

    ConstantList::iterator begin() {
      return constants.begin();
    }
    ConstantList::iterator end() {
      return constants.end();
    }
    ConstantList::const_iterator begin() const {
      return constants.begin();
    }
    ConstantList::const_iterator end() const {
      return constants.end();
    }

  private:
    int count = 0;
    ConstantIdMap constants_map;
    ConstantList constants;
  };

  // namespace Pop
}

#endif // POP_CONSTANTS_TABLE_HPP
