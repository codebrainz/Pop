#ifndef POP_CONSTANT_HPP
#define POP_CONSTANT_HPP

#include <Pop/ByteCodeFile.hpp>
#include <Pop/TypeCode.hpp>
#include <istream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

namespace Pop {

  struct Constant {
    TC type;

    union Value {
      bool as_bool;
      long long int as_int;
      long double as_float;
      std::string *as_str;
    } u;

    static Constant new_nil();
    static Constant new_bool(bool value = false);
    static Constant new_int(long long int value = 0);
    static Constant new_float(long double value = 0.0);
    static Constant new_string(const std::string &s = std::string());
    static Constant new_symbol(const std::string &s);

    Constant() : Constant(TC::NIL) {
    }
    Constant(const Constant &other);
    Constant(Constant &&other);
    Constant &operator=(const Constant &other);
    Constant &operator=(Constant &&other);
    explicit Constant(TC ty) : type(ty), u{ 0 } {
    }

    ~Constant();

    void swap(Constant &other);

    bool operator==(const Constant &other) const;
    bool operator!=(const Constant &other) const {
      return !operator==(other);
    }

    std::string to_string() const;
    size_t hash() const;
    void serialize(ByteCodeFile &bcf) const;
    void serialize(std::ostream &os) const;
    static Constant deserialize(ByteCodeFile &bcf);
    static Constant deserialize(std::istream &is);

    friend std::ostream &operator<<(std::ostream &os, const Constant &c) {
      os << c.to_string();
      return os;
    }
  };

  typedef std::unique_ptr< Constant > ConstantPtr;
  typedef std::vector< ConstantPtr > ConstantList;

  // namespace Pop
}

namespace std {
  template <>
  struct hash< Pop::Constant > {
    size_t operator()(const Pop::Constant &c) const {
      return c.hash();
    }
  };
}

#endif // POP_CONSTANT_HPP
