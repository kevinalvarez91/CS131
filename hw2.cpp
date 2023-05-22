/*
   Kevin Alvarez
   CS 131
   April 1 2023

 */
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main() {
    char choice;

    //assuming the Nth value of 0 is 0 aka fib(0) = 0
    //assuming the Nth valufe of the first 1 is 1 aka fib(1) = 1, therefore fib(2) = 1
    do {
        int n, a = 0, b = 1, c;
        cout << "Fibonacci Sequence Calculator: " << endl; 
        cout << "Enter the 'Nth' value of the maximum term you would like to display: ";
        cin >> n;

        if (n < 1) {
            cout << "Invalid input. Please enter a positive integer." << endl;
            break; // terminate the program
        }
        else if (n == 1) {
            cout << a << endl;
            continue;
        }

        cout << a << " " << b << " ";

        for (int i = 2; i <= n; i++) {
            c = a + b;
            cout << c << " ";
            a = b;
            b = c;
        }

        cout << endl;

        cout << "Do you want to run the program again? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    return 0;
}




/*
   Test 1
   Fibonacci Sequence Calculator: 
   Enter the 'Nth' value of the maximum term you would like to display: 5
   0 1 1 2 3 5

   Test 2
   Fibonacci Sequence Calculator: 
   Enter the 'Nth' value of the maximum term you would like to display: 6
   0 1 1 2 3 5 8 

   Test 3
   Fibonacci Sequence Calculator: 
   Enter the 'Nth' value of the maximum term you would like to display: J
   Invalid input. Please enter a positive integer.



 */
