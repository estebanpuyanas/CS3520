
/*
Write a program that tries to read a double from standard input, and if successful, prints "number: " followed by the number. If a number can't be read, it tries to read a word, and if successful, prints "word: " followed by the word.

For example, entering "5.5" prints "number: 5.5" and entering "five" prints "word: five". To simplify error handling, you only need to check if the stream evaluates to true or not.

Optional challenge: always print numbers with with two decimal digits.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

    double number;
    string word; 

    cout << "Enter a double or a word:" << endl;

    if(cin >> number) {
        cout << "The input number is:" << number << endl;
    } else {
        cin.clear();
        getline(cin, word);
        cout << "The input word is:" << word << endl;
    }

    return 0;
}