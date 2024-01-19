#include "string_trim.h"

namespace no_strings_attached {

std::string Trim(const std::string &str, char char_to_trim, Side side) {
  size_t begin = 0;
  size_t end = str.size();
  if (side == Side::kLeft || side == Side::kBoth) {
    const size_t first_not_of = str.find_first_not_of(char_to_trim);
    begin = (first_not_of == std::string::npos) ? str.size() : first_not_of;
  }
  if (side == Side::kRight || side == Side::kBoth) {
    const size_t last_not_of = str.find_last_not_of(char_to_trim);
    end = (last_not_of == std::string::npos) ? begin : last_not_of + 1;
  }
  return str.substr(begin, end - begin);
}

std::string Trim(const std::string &str) { return Trim(str, ' ', Side::kBoth); }

} // namespace no_strings_attached