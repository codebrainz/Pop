#ifndef POP_CONSTANTS_TABLE_HPP
#define POP_CONSTANTS_TABLE_HPP

#include <Pop/AST.hpp>
#include <functional>
#include <unordered_map>
#include <vector>

namespace Pop {

  class ConstantsTable {

    typedef std::vector< Node * > NodeVec;

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

    size_t size() const {
      return node_vec.size();
    }

    NodeVec::iterator begin() {
      return node_vec.begin();
    }
    NodeVec::iterator end() {
      return node_vec.end();
    }
    NodeVec::const_iterator begin() const {
      return node_vec.begin();
    }
    NodeVec::const_iterator end() const {
      return node_vec.end();
    }

  private:
    int count;
    NodeIdMap node_to_id;
    NodeVec node_vec;
  };

  // namespace Pop
}

#endif // POP_CONSTANTS_TABLE_HPP
