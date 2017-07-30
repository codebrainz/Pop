#include <Pop/Logger.hpp>

namespace Pop {

  static const char *message_type_name(MessageType ty) {
    switch (ty) {
      case MessageType::NOTE:
        return "note";
      case MessageType::INFO:
        return "info";
      case MessageType::DEBUG:
        return "debug";
      case MessageType::WARNING:
        return "warning";
      case MessageType::CRITICAL:
        return "critical";
      case MessageType::ERROR:
        return "error";
      case MessageType::FATAL:
        return "fatal";
    }
    return "unknown";
  }

  void Logger::report_messages(std::ostream &out, int max_errors) const {
    int count = 0;
    for (const auto &msg : messages) {
      bool have_loc = false;
      if (msg.file) {
        out << msg.file << ':';
        have_loc = true;
      }
      if (msg.line >= 0) {
        out << msg.line << ':';
        if (msg.column >= 0)
          out << msg.column << ':';
        have_loc = true;
      }
      if (have_loc)
        out << ' ';
      out << message_type_name(msg.type) << ": " << msg.text << '\n';
      count++;
      if (count == max_errors)
        break;
    }
  }

  // namespace Pop
}
