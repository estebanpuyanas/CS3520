/*
Write a pair of overloaded functions, named swapnumbers, that will swap the values of either two ints or two doubles.
*/

#include <iostream>
using namespace std;

void swapnumbers(int int1, int int2);
void swapnumbers(double double1, double double2);

int main() {
  int i1 = 1, i2 = 2;
  double d1 = 1.1, d2 = 2.2;

  cout << i1 << " " << i2 << endl; // 1 2
  cout << d1 << " " << d2 << endl; // 1.1 2.2

  swapnumbers(i1, i2);
  swapnumbers(d1, d2);

  cout << i1 << " " << i2 << endl; // 2 1
  cout << d1 << " " << d2 << endl; // 2.2 1.1
}

void swapnumbers(int int1, int int2) {
    int temp = int1; 
    int1 = int2;
    int2 = temp; 

  }

  void swapnumbers(double double1, double double2) {
    double temp = double1;
    double1 = double2; 
    double2 = temp;
  }