#include <iostream>
#include <string>
using namespace std;

int
main()
{
  const string prompt_fizz = "Enter the fizz number:";
  const string prompt_buzz = "Enter the buzz number:";
  const string error_message = "Invalid input.";

// Create int variables to store numbers. 
  int fizz;
  int buzz;

  // Output to prompt for input.
  cout << prompt_fizz << endl;

// Check if input is valid: First check is for input type (only int), second is for int size. 
  if(!(cin >> fizz) || fizz <= 0) {
    cout << error_message << endl;
    return 255; // Error code is 255 (?) according to reference implementation test runs.
  }


  // Repeat process for buzz number.
  cout << prompt_buzz << endl;
  
  if(!(cin >> buzz) || buzz <= 0) {
     cout << error_message << endl;
    return 255;
  }

  // Main FizzBuzz logic.
  for(int i = 1; i <= 20; i++) {
    if(i % fizz == 0 && i % buzz == 0) {
      cout << "FizzBuzz" << endl;
    } else if(i % fizz == 0) {
      cout << "Fizz" << endl;
    } else if(i % buzz == 0) {
      cout << "Buzz" << endl;
    } else {
      cout << i << endl;
    }
  }
  return 0; // If success, return 0. 
}