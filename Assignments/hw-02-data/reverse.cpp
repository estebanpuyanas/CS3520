#include <iostream>
#include <string>
#include <vector>
using namespace std;

int
main()
{
  // Define variables necessary for program. 
  vector<string> words; 
  string inputLines;

  // Read text. 
  while(getline(cin, inputLines)) {

    // Reverse characters in line. Use two pointer to swap characters. 
    for(size_t i = 0, j = inputLines.size() -1; i < j; i++, j--) {
      char temp = inputLines[i]; 
      inputLines[i] = inputLines[j];
      inputLines[j] = temp; 
    }
    words.push_back(inputLines);
  }

  // Print the reversed output. Remember to put chatgpt suggestion for rbegins and rends in LLM.txt. 
  for(auto i = words.rbegin(); i != words.rend(); ++i) {
    cout << *i << "\n"; // Use * to get the value of the iterator in the loop. 
  }

  // Success 
  return 0; 
}
