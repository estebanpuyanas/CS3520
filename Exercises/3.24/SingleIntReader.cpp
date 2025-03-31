/*
Write a program that reads integers from standard input until error, removes all copies of the largest number, and prints all the numbers.

For example, given input "2 4 1 1 4 3" it should print "2 1 1 3".

Hint: use max_element, and remove with vector<T>::erase.
Optional challenge: use a lambda or functor with a different algorithm to find the largest number.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v;
  int input;
  while (cin >> input) {
    v.push_back(input);
  }



  if (v.empty()) {
    return EXIT_SUCCESS;
  }

  auto max = *max_element(v.begin(), v.end());
  v.erase(remove(v.begin(), v.end(), max), v.end());
  for (const auto& i : v) {
    cout << i << " ";
  }
  cout << endl;

}