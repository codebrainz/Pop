#ifndef POP_CONSTANTS_TABLE_HPP
#define POP_CONSTANTS_TABLE_HPP

#include <Pop/AST.hpp>
#include <functional>
#include <unordered_map>
#include <vector>

namespace Pop {

  class ConstantsTable {

    struct NodeHasher {
      size_t operator()(const Node *n) const {
        return n->hash();
      }
    };

    struct NodeComparator {
      size_t operator()(const Node *lhs, const Node *rhs) const {
        return lhs->equal(rhs);
      }
    };

    typedef std::unordered_map< Node *, int, NodeHasher, NodeComparator >
        NodeIdMap;

  public:
    ConstantsTable();
    ~ConstantsTable();
    int intern(Node *n);
    Node *node(int id);

  private:
    int count;
    NodeIdMap node_to_id;
    std::vector< Node * > node_vec;
  };

  // namespace Pop
}

#endif // POP_CONSTANTS_TABLE_HPP
