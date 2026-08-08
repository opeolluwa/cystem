#include <string>

namespace argparser {
bool validate_command(const std::string &command) {
  return (command == "self" || command == "bookmarks" || command == "help" ||
          command == "extensions" || command == "generate");
}
} // namespace argparser
