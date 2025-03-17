/*
Complete the implementation of MovableInt. A MovableInt holds a pointer to a dynamically allocated int that can be moved from object to object (but not copied!).  An empty MovableInt has a null pointer.
*/

#include <iostream>
using namespace std;

class MovableInt {
public:
  // allocate new movable int (dynamically allocate a single int and give it the value i)
  MovableInt(int i) : m_int(new int(i)) {}

  // move construct
  MovableInt(MovableInt && o) : m_int(o.m_int) {
    o.m_int = nullptr; // Transfer ownership and leave the source object empty
  }

  // deallocate movable int
  ~MovableInt() {
    delete m_int; // Free the dynamically allocated memory
  }

  // move assign
  MovableInt &operator=(MovableInt && o) {
    if (this != &o) { // Avoid self-assignment
      delete m_int;   // Free existing memory
      m_int = o.m_int; // Transfer ownership
      o.m_int = nullptr; // Leave the source object empty
    }
    return *this;
  }

  bool has_value() const { return m_int != nullptr; }

  int get_value() const { return *m_int; }

private:
  MovableInt(const MovableInt &) = delete;
  MovableInt &operator=(const MovableInt &) = delete;

  int * m_int = nullptr; // Initialize to nullptr
};

int main() {
  cout << boolalpha;

  MovableInt m1(1);
  cout << m1.has_value() << " " << m1.get_value() << endl; // true 1
  
  MovableInt m2(2);
  cout << m2.has_value() << " " << m2.get_value() << endl; // true 2

  MovableInt m3 = std::move(m1);
  cout << m1.has_value() << endl; // false
  cout << m3.has_value() << " " << m3.get_value() << endl; // true 1

  m3 = std::move(m2);
  cout << m2.has_value() << endl; // false
  cout << m3.has_value() << " " << m3.get_value() << endl; // true 2
}