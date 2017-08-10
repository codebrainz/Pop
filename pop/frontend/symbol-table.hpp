#if !defined(POP_INSIDE_MAIN_HEADER_) && !defined(POP_LIB_COMPILATION_)
#error "Do not include this header directly, use '<pop/pop.hpp>' instead."
#endif

#ifndef POP_SYMBOLTABLE_HPP
#define POP_SYMBOLTABLE_HPP

#include <cassert>
#include <unordered_map>

namespace Pop {

  struct Node;

  struct SymbolEntry {
    int id;
    std::string name;
    Node *node;
    SymbolEntry(int id, const std::string &name, Node *node)
        : id(id), name(name), node(node) {
      assert(id >= 0);
      assert(!name.empty());
      assert(node);
    }
  };

  class SymbolTable {
  public:
    int sym_count;
    SymbolTable *parent;
    Node *owner;
    SymbolTable(SymbolTable *parent = nullptr, Node *owner = nullptr);
    ~SymbolTable();
    bool define(const std::string &name, Node *node);
    SymbolEntry *lookup(const std::string &name, bool rec = true);
    bool is_defined(const std::string &name, bool rec = true) {
      return (lookup(name, rec) != nullptr);
    }

  private:
    std::unordered_map< std::string, SymbolEntry * > symbols;
    int next_id();
  };

  // namespace Pop
}

#endif // POP_SYMBOLTABLE_HPP
