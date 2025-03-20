/*
Write a program that prompts the user to enter the name of a number.  If the number is a key in the provided map, the program prints out the integer value for that number.
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  const map<string, int> word_to_number = {
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5}
  };

    string input;
    while (cin >> input) {
        if (word_to_number.find(input) != word_to_number.end()) {
            cout << word_to_number.at(input) << endl;
        }
    }
}