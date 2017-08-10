#ifndef POP_FORMATTER_HPP
#define POP_FORMATTER_HPP

#include <ostream>
#include <stdexcept>
#include <string>

namespace Pop {

  class Formatter {
  public:
    Formatter(std::ostream &os, std::string indent_token = "\t")
        : os(os), indent_level(0), indent_token(std::move(indent_token)),
          indent_string("") {
    }

    void indent() {
      indent_level++;
      update_indent_string();
    }

    void unindent() {
      indent_level--;
      update_indent_string();
    }

    void write(const char *s) {
      while (*s) {
        if (*s == '%') {
          if (*(s + 1) == '%') {
            ++s;
          } else {
            throw std::runtime_error("invalid format string");
          }
        }
        os << *s++;
      }
    }

    template < class T, class... Args >
    void write(const char *s, const T &value, Args &&... args) {
      while (*s) {
        if (*s == '%') {
          if (*(s + 1) == '%') {
            ++s;
          } else {
            os << value;
            s++;
            write(s, std::forward< Args >(args)...);
            return;
          }
        }
        os << *s++;
      }
    }

    template < class... Args >
    void writeln(Args &&... args) {
      write(std::forward< Args >(args)...);
      os << '\n';
    }

    template < class... Args >
    void iwrite(Args &&... args) {
      os << indent_string;
      write(std::forward< Args >(args)...);
    }

    template < class... Args >
    void iwriteln(Args &&... args) {
      iwrite(std::forward< Args >(args)...);
      os << '\n';
    }

  private:
    std::ostream &os;
    int indent_level;
    const std::string indent_token;
    std::string indent_string;

    void update_indent_string() {
      indent_string.clear();
      for (int i = 0; i < indent_level; i++)
        indent_string += indent_token;
    }
  };

  // namespace Pop
}

#endif // POP_FORMATTER_HPP
