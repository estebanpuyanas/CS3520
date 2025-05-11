#ifndef INT_ARRAY_CXXTEST_HPP
#define INT_ARRAY_CXXTEST_HPP

#include <cxxtest/TestSuite.h>
#include <iostream>
#include <utility>
#include "IntArrayAlgorithms.hpp"

class IntArrayTestSuite : public CxxTest::TestSuite
{
public:

  void test_ctor_default() {
  IntArray a; 
  TS_ASSERT_EQUALS(a.size(), 0U);        // size should be 0
  TS_ASSERT_DIFFERS(a.ptr(), (int*)nullptr); // ptr should not be null (array of size 0)
  }

  void test_ctor_size_t() {
    IntArray a(5);
    TS_ASSERT_EQUALS(a.size(), 5U);
    for (size_t i = 0; i < a.size(); ++i) {
      TS_ASSERT_EQUALS(a[i], 0); // newly allocated should be 0-initialized
    }
  }

  void test_ctor_init() {
    IntArray a({1, 2, 3});
    TS_ASSERT_EQUALS(a.size(), 3U);
    TS_ASSERT_EQUALS(a[0], 1);
    TS_ASSERT_EQUALS(a[1], 2);
    TS_ASSERT_EQUALS(a[2], 3);
  }

  void test_ctor_copy() {
    IntArray source({10, 20, 30});
    IntArray copy(source);
    TS_ASSERT_EQUALS(copy.size(), source.size());
    for (size_t i = 0; i < copy.size(); ++i) {
      TS_ASSERT_EQUALS(copy[i], source[i]);
    }
    // Ensure a deep copy was made
    copy[0] = 99;
    TS_ASSERT_DIFFERS(copy[0], source[0]);
  }

  void test_ctor_move() {
    IntArray source({5, 10, 15});
    IntArray moved(std::move(source));
    TS_ASSERT_EQUALS(moved.size(), 3U);
    TS_ASSERT_EQUALS(moved[0], 5);
    TS_ASSERT_EQUALS(moved[1], 10);
    TS_ASSERT_EQUALS(moved[2], 15);
    // Source should be empty after move
    TS_ASSERT_EQUALS(source.size(), 0U);
  }

  void test_asgn_copy() {
    IntArray source({1, 2, 3, 4});
    IntArray other;
    other = source; 
    TS_ASSERT_EQUALS(other.size(), source.size());
    for (size_t i = 0; i < other.size(); ++i) {
      TS_ASSERT_EQUALS(other[i], source[i]);
    }
    // Modify one to ensure separate arrays
    source[0] = 42;
    TS_ASSERT_DIFFERS(source[0], other[0]);
  }

  void test_asgn_move() {
    IntArray source({7, 8, 9});
    IntArray other;
    other = std::move(source); 
    TS_ASSERT_EQUALS(other.size(), 3U);
    TS_ASSERT_EQUALS(other[0], 7);
    TS_ASSERT_EQUALS(other[1], 8);
    TS_ASSERT_EQUALS(other[2], 9);
    TS_ASSERT_EQUALS(source.size(), 0U); // source should be empty
  }

  void test_elem_nonconst() {
    IntArray a(3);
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    TS_ASSERT_EQUALS(a[0], 10);
    TS_ASSERT_EQUALS(a[1], 20);
    TS_ASSERT_EQUALS(a[2], 30);

    // Test out_of_range
    bool caught = false;
    try {
      a[3] = 100; 
    } catch (const std::out_of_range & e) {
      caught = true;
    }
    TS_ASSERT(caught);
  }

  void test_elem_const() {
    const IntArray a({1, 2, 3});
    TS_ASSERT_EQUALS(a[0], 1);
    TS_ASSERT_EQUALS(a[1], 2);
    TS_ASSERT_EQUALS(a[2], 3);

    // Test out_of_range on const
    bool caught = false;
    try {
      int val = a[3];
      (void)val; // suppress unused-variable warning
    } catch (const std::out_of_range & e) {
      caught = true;
    }
    TS_ASSERT(caught);
  }

  void test_oper_eq() {
    IntArray a({1, 2, 3});
    IntArray b({1, 2, 3});
    TS_ASSERT(a == b);
    b[2] = 99;
    TS_ASSERT(!(a == b));
  }

  void test_oper_ne() {
    IntArray a({4, 5, 6});
    IntArray b({4, 5, 6});
    TS_ASSERT(!(a != b));
    b[1] = 0;
    TS_ASSERT(a != b);
  }

  void test_operator_eq_different_sizes() {
    // This test ensures coverage of line 97, where lhs.m_sz != rhs.m_sz
    IntArray a({1, 2, 3});
    IntArray b({4, 5});
    TS_ASSERT(!(a == b)); // Should hit the "return false;" when sizes differ
  }

  void test_ptr_and_size() {
    IntArray a({100, 200, 300});
    TS_ASSERT_EQUALS(a.size(), 3U);
    TS_ASSERT_DIFFERS(a.ptr(), (int*)nullptr);
    // Check the pointer's contents match array elements
    const int *p = a.ptr();
    TS_ASSERT_EQUALS(p[0], 100);
    TS_ASSERT_EQUALS(p[1], 200);
    TS_ASSERT_EQUALS(p[2], 300);
  }

};

#endif
