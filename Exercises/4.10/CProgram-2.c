/*
In this C program, fill in the definition of compareint and the call to qsort so that the array arr gets sorted.

You can find the documentation for qsort here:
https://en.cppreference.com/w/c/algorithm/qsort

Note: to compile as C, replace the Makefile CXXFLAGS `-std=c++20` with `-std=c99 -xc`.
*/

#include <stdio.h>
#include <stdlib.h>

int compareint(const void * a, const void * b) {
    // Cast the pointers to int pointers and dereference them
    int int_a = *(int*)a;
    int int_b = *(int*)b;
    
    // Compare the two integers
    if (int_a == int_b) {
        return 0; // equal
    } else if (int_a < int_b) {
        return -1; // a is less than b
    } else {
        return 1; // a is greater than b
    }
}

int main() {
  int arr[] = { 5, 3, 2, 4, 1 };
  const int length = sizeof(arr) / sizeof(*arr);

  // void qsort(void* base, size_t num, size_t size,
  //            int (*compar)(const void*,const void*));
  qsort(arr, length, sizeof(int), compareint);

  for (int i = 0; i < length; ++ i) {
    printf("%d\n", arr[i]);
  }
}