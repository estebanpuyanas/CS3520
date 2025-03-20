/*
Write a function that takes a (const reference to a) list, and uses iterators to print out the elements of the list in forward and backward order.

Hint: use auto
Hint: begin ... end; rbegin ... rend

Optional challenge: try without using auto.
Optional challenge hint: const_iterator
*/

#include <iostream>
#include <list>
using namespace std;

void print_forward_backward(const list<int> & lst) {
    cout << "forward: ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "backward: ";
    for (auto it = lst.rbegin(); it != lst.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
  list<int> test_list = { 1, 2, 3, 4, 5 };
  print_forward_backward(test_list);
  // forward: 1 2 3 4 5
  // backward: 5 4 3 2 1
}