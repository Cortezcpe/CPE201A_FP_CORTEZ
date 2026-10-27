#include <iostream>
using namespace std;

// Function prototypes (declarations)
double fahrenheitToCelsius(double f);   // C = (F - 32) * 5/9
double celsiusToFahrenheit(double c);   // F = (C * 9/5) + 32

int main() {
    int choice;     // menu choice entered by the user
    double value;   // temperature entered by the user

    // Display the menu
    cout << "Temperature Converter\n";
    cout << "1. Fahrenheit to Celsius\n";
    cout << "2. Celsius to Fahrenheit\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        // Fahrenheit -> Celsius
        cout << "Enter temperature in Fahrenheit: ";
        cin >> value;
        cout << value << " F = " << fahrenheitToCelsius(value) << " C" << endl;
    } else if (choice == 2) {
        // Celsius -> Fahrenheit
        cout << "Enter temperature in Celsius: ";
        cin >> value;
        cout << value << " C = " << celsiusToFahrenheit(value) << " F" << endl;
    } else {
        // Anything other than 1 or 2 is not a valid option
        cout << "Invalid choice. Please run the program again." << endl;
    }

    return 0;
}

// Function definitions
// Converts a Fahrenheit temperature to Celsius
double fahrenheitToCelsius(double f) {
    // Use 5.0 and 9.0 (decimals) so the division is not truncated
    return (f - 32.0) * 5.0 / 9.0;
}

// Converts a Celsius temperature to Fahrenheit
double celsiusToFahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32.0;
}
