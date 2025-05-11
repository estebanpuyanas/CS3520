#include <iostream>
#include <vector>
using namespace std;
const int iterations = 10000000;

void run_vector_at() {
    // Initialize a vector with 1000 elements, all set to 1
    vector<int> vec(1000, 1);
    int sum = 0;
    for (int i = 0; i < iterations; i++) {
        sum += vec.at(i % 1000); // Vector must be summed otherwise the compiler will optimize the loop away. 
    }
    cout << "Vector at() sum: " << sum << endl;
}

void run_vector_brackets() {
    vector<int> vec(1000, 1);
    int sum = 0;
    for (int i = 0; i < iterations; i++) {
        sum += vec[i % 1000];
    }
    cout << "Vector [] sum: " << sum << endl;
}

int main() {
    run_vector_at();
    run_vector_brackets();
    return 0;
}