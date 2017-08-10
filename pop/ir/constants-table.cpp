#ifdef HAVE_CONFIG_H
#include <pop/config.h>
#endif

#include <pop/ir/constants-table.hpp>
#include <cassert>

namespace Pop {

  int ConstantsTable::intern(const Constant &c) {
    return intern(Constant(c));
  }

  int ConstantsTable::intern(Constant &&c) {
    auto cc = std::move(c);
    auto found = constants_map.find(&cc);
    if (found != constants_map.end())
      return found->second;
    int id = count++;
    auto ncc = new Constant(std::move(cc));
    constants.emplace_back(ncc);
    constants_map.emplace(ncc, id);
    return id;
  }

  Constant *ConstantsTable::constant(int id) {
    if (id >= 0 && size_t(id) < constants.size())
      return constants[id].get();
    return nullptr;
  }

  // namespace Pop
}
