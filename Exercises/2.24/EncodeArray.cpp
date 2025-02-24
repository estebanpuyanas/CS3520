/*
Write the functions accumulate_matrix and print_matrix.
accumulate_matrix takes two 2D int arrays with both dimensions size, and adds the values from the second onto the first (i.e. a += b).
print_matrix takes one such 2D array and prints the elements, one row on each line.
You might need to consider which arguments are const.

Optional: rewrite the functions (and arrays) to encode the 2D arrays into 1D arrays.
*/

#include <cstdlib>
#include <iostream>
using namespace std;

const size_t size = 3;

void accumulate_matrix(int mtxA[::size][::size], const int mtxB[::size][::size]) {
  for (size_t i = 0; i < ::size; i++) {
    for (size_t j = 0; j < ::size; j++) {
      mtxA[i][j] += mtxB[i][j];
    }
  }
}

void print_matrix(const int mtx[::size][::size]) {
  for (size_t i = 0; i < ::size; i++) {
    for (size_t j = 0; j < ::size; j++) {
      cout << mtx[i][j] << " ";
    }
    cout << endl;
  }
}


int main() {
  int mtxA[::size][::size] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  const int mtxB[::size][::size] = {{0, 1, 2}, {1, 0, 0}, {-1, -1, -1}};

  accumulate_matrix(mtxA, mtxB);
  print_matrix(mtxA);
  // 1 3 5
  // 5 5 6
  // 6 7 8
}