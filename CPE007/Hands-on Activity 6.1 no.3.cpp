#include <iostream>
#include <iomanip>
using namespace std;

// Exchange rate: pesos per 1 US dollar.
// This is only an approximation; change it to match the current rate.
const double RATE = 62.86;

// Function prototypes (declarations)
double dollarsToPesos(double dollars);   // pesos = dollars * RATE
double pesosToDollars(double pesos);     // dollars = pesos / RATE

int main() {
    int choice;      // menu choice entered by the user
    double amount;   // amount of money entered by the user

    // Show money values with exactly 2 decimal places
    cout << fixed << setprecision(2);

    // Display the menu
    cout << "Currency Converter (1 USD = " << RATE << " PHP)\n";
    cout << "1. Dollars to Pesos\n";
    cout << "2. Pesos to Dollars\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        // Dollars -> Pesos
        cout << "Enter amount in dollars: ";
        cin >> amount;
        cout << "$" << amount << " = PHP " << dollarsToPesos(amount) << endl;
    } else if (choice == 2) {
        // Pesos -> Dollars
        cout << "Enter amount in pesos: ";
        cin >> amount;
        cout << "PHP " << amount << " = $" << pesosToDollars(amount) << endl;
    } else {
        // Anything other than 1 or 2 is not a valid option
        cout << "Invalid choice. Please run the program again." << endl;
    }

    return 0;  // program ended successfully
}

// Function definitions

// Converts US dollars to Philippine pesos
double dollarsToPesos(double dollars) {
    return dollars * RATE;
}

// Converts Philippine pesos to US dollars
double pesosToDollars(double pesos) {
    return pesos / RATE;
}
