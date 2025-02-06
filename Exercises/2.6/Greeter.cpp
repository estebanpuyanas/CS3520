/*
Write a class Greeter that prints “hello!” in its constructor and “goodbye!” in its destructor.
*/

#include <iostream>
using namespace std;

class Greeter {
    public:
    Greeter() {
        cout << "hello!" << endl;
    }
    ~Greeter() {
        cout << "goodbye!" << endl;
    }
};

int main() {
  Greeter g; // prints "hello!" and "goodbye!"
}