#ifndef POP_BYTECODE_FILE_HPP
#define POP_BYTECODE_FILE_HPP

#include <Pop/CRC32.hpp>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace Pop {

  typedef std::uint8_t U8;
  typedef std::int16_t I16;
  typedef std::uint16_t U16;
  typedef std::uint32_t U32;
  typedef std::int64_t I64;
  typedef std::uint64_t U64;
  typedef float F32;
  typedef double F64;
  typedef long double REAL;

  class ByteCodeFile {
  public:
    enum class Origin { START, CURRENT, END };

    ByteCodeFile() : off(0) {
    }

    bool save(const std::string &fn) {
      std::ofstream f(fn, std::ios_base::binary);
      return save(f);
    }

    bool save(std::ostream &os) {
      os.write(reinterpret_cast< const char * >(buf.data()), buf.size());
      return os.good();
    }

    bool load(const std::string &fn) {
      std::ifstream f(fn, std::ios_base::binary);
      return load(f);
    }

    bool load(std::istream &is) {
      buf.clear();
      is.seekg(0, std::ios_base::end);
      buf.resize(is.tellg(), 0);
      is.seekg(0, std::ios_base::beg);
      is.read(reinterpret_cast< char * >(buf.data()), buf.size());
      return is.good();
    }

    void reserve(U32 size) {
      buf.reserve(size);
    }

    void resize(U32 size, U8 fill = 0) {
      buf.resize(size, fill);
    }

    void seek(I64 offset, Origin origin = Origin::START) {
      switch (origin) {
        case Origin::START:
          assert(offset >= 0);
          off = offset;
          break;
        case Origin::CURRENT:
          off += offset;
          break;
        case Origin::END:
          assert(offset >= 0);
          off = buf.size() - offset;
          break;
      }
      assert(off <= buf.size());
    }

    U32 tell() const {
      return off;
    }

    void set_u8(U8 v) {
      if (off < buf.size()) {
        buf[off++] = v;
      } else {
        buf.push_back(v);
        off++;
      }
    }

    void insert_u8(U8 v) {
      buf.insert(buf.begin() + off, v);
      off++;
    }

    U8 get_u8() {
      if (off > 0 && off <= buf.size())
        return buf[--off];
      throw std::runtime_error("invalid offset in ByteCodeFile");
      return 0;
    }

    U8 peek_u8() {
      auto old_off = off;
      U8 v = get_u8();
      off = old_off;
      return v;
    }

    void set_u32(U32 v) {
      set_u8(v >> 24);
      set_u8(v >> 16);
      set_u8(v >> 8);
      set_u8(v);
    }

    void insert_u32(U32 v) {
      insert_u8(v >> 24);
      insert_u8(v >> 16);
      insert_u8(v >> 8);
      insert_u8(v);
    }

    U32 get_u32() {
      U32 v = 0;
      v |= U32(get_u8()) << 24;
      v |= U32(get_u8()) << 16;
      v |= U32(get_u8()) << 8;
      v |= U32(get_u8());
      return v;
    }

    U32 peek_u32() {
      auto old_off = off;
      U32 v = get_u32();
      off = old_off;
      return v;
    }

    void set_u64(U64 v) {
      set_u8(v >> 56);
      set_u8(v >> 48);
      set_u8(v >> 40);
      set_u8(v >> 32);
      set_u8(v >> 24);
      set_u8(v >> 16);
      set_u8(v >> 8);
      set_u8(v);
    }

    void insert_u64(U64 v) {
      insert_u8(v >> 56);
      insert_u8(v >> 48);
      insert_u8(v >> 40);
      insert_u8(v >> 32);
      insert_u8(v >> 24);
      insert_u8(v >> 16);
      insert_u8(v >> 8);
      insert_u8(v);
    }

    U64 get_u64() {
      U64 v = 0;
      v |= U64(get_u8()) << 56;
      v |= U64(get_u8()) << 48;
      v |= U64(get_u8()) << 40;
      v |= U64(get_u8()) << 32;
      v |= U64(get_u8()) << 24;
      v |= U64(get_u8()) << 16;
      v |= U64(get_u8()) << 8;
      v |= U64(get_u8());
      return v;
    }

    U64 peek_u64() {
      auto old_off = off;
      U64 v = get_u64();
      off = old_off;
      return v;
    }

    template < class T >
    void set_raw(T v) {
      union {
        T v;
        U8 b[sizeof(T)];
      } u = { v };
      set_raw(u.b, sizeof(T));
    }

    void set_raw(const void *p, size_t s) {
      auto b = static_cast< const U8 * >(p);
      for (size_t i = 0; i < s; i++)
        set_u8(b[i]);
    }

    template < class T >
    void insert_raw(T v) {
      union {
        T v;
        U8 b[sizeof(T)];
      } u = { v };
      insert_raw(u.b, sizeof(T));
    }

    void insert_raw(const void *p, size_t s) {
      auto b = static_cast< const U8 * >(p);
      for (size_t i = 0; i < s; i++)
        insert_u8(b[i]);
    }

    template < class T >
    T get_raw() {
      union {
        T v;
        U8 b[sizeof(T)];
      } u;
      get_raw(u.b, sizeof(T));
      return u.v;
    }

    size_t get_raw(void *p, size_t s) {
      auto b = static_cast< U8 * >(p);
      size_t n = 0;
      for (n = 0; n < s; n++)
        b[n] = get_u8();
      return n;
    }

    template < class T >
    T peek_raw() {
      auto old_off = off;
      T v = get_raw< T >();
      off = old_off;
      return v;
    }

    size_t peek_raw(void *p, size_t s) {
      auto old_off = off;
      size_t v = get_raw(p, s);
      off = old_off;
      return v;
    }

    void set_f32(F32 v) {
      set_raw< F32 >(v);
    }

    void insert_f32(F32 v) {
      insert_raw< F32 >(v);
    }

    F32 get_f32() {
      return get_raw< F32 >();
    }

    F32 peek_f32() {
      auto old_off = off;
      F32 v = get_f32();
      off = old_off;
      return v;
    }

    void set_f64(F64 v) {
      set_raw< F64 >(v);
    }

    void insert_f64(F64 v) {
      insert_raw< F64 >(v);
    }

    F64 get_f64() {
      return get_raw< F64 >();
    }

    F64 peek_f64() {
      auto old_off = off;
      F64 v = get_f64();
      off = old_off;
      return v;
    }

    void set_real(REAL v) {
      set_raw< REAL >(v);
    }

    void insert_real(REAL v) {
      insert_raw< REAL >(v);
    }

    REAL get_real() {
      return get_raw< REAL >();
    }

    REAL peek_real() {
      auto old_off = off;
      REAL v = get_real();
      off = old_off;
      return v;
    }

    void set_string(const char *s, I64 len) {
      assert(s);
      if (len < 0)
        len = std::strlen(s);
      set_u32(len);
      for (I64 i = 0; i < len; i++)
        set_u8(s[i]);
    }

    void insert_string(const char *s, I64 len) {
      assert(s);
      if (len < 0)
        len = std::strlen(s);
      insert_u32(len);
      for (I64 i = 0; i < len; i++)
        insert_u8(s[i]);
    }

    U32 get_string(char *s, U64 len) {
      if (!s) {
        auto save_off = off;
        U32 size = get_u32();
        off = save_off;
        return size;
      } else {
        assert(len > 0);
        U32 size = get_u32();
        if (size > len)
          size = len;
        for (U32 i = 0; i < size; i++)
          s[i] = get_u8();
        return size;
      }
    }

    U32 peek_string(char *s, U64 len) {
      auto old_off = off;
      U32 v = get_string(s, len);
      off = old_off;
      return v;
    }

    U32 get_string_length() {
      return get_string(nullptr, 0);
    }

    void set_string(const std::string &s) {
      set_string(s.data(), s.size());
    }

    void insert_string(const std::string &s) {
      set_string(s.data(), s.size());
    }

    std::string get_string() {
      U32 len = get_string_length();
      std::string s(len, '\0');
      get_string(&s[0], s.size());
      return s;
    }

    std::string peek_string() {
      auto old_off = off;
      std::string v = get_string();
      off = old_off;
      return v;
    }

    U32 checksum_range(U32 start, U32 length) {
      if (start + length >= buf.size())
        throw std::runtime_error("checksum position/length out of range");
      return crc32(0, &buf[start], length);
    }

  private:
    std::size_t off;
    std::vector< U8 > buf;
  };

  // namespace Pop
}

#endif // POP_BYTECODE_FILE_HPP
