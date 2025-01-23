/*
Write a program that prints the sum of integers on each line of a file.

The program reads from the file “in.txt” line-by-line (stopping on any error reading a line). For each line, it reads the line as a list of integers (stopping processing that line on any error). It writes the sum of the integers on each line to a separate line in standard output.

You’ll need to create a file to read from. A file containing:
1 2
4 5 6 a 7
100

Should display:
3
15
100

Hint: use an ifstream to read from the file, and an istringstream to process each line.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {

    // Use to read the file, avoid hardcoding file name when possible.
    ifstream inputFile("in.txt");

    // If error with the input file, print error message and return non-zero code. 
    if(!inputFile) {
        cout << "Error occurred while opening the file" << endl;
        return 255;
    }

    // Create a string to store and process each line from the input. 
    string line; 

    // While still able form getting lines from the input file:
    while(getline(inputFile, line)) {

        // Use stringstream to process the given line.
        istringstream ss(line);

        // Create variables to sum and add to value. 
        int sum = 0;
        int value; 

        // While being able to get values from the stringstream, add to sum. 
        while(ss >> value) {
            sum += value;
        }

        // Print sum.
        cout << sum << endl;
    }

    // Success. 
    return 0;
}