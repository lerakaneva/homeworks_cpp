#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

int main() {
  cout << "Welcome to the GUESSING GAME!" << endl
       << "I will generate a number and you will guess it!" << endl
       << "Please provide the smallest number:" << endl;
  int min_number{0};
  cin >> min_number;
  cout << "Please provide the largest number:" << endl;
  int max_number{0};
  cin >> max_number;

  std::random_device random_device;
  std::mt19937 random_engine{random_device()};
  std::uniform_int_distribution distribution{min_number, max_number};
  const int generated_number = distribution(random_engine);

  cout << "I've generated a number. Try to guess it!" << endl;
  int guess = 0;
  int guess_number = 0;
  do {
    cout << "Please provide the next guess: ";
    cin >> guess;
    ++guess_number;
    if (guess < generated_number) {
      cout << "Your number is too small. Try again!" << endl;
    } else if (guess > generated_number) {
      cout << "Your number is too big. Try again!" << endl;
    }
  } while (guess != generated_number);
  cout << "You've done it! You guessed the number " << generated_number
       << " in " << guess_number << " guesses!" << endl;
  return 0;
}