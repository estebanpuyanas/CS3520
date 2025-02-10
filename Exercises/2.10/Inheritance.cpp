/*
Write the implementation for two classes Base and Derived.  Derived inherits from Base and the classes have two member functions: redefinable and overridable.  Both functions return the name of the class as a string; however, the derived class redefines redefinable and overrides overridable.

Hint: one member function should be virtual and one should not.
*/

/**
 * Answers to PPQ
 * 1.Mak it virtual 
 * 2. Fucntion in base class declared as = 0. 
 * 3. Method is not overriding. 
 * 4. Constructor. 
 * 5. Using multiple inheritance. 
 */

#include <iostream>
#include <string>
using namespace std;

class Base {
public:
  virtual ~Base() {} // recommended
    virtual string redefinable() const {
        return "Base";
    }
    string overridable() const {
        return "Base";
    }
};

class Derived : public Base {
public:
  virtual ~Derived() {} // recommended
    string redefinable() const {
        return "Derived";
    }
    string overridable() const {
        return "Derived";
    }
};

void use_base(const Base & b) {
  cout << b.redefinable() << " " << b.overridable() << endl;
}

void use_derived(const Derived & d) {
  cout << d.redefinable() << " " << d.overridable() << endl;
}

int main() {
  Base b;
  Derived d;

  use_base(b); // prints "Base Base"
  use_base(d); // prints "Base Derived"
  use_derived(d);  // prints "Derived Derived"
}