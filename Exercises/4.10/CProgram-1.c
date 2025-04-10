/*
Write a C program that prompts the user to enter an integer.  Then it reads the integer, and if there was no error, prints the integer. If there was any error, prints an error message.

Hint: use printf, scanf, and the %d format specifier.

Note: to compile as C, replace the Makefile CXXFLAGS `-std=c++20` with `-std=c99 -xc`.
*/

#include <stdio.h>

int main() {
    int number;
    printf("Please enter an integer: ");
    
    // Read the integer from user input
    if (scanf("%d", &number) == 1) {
        // If successful, print the integer
        printf("You entered: %d\n", number);
    } else {
        // If there was an error, print an error message
        printf("Error: Invalid input. Please enter a valid integer.\n");
    }

    return 0;
}