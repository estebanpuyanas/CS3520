/*
Write a program that prompts the user and reads in their favorite number as a double, their favorite letter as a char, and their favorite foods as a string (possibly containing spaces). It then prints out their favorites. Don't worry about error handling for now.
Possibly useful reminder: numeric_limits<streamsize>::max()
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

    double favoriteNumber;
    char favoriteLetter;
    string favoriteFood;


  cout << "Enter your favorite number:" << endl;
  cin >> favoriteNumber;

  cout << "Enter your favorite letter:" << endl;
  favoriteLetter = cin.get();

  cout << "Enter some of your favorite foods:" << endl;
  getline(cin, favoriteFood);

  cout << "Favorites:" << endl;
  cout << "number: " << endl;
  cout << "letter: " << endl;
  cout << "foods:  " << endl;
}