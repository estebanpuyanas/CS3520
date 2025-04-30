#include <iostream>
using namespace std;

int
main()
{

  // Variable to track sum. 
  int sum = 0; 

  // Varuable for user input.
  int num;

// Keep reading input until end. 
  while(cin >> num) {
    sum += num; // Update sum.
  } 
  cout << sum << endl; // Print sum.

  return 0;
  }