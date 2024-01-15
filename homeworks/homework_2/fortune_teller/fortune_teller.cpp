#include <array>
#include <iostream>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace {
const std::map<string, string> kTimeToNoun = {
    {"spring", "STL guru"},
    {"summer", "C++ expert"},
    {"autumn", "coding beast"},
    {"winter", "software design hero"}};
const std::array<string, 3UL> kEndings{"eats UB for breakfast",
                                       "finds errors quicker than the compiler",
                                       "is not afraid of C++ error messages"};
} // namespace

int main() {
  cout << "Welcome to the fortune teller program!" << endl
       << "Please enter your name:" << endl;
  string user_name{};
  cin >> user_name;

  string time_of_year{};
  while (!kTimeToNoun.count(time_of_year)) {
    cout << "Please enter the time of year when you were born:" << endl
         << "(pick from 'spring', 'summer', 'autumn', 'winter')" << endl;
    cin >> time_of_year;
  }

  std::vector<string> adjectives(2, "");
  cout << "Please enter an adjective:" << endl;
  cin >> adjectives[0];
  cout << "Please enter another adjective:" << endl;
  cin >> adjectives[1];

  cout << user_name << ", the "
       << adjectives[user_name.size() % adjectives.size()] << " "
       << kTimeToNoun.at(time_of_year) << " that "
       << kEndings.at(user_name.size() % kEndings.size()) << endl;
}