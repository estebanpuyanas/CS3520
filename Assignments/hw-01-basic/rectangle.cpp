#include <iostream>
#include <string>
using namespace std;

/**
 * Program constraints:
 * 
 * 1. User must input ints w,h where 1 <= w,h < 21. Amy other input leads to error.
 * Print rectangle that is made of X with w,h as width and height.
 * 
 * The program follows the same control flow as fizzbuzz program:
 * 
 * 1. Create variables to store user input. 
 * 2. Prompt first user input followed by validation check.
 * 3. Repeat #2 for second user input.
 * 4. Execute main printing logic.
 */

int
main()
{
  const string prompt_width = "Enter width:";
  const string prompt_height = "Enter height:";
  const string error_message = "Invalid input.";

  int w, h;

  cout << prompt_width << endl;

  if(!(cin >> w) || w <= 0 || w >= 21) {
    cout << error_message << endl;
    return 255; 
  }

  cout << prompt_height << endl;

  if(!(cin >> h) || h <= 0 || h >= 21) {
    cout << error_message << endl;
    return 255; 
  }

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cout << "X";
    }
    cout << endl;
  }

  return 0;
  }
