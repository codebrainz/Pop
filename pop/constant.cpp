#ifdef HAVE_CONFIG_H
#include <pop/config.h>
#endif

#include <pop/constant.hpp>
#include <pop/serialization.hpp>
#include <pop/utils.hpp>

#include <cstring>
#include <sstream>

namespace Pop {

  Constant Constant::new_nil() {
    return Constant(TC::NIL);
  }

  Constant Constant::new_bool(bool value) {
    Constant tmp(TC::BLN);
    tmp.u.as_bool = value;
    return tmp;
  }

  Constant Constant::new_int(long long int value) {
    Constant tmp(TC::INT);
    tmp.u.as_int = value;
    return tmp;
  }

  Constant Constant::new_float(long double value) {
    Constant tmp(TC::FLT);
    tmp.u.as_float = value;
    return tmp;
  }

  Constant Constant::new_string(const std::string &s) {
    Constant tmp(TC::STR);
    tmp.u.as_str = new std::string(s);
    return tmp;
  }

  Constant Constant::new_symbol(const std::string &s) {
    Constant tmp(TC::SYM);
    tmp.u.as_str = new std::string(s);
    return tmp;
  }

  Constant::Constant(const Constant &other) : type(other.type) {
    switch (type) {
      case TC::NIL:
        break;
      case TC::BLN:
        u.as_bool = other.u.as_bool;
        break;
      case TC::INT:
        u.as_int = other.u.as_int;
        break;
      case TC::FLT:
        u.as_float = other.u.as_float;
        break;
      case TC::STR:
      case TC::SYM:
        u.as_str = new std::string(other.u.as_str ? *other.u.as_str : "");
        break;
    }
  }

  Constant::Constant(Constant &&other) : Constant() {
    swap(other);
  }

  Constant &Constant::operator=(const Constant &other) {
    Constant tmp(other);
    swap(tmp);
    return *this;
  }

  Constant &Constant::operator=(Constant &&other) {
    swap(other);
    return *this;
  }

  Constant::~Constant() {
    if (type == TC::STR || type == TC::SYM)
      delete u.as_str;
  }

  void Constant::swap(Constant &other) {
    std::swap(type, other.type);
    Value tmp;
    std::memcpy(&tmp, &u, sizeof(Value));
    std::memcpy(&u, &other.u, sizeof(Value));
    std::memcpy(&other.u, &tmp, sizeof(Value));
  }

  bool Constant::operator==(const Constant &other) const {
    if (type != other.type)
      return false;
    switch (type) {
      case TC::NIL:
        return true;
      case TC::BLN:
        return (u.as_bool == other.u.as_bool);
      case TC::INT:
        return (u.as_int == other.u.as_int);
      case TC::FLT:
        return (u.as_float == other.u.as_float);
      case TC::STR:
      case TC::SYM:
        if (u.as_str && other.u.as_str)
          return (*u.as_str == *other.u.as_str);
        else if (!u.as_str && !other.u.as_str)
          return true;
        return false;
    }
    return false;
  }

  std::string Constant::to_string() const {
    std::stringstream ss;
    switch (type) {
      case TC::NIL:
        ss << "null";
        break;
      case TC::BLN:
        ss << (u.as_bool ? "true" : "false");
        break;
      case TC::INT:
        ss << u.as_int;
        break;
      case TC::FLT:
        ss << u.as_float;
        break;
      case TC::STR:
      case TC::SYM:
        if (u.as_str)
          ss << *u.as_str;
        break;
    }
    return ss.str();
  }

  size_t Constant::hash() const {
    size_t seed =
        std::hash< std::uint8_t >()(static_cast< std::uint8_t >(type));
    switch (type) {
      case TC::NIL:
        break;
      case TC::BLN:
        hash_combine(seed, u.as_bool);
        break;
      case TC::INT:
        hash_combine(seed, u.as_int);
        break;
      case TC::FLT:
        hash_combine(seed, u.as_float);
        break;
      case TC::STR:
      case TC::SYM:
        if (u.as_str)
          hash_combine(seed, *u.as_str);
        break;
    }
    return seed;
  }

  void Constant::serialize(ByteCodeFile &bcf) const {
    bcf.set_u8(static_cast< U8 >(type));
    switch (type) {
      case TC::NIL:
        break;
      case TC::BLN:
        bcf.set_u8(!!u.as_bool);
        break;
      case TC::INT:
        bcf.set_u64(u.as_int);
        break;
      case TC::FLT:
        bcf.set_real(u.as_float);
        break;
      case TC::STR:
      case TC::SYM:
        bcf.set_string(*u.as_str);
        break;
    }
  }

  void Constant::serialize(std::ostream &os) const {
    serialize8(os, type);
    switch (type) {
      case TC::NIL:
        break;
      case TC::BLN:
        serialize8(os, u.as_bool);
        break;
      case TC::INT:
        serialize64(os, u.as_int);
        break;
      case TC::FLT:
        serialize_raw(os, u.as_float);
        break;
      case TC::STR:
      case TC::SYM:
        serialize_str(os, *u.as_str);
        break;
    }
  }

  Constant Constant::deserialize(ByteCodeFile &bcf) {
    switch (static_cast< TC >(bcf.get_u8())) {
      case TC::NIL:
        return Constant::new_nil();
      case TC::BLN:
        return Constant::new_bool(bcf.get_u8());
      case TC::INT:
        return Constant::new_int(bcf.get_u64());
      case TC::FLT:
        return Constant::new_float(bcf.get_real());
      case TC::STR:
        return Constant::new_string(bcf.get_string());
      case TC::SYM:
        return Constant::new_symbol(bcf.get_string());
    }
    return Constant();
  }

  Constant Constant::deserialize(std::istream &is) {
    switch (static_cast< TC >(deserialize8(is))) {
      case TC::NIL:
        return Constant::new_nil();
      case TC::BLN:
        return Constant::new_bool(static_cast< bool >(deserialize8(is)));
      case TC::INT:
        return Constant::new_int(
            static_cast< long long int >(deserialize64(is)));
      case TC::FLT:
        return Constant::new_float(deserialize_raw< long double >(is));
      case TC::STR:
        return Constant::new_string(deserialize_str(is));
      case TC::SYM:
        return Constant::new_symbol(deserialize_str(is));
    }
    return Constant();
  }

  // namespace Pop
}
