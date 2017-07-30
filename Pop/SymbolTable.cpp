#include <Pop/SymbolTable.hpp>
#include <Pop/AST.hpp>

namespace Pop {

  SymbolTable::SymbolTable(SymbolTable *parent, Node *owner)
      : sym_count(0), parent(parent), owner(owner) {
  }

  SymbolTable::~SymbolTable() {
    for (auto pair : symbols)
      delete pair.second;
  }

  bool SymbolTable::define(const std::string &name, Node *node) {
    if (is_defined(name, false))
      return false;
    symbols.emplace(name, new SymbolEntry(next_id(), name, node));
    return true;
  }

  SymbolEntry *SymbolTable::lookup(const std::string &name, bool rec) {
    auto found = symbols.find(name);
    if (found != symbols.end())
      return found->second;
    else if (rec && parent)
      return parent->lookup(name, rec);
    return nullptr;
  }

  int SymbolTable::next_id() {
    int id = sym_count;
    sym_count++;
    return id;
  }

  // namespace Pop
}
