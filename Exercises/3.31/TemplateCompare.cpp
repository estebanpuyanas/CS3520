/*
Write a function template named compare that takes two arguments of any (potentially different) types and returns an int.  The return value is <0 if the first argument is less than the second, >0 if the second argument is less than the first, and 0 otherwise.

Optional challenge: Overload the function so that it works for two (const and non-const) C-strings.
(Hint: use strcmp, and check for a different return value to confirm.)
*/

#include <iostream>
#include <cstring>
using namespace std;

// TODO
int compare(int a, int b) {
  return (a < b) ? -1 : (a > b) ? 1 : 0;
}

string compare(char *a, char *b) {
  return (a < b) ? "<0" : (a > b) ? ">0" : "0";
}

int main() {
  cout << compare(1, 2) << endl; // <0
  cout << compare(1, 2.0) << endl; // <0
  cout << compare(1.0, 2.0) << endl; // <0
  cout << compare(2, 1) << endl; // >0
  cout << compare(2.0, 1) << endl; // >0
  cout << compare(2.0, 1.0) << endl; // >0

  // optional C-string comparison
  char stra[] = "aaa";
  char strc[] = "ccc";
  cout << compare("aaa", "ccc") << endl; // <0
  cout << compare("ccc", stra) << endl; // >0
  cout << compare(stra, "ccc") << endl; // <0
  cout << compare(strc, stra) << endl; // >0
}