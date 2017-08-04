#ifndef POP_CONSTANTS_TABLE_HPP
#define POP_CONSTANTS_TABLE_HPP

#include <unordered_map>
#include <vector>

namespace Pop {

  struct Node;

  class ConstantsTable {
  public:
    ConstantsTable();
    ~ConstantsTable();
    int intern(Node *n);
    Node *node(int id);

  private:
    int count;
    std::unordered_map< Node *, int > node_to_id;
    std::vector< Node * > node_vec;
  };

  // namespace Pop
}

#endif // POP_CONSTANTS_TABLE_HPP
