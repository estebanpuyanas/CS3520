/*
Write a function print_vector that takes one int vector argument and prints all the elements of the vector in order.

Write another function named append_evens that takes two int vectors as arguments and appends all the even numbers in the second vector onto the first in order.

All arguments should be passed by reference (const reference if applicable).

Put the declarations before main and the definitions after main.
*/

#include <iostream>
#include <vector>
using namespace std;

// Declarations (format is: return_type funtion_name(param_list))
void print_vector(const vector<int>& numbers);
void append_evens(vector<int>& evens, const vector<int>& numbers);

int main() {
  vector<int> evens;
  const vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7 };

  print_vector(numbers); // 1 2 3 4 5 6 7
  append_evens(evens, numbers);
  print_vector(evens); // 2 4 6

  return 0;
}

// Function Defintions
void print_vector(const vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << endl;
    }
}

void append_evens(vector<int>& evens, const vector<int>& numbers) {
    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] % 2 == 0) {
            evens.push_back(numbers[i]);
        }
    }
}