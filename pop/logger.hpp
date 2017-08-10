#ifndef POP_LOGGER_HPP
#define POP_LOGGER_HPP

#include <cstdint>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace Pop {

  enum class MessageType : std::uint8_t {
    NOTE,
    INFO,
    DEBUG,
    WARNING,
    CRITICAL,
    ERROR,
    FATAL,
  };

  struct Message {
    MessageType type;
    std::string text;
    const char *file;
    int line, column;
    Message(MessageType ty, std::string text, const char *file, int line,
            int column)
        : type(ty), text(std::move(text)), file(file), line(line),
          column(column) {
    }
  };

  class Logger {
  public:
    int report_messages(std::ostream &out, int max_errors = -1) const;

    template < class... Args >
    void note(Args &&... args) {
      log(MessageType::NOTE, std::forward< Args >(args)...);
    }

    template < class... Args >
    void info(Args &&... args) {
      log(MessageType::INFO, std::forward< Args >(args)...);
    }

    template < class... Args >
    void debug(Args &&... args) {
      log(MessageType::DEBUG, std::forward< Args >(args)...);
    }

    template < class... Args >
    void warning(Args &&... args) {
      log(MessageType::WARNING, std::forward< Args >(args)...);
    }

    template < class... Args >
    void critical(Args &&... args) {
      log(MessageType::CRITICAL, std::forward< Args >(args)...);
    }

    template < class... Args >
    void error(Args &&... args) {
      log(MessageType::ERROR, std::forward< Args >(args)...);
    }

    template < class... Args >
    void fatal(Args &&... args) {
      log(MessageType::FATAL, std::forward< Args >(args)...);
    }

  private:
    std::vector< Message > messages;

    void log_(std::ostream &os, const char *s) {
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
    void log_(std::ostream &os, const char *s, const T &value,
              Args &&... args) {
      while (*s) {
        if (*s == '%') {
          if (*(s + 1) == '%') {
            ++s;
          } else {
            os << value;
            s++;
            log_(os, s, std::forward< Args >(args)...);
            return;
          }
        }
        os << *s++;
      }
    }

    template < class... Args >
    void log(MessageType ty, const char *file, int line, int column,
             const char *s, Args &&... args) {
      std::stringstream ss;
      log_(ss, s, std::forward< Args >(args)...);
      messages.emplace_back(ty, ss.str(), file, line, column);
    }

    template < class... Args >
    void log(MessageType ty, Args &&... args) {
      log(ty, nullptr, -1, -1, std::forward< Args >(args)...);
    }
  };

  // namespace Pop
}

#endif // POP_LOGGER_HPP
