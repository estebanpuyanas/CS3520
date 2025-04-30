#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int
main()
{
  const string error_message = "Invalid input.";
  
  vector<double> numbers;
  double input; 
  double median; 

  // Read the numbers.
  while(cin >> input) {
    numbers.push_back(input); 
  }

  // Base case for error (empty list). 
  if(numbers.empty()) {
    cout << error_message << endl;
  }

  // This ensures that we have enough space to store size of vector. Helps with iterating over vector and finding middle number. 
  size_t vectorSize = numbers.size(); 

  /**
   * If vector is of odd size then we can take the middle element and return it as the median.
   * Else, take the average of two middle elements and return it as the median. 
   */
  if(vectorSize % 2 == 1) {
    median = numbers[vectorSize / 2];
  } else {
    median = (numbers[vectorSize / 2 - 1] + numbers[vectorSize / 2]) / 2.0;
  }

  // Set the decimal precsion and print the median. 
  cout << fixed << setprecision(2) << median << endl; 
  
  // Sucess. 
  return 0; 
}
