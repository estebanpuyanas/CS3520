/*
Write a function named zeroout that takes two pointer ranges, one for values and one for an array.
Any elements in the array range that are in the value range are set to 0.
You can assume the pointer arguments are not null.
*/

#include <iostream>
using namespace std;

void zeroout(const int *val_begin, const int *val_end, int *arr_begin, int *arr_end) {
    for (int *p = arr_begin; p != arr_end; ++p) {
        for (const int *q = val_begin; q != val_end; ++q) {
        if (*p == *q) {
            *p = 0;
            break;
        }
        }
    }
}

int main() {
  const size_t sz = 5;
  const int vals[3] = {1, 3, 5};

  int arr1[sz] = {1, 2, 3, 4, 5};
  zeroout(vals + 1, vals + 2, arr1, arr1 + sz);
  for (int e: arr1) { cout << e << " "; }
  cout << endl; // `1 2 0 4 5`

  int arr2[sz] = {1, 2, 3, 4, 5};
  zeroout(vals, vals + 3, arr2, arr2 + sz);
  for (int e: arr2) { cout << e << " "; }
  cout << endl; // `0 2 0 4 0`
}