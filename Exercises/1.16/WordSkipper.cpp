/*
Write a program that reads in lines of text (i.e. using getline) from standard input, and if successful, prints every other word from each line.

For example, given input:
one two three
v w x y z

Output is:
one three
v x z

Hint: use a stringstream to separate the words in each line.
Optional challenge: (over)write the result of the dice rolls to a file name "dice.txt" instead of the console.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {

    string inputLine;
    stringstream ss;

    cout << "Enter a line of text:" << endl;

    while(getline(cin, inputLine)) {
        if(ss << inputLine) {
            string word;
            int count = 0;
            while(ss >> word) {
                if(count % 2 == 0) {
                    cout << word << " ";
                }
                count++;
            }
            cout << endl;
        }
    }
    return 0;
}