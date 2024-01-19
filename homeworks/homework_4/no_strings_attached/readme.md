#This tool will help you to split or strim strings

#How to build:
cmake -S . -B build
cmake --build build -j 12

#Usage example:
1
echo "hello world" | ./build/examples/split_strings
Example program that splits strings.
Please enter a string:
Your split string: 'hello' 'world'
2
echo "  hello world  " | ./build/examples/trim_strings
Example program that trims strings.
Please enter a string:
Your trimmed string: 'hello world'

#Library:
To split and trim strings in your project you can use the following libraries:
- `string_split`
- `string_trim`
Header files:
- `#include <no_strings_attached/string_split.h>`
- `#include <no_strings_attached/string_trim.h>`

Use functions
- `string_split`
  - A function to split a given string into a vector of strings from the right given a delimiter:
    ```cpp
    std::vector<std::string> Split(const std::string& str, const std::string& delimiter);
    ```
    Examples:
      - `no_strings_attached::Split("hello world", " ")` ➡️ `std::vector{"hello", "world"}`
      - `no_strings_attached::Split("aaabaaba", "aa")` ➡️ `std::vector{"", "ab", "ba"}`
  - Function that allows keeping only part of the output:
    ```cpp
    std::vector<std::string> Split(const std::string& str, const std::string& delimiter, int number_of_chunks_to_keep);
    ```
    Examples:
      - `no_strings_attached::Split("hello world", " ", 1)` ➡️ `std::vector{"hello"}`
      - `no_strings_attached::Split("hello world", " ", 2)` ➡️ `std::vector{"hello", "world"}`
      - `no_strings_attached::Split("aaabaaba", "aa", 2)` ➡️ `std::vector{"", "ab"}`
- `string_trim`:
  - A function that allows trimming strings from a given direction:
    ```cpp
    std::string Trim(const std::string& str, char char_to_trim, Side side);
    ```
    Examples:
      - `no_strings_attached::Trim("  hello ", ' ', Side::kLeft)` ➡️ `std::string{"hello "}`
      - `no_strings_attached::Trim("  hello ", ' ', Side::kRight)` ➡️ `std::string{"  hello"}`
      - `no_strings_attached::Trim("  hello ", ' ', Side::kBoth)` ➡️ `std::string{"hello"}`
      - `no_strings_attached::Trim("hello", 'h', Side::kLeft)` ➡️ `std::string{"ello"}`
  - Function function that allows trimming spaces from both sides:
    ```cpp
    std::string Trim(const std::string& str);
    ```
    Examples:
      - `no_strings_attached::Trim("  hello ")` ➡️ `std::string{"hello"}`