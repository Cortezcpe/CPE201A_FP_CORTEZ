#include <iostream>
#include <string>
using namespace std;

string checkNumber(int num) {
    if (num < 0) {
        // Negative numbers are treated as invalid in this program
        return "Invalid";
    } else if (num % 2 == 0) {
        // % gives the remainder; if dividing by 2 leaves 0, the number is even
        return "Even";
    } else {
        // Any other non-negative number has a remainder of 1, so it is odd
        return "Odd";
    }
}

int main() {
    int number;   // variable that stores the user's input

    // Ask the user to enter a number
    cout << "Enter a number: ";

    // cin >> number fails if the input is not a whole number
    if (!(cin >> number)) {
        cout << "Result: Invalid" << endl;
        return 0;   // end the program early
    }

    // Function call
    // Argument: 'number' is passed to the parameter 'num' of checkNumber()
    // The returned string is stored in 'result'
    string result = checkNumber(number);

    // Display the result
    cout << "Result: " << result << endl;

    return 0;
}
