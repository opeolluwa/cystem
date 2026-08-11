#include <optional>
#include <vector>
namespace commander {
void init_command(const std::optional<std::string> &name,
                  const std::optional<std::string> &path);
const std::vector<std::string> DIRECTORIES{"src", "include", "external",
                                           "assets"};
const std::vector<std::string> FILES{"CMakeList.txt"};
}; // namespace commander
