#include "IntArrayAlgorithms.hpp"
#include "IntArray.hpp"
using namespace std;

void IntArrayAlgorithms::swap(IntArray & lhs, IntArray & rhs) {
  IntArray temp(lhs); 
  lhs = rhs;         
  rhs = temp;        
}

bool IntArrayAlgorithms::contains(const IntArray & arr, int val) {
  for (size_t i = 0; i < arr.size(); i++) {
      if (arr[i] == val) {
          return true;
      }
  }
  return false;
}

void IntArrayAlgorithms::sort(IntArray & arr) {
  size_t n = arr.size();
  for (size_t i = 0; i < n; i++) {
      size_t minIndex = i;
      for (size_t j = i + 1; j < n; j++) {
          if (arr[j] < arr[minIndex]) {
              minIndex = j;
          }
      }
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
  }
}

int IntArrayAlgorithms::sum(const IntArray & arr) {
  int s = 0;
  for (size_t i = 0; i < arr.size(); i++) {
      s += arr[i];
  }
  return s;
}

int IntArrayAlgorithms::product(const IntArray & arr) {
  int p = 1;
  for (size_t i = 0; i < arr.size(); i++) {
      p *= arr[i];
  }
  return p;
}
