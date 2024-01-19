#include <no_strings_attached/string_split.h>

#include <iostream>

using std::cout;
using std::endl;

int main() {
  cout << "Example program that splits strings." << endl
       << "Please enter a string:" << endl;
  std::string input_string;
  std::getline(std::cin, input_string);
  cout << "Your split string: ";
  const auto result = no_strings_attached::Split(input_string, " ");
  for (const auto& elem : result) {
    cout << "'" << elem << "'";
    if (&elem != &result.back()) { cout << " "; }
  }
  cout << endl;
  return 0;
}