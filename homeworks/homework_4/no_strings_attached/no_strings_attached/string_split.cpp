#include "string_split.h"

#include <stdexcept>

namespace {
std::vector<std::string> SplitWithLimit(const std::string &str,
                                        const std::string &delimiter,
                                        size_t limit = 0) {
  std::vector<std::string> result;
  size_t start{0};

  while (start <= str.size()) {
    if (start == str.size()) {
      result.push_back("");
      break;
    }
    const size_t finish = str.find(delimiter, start);

    if (finish == std::string::npos) { // delimeter not found
      result.push_back(str.substr(start, str.size() - start));
      break;
    }

    result.push_back(str.substr(start, finish - start));
    start = finish + delimiter.size();
    if (limit > 0 && result.size() == limit) {
      break;
    }
  }

  return result;
}
} // namespace

namespace no_strings_attached {
std::vector<std::string> Split(const std::string &str,
                               const std::string &delimiter) {
  return SplitWithLimit(str, delimiter);
}

std::vector<std::string> Split(const std::string &str,
                               const std::string &delimiter,
                               int number_of_chunks_to_keep) {
  if (number_of_chunks_to_keep < 0) {
    throw std::out_of_range("Trying to keep negative number of elements");
  }
  if (!number_of_chunks_to_keep) {
    return {};
  }
  return SplitWithLimit(str, delimiter, number_of_chunks_to_keep);
}
} // namespace no_strings_attached