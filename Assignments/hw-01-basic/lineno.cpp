#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int
main()
{

  string inputLine;
  int lineNum = 1; 

  while(getline(cin, inputLine)) {
    cout << setw(3) << lineNum << ": " << inputLine << '\n'; // The setw() method fixes the width of the output stream. 
    ++lineNum; 
  }

  return 0;
}
