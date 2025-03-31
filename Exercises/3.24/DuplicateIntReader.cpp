/*
Write a program that reads integers from stdin until an error.  It then prints the integers entered (including duplicates) in increasing order. Use a vector and algorithm(s).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> numbers;
    int input;
    while (cin >> input) {
        numbers.push_back(input);
    }
}