/*
Write a function named swap that swaps the value of two integers through pointers.  Call the function to swap two values. You can assume the arguments are not null.
*/

#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
  int a = 2;
  int b = 4;
  cout << a << " " << b << endl; // "2 4"
  swap(&a, &b);
  cout << a << " " << b << endl; // "4 2"
}