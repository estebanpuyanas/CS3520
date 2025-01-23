/*
Write a program that reads in integers from standard input until any error, then prints the integers in the reverse order they were entered.

Hint: store the integers in a vector<int>; the member functions push_back, pop_back, empty, and size may be useful.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

    // To store numbers as list. 
    vector<int> numberVector;

    // To get specific number (in while) and read from it. 
    int number;
  

    // While being able to get numbers added them to the vector. 
    while(cin >> number) {
        numberVector.push_back(number);
    }

    // While not empty,print in reverse order. 
    while(!numberVector.empty()) {
        cout << numberVector.back() << endl;
        numberVector.pop_back();
    }

    // Sucess. 
    return 0;

}