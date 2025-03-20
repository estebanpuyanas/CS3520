/*
Write a program that reads integers from stdin until an error.  It then prints the unique integers entered (i.e. no duplicates) in increasing order.  Do not sort the integers directly.

Hint: use a set.
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> unique_ints;
    int input;
    while (cin >> input) {
        unique_ints.insert(input);
    }
    
    for (int i : unique_ints) {
        cout << i << " ";
    }
    cout << endl;
}