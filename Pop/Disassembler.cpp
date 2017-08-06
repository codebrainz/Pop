#ifdef HAVE_CONFIG_H
#include <Pop/Config.h>
#endif

#include <Pop/Disassembler.hpp>
#include <Pop/Serialization.hpp>
#include <Pop/TypeCode.hpp>
#include <cassert>
#include <string>
#include <vector>

namespace Pop {

  struct Constant {
    TC type;
    union {
      bool bln;
      long long int itg;
      long double flt;
      std::string *str;
    };
    Constant(const Constant &) = delete;
    Constant &operator=(const Constant &) = delete;
    explicit Constant(TC ty) : type(ty), itg(0) {
    }
    template < class T >
    Constant(TC ty, T val) : Constant(ty) {
      switch (type) {
        case TC::NIL:
          break;
        case TC::BLN:
          bln = val;
          break;
        case TC::INT:
          itg = val;
          break;
        case TC::FLT:
          flt = val;
          break;
        case TC::STR:
          str = new std::string(val);
          break;
        case TC::SYM:
          str = new std::string(val);
          break;
      }
    }
    ~Constant() {
      if (type == TC::STR || type == TC::SYM)
        delete str;
    }
  };

  static bool check_magic_bytes(std::istream &is) {
    static const std::string magic = POP_MAGIC_BYTES;
    std::string test_magic;
    test_magic.reserve(magic.size());
    for (size_t i = 0; i < magic.size(); i++)
      test_magic += static_cast< char >(deserialize8(is));
    return (magic == test_magic);
  }

  bool disassemble(std::istream &is, std::ostream &os, std::ostream &err) {
    if (!check_magic_bytes(is)) {
      err << "error: invalid magic bytes" << std::endl;
      return false;
    }

    size_t bytecode_offset = deserialize32(is);
    size_t num_constants = deserialize32(is);

    std::vector< Constant > constants;
    for (size_t i = 0; i < num_constants; i++) {
#if 0
      switch (auto tc = static_cast< TC >(deserialize8(is))) {
        case TC::NIL:
          constants.emplace_back(tc);
          break;
        case TC::BLN:
          constants.emplace_back(tc, static_cast< bool >(deserialize8(is)));
          break;
        case TC::INT:
          constants.emplace_back(
              tc, static_cast< long long int >(deserialize64(is)));
          break;
        case TC::FLT:
          constants.emplace_back(tc, deserialize_raw< long double >(is));
          break;
        case TC::STR:
          constants.emplace_back(tc, deserialize_str(is));
          break;
        case TC::SYM:
          constants.emplace_back(tc, deserialize_str(is));
          break;
      }
#endif
    }

    if (is.tellg() != bytecode_offset) {
      err << "error: constants table is corrupted" << std::endl;
      return false;
    }

    // while (!is.eof()) {
    // auto code = static_cast< OpCode >(deserialize8(is));
    //(void)code;
    //}

    (void)os;
    return false;
  }

  // namespace Pop
}
