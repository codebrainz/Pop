#include <Pop/ConstantsTable.hpp>
#include <cassert>

namespace Pop {

  ConstantsTable::ConstantsTable() : count(0) {
  }

  ConstantsTable::~ConstantsTable() {
    for (auto &pair : node_to_id)
      node_unref(pair.first);
    for (auto node : node_vec)
      node_unref(node);
  }

  int ConstantsTable::intern(Node *n) {
    assert(n);
    auto found = node_to_id.find(n);
    if (found != node_to_id.end())
      return found->second;
    int c = count;
    count++;
    node_to_id.emplace(n->ref(), c);
    node_vec.emplace_back(n->ref());
    return c;
  }

  Node *ConstantsTable::node(int id) {
    if (id >= 0 && size_t(id) < node_vec.size())
      return node_vec[id];
    return nullptr;
  }

  // namespace Pop
}
