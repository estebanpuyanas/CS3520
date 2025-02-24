/*
From the given code for WrappedUInt, add overloaded operators so that a WrappedUInt can be compared for equality (==) to a WrappedUInt or a UInt. Write them as friend functions.

Hint: There should be three functions written.
*/

#include <iostream>
using namespace std;

typedef unsigned int UInt;

class WrappedUInt {
public:
  WrappedUInt(UInt value, UInt modBy);
  friend ostream & operator<<(ostream &, const WrappedUInt &);

    friend bool operator==(const WrappedUInt & lhs, const WrappedUInt & rhs) {
        return lhs.m_value == rhs.m_value;
    }

friend bool operator==(const WrappedUInt & lhs, const UInt rhs);
friend bool operator==(const UInt lhs, const WrappedUInt & rhs);

private:
  UInt m_value;
  const UInt m_modBy;
};

WrappedUInt::WrappedUInt(UInt value, UInt modBy):
  m_value(value % modBy),
  m_modBy(modBy)
{}

ostream & operator<<(ostream & os, const WrappedUInt & wi) {
  return (os << wi.m_value);
}

bool operator==(const WrappedUInt & lhs, const UInt rhs) {
    return lhs.m_value == rhs;
}

bool operator==(const UInt lhs, const WrappedUInt & rhs) {
    return lhs == rhs.m_value;
}

int main() {
  WrappedUInt wi0(1U, 3U);
  WrappedUInt wi1(1U, 3U);
  WrappedUInt wi2(2U, 3U);

  cout << boolalpha;

  cout << (wi0 == wi1) << endl; // true
  cout << (wi0 == wi2) << endl; // false

  cout << (wi0 == 1U) << endl; // true
  cout << (wi0 == 2U) << endl; // false

  cout << (1U == wi0) << endl; // true
  cout << (2U == wi0) << endl; // false
}