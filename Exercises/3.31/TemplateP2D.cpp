/*
Write a struct template Point2D that has x and y member variables of any (same) type. Overload the + and << operators for Point2D.
*/

#include <iostream>
using namespace std;

template <typename T>
struct Point2D {
    T x;
    T y;

    // Overload the + operator
    Point2D operator+(const Point2D& other) const {
        return Point2D{ x + other.x, y + other.y };
    }

    // Overload the << operator as a friend function
    friend ostream& operator<<(ostream& os, const Point2D& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    Point2D<double> a = { 1.1, 2.2 };
    Point2D<double> b = { 3.3, 4.4 };
    cout << a + b << endl; // Output: (4.4, 6.6)

    Point2D<int> c = { 1, 2 };
    Point2D<int> d = { 3, 4 };
    cout << c + d << endl; // Output: (4, 6)
}