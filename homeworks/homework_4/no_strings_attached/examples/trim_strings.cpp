#include <no_strings_attached/string_trim.h>

#include <iostream>

using std::cout;
using std::endl;

int main() {
  cout << "Example program that trims strings." << endl
       << "Please enter a string:" << endl;
  std::string input_string;
  std::getline(std::cin, input_string);
  cout << "Your trimmed string: "
       << "'" << no_strings_attached::Trim(input_string) << "'" << endl;
  return 0;
}