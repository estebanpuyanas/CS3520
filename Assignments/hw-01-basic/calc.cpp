#include <iostream>
#include <string>
#include <iomanip> // For setprecision
#include <cmath>   // For sin and cos
#include <sstream> // For stringstream

using namespace std;

int main() {
    const string prompt_function = "Enter a function name:";
    const string prompt_value = "Enter a value:";
    const string error_message = "Invalid input.";

    // Variables to store user input.
    double X;
    string W;

    // Prompt for function input.
    cout << prompt_function << endl;
    string input_line;
    getline(cin, input_line);  // Read the full line.

    // Use stringstream to parse the input line.
    stringstream ss(input_line);
    ss >> W;  // Extract the first word.

    // Check if the function is valid.
    if (W != "sin" && W != "cos") {
        cout << error_message << endl;
        return 255;
    }

    // Always print the "Enter a value:" message.
    cout << prompt_value << endl;

    // Check if there's already a value in the same input.
    if (ss >> X) {
        // A value was provided; no need for further input.
    } else {
        // No value provided; prompt for the value.
        string input_value;
        getline(cin, input_value);

        stringstream value_ss(input_value);
        if (!(value_ss >> X)) {
            cout << error_message << endl;
            return 255;
        }
    }

    // Calculate the result.
    double result = (W == "sin") ? sin(X) : cos(X);

    // Output with at most three digits of precision.
    cout << fixed << setprecision(3) << result << endl;

    return 0;
}