#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int
main()
{

  // Define variables necessary for program.
  vector<string> words; 
  string lines; 
  size_t maxLength; 

  // Read input and determine the longest line. 
  while(getline(cin, lines)) {
    words.push_back(lines); 
    maxLength = max(maxLength, lines.size()); 
  }
  
  string textFrame(maxLength + 4, '*');
  cout << textFrame << endl;

  // Use const to avoid changing variable value. Use & to acess via reference rather than copy. 
  for(const auto& text : words) {
    cout << "* " << text;
    cout << string(maxLength - text.size(), ' ') << " *" << endl;  
  }

  // Print frame 
  cout << textFrame << endl; 

  // Sucess 
  return 0;
}
