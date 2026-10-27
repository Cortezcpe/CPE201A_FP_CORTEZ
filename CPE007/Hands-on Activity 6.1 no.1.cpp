#include <iostream>
using namespace std;

// Function declarations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);

int main() {
	int num1, num2; // the two integers entered by the user
	
	// asks the user for the integers
	cout << "Enter first integer: ";
	cin >> num1;
	cout << "Enter second integer: ";
	cin >> num2;
	
	// Call each function and display< the result
	cout << "\nResults:\n";
	cout << num1 << "+" << num2 << "=" << add(num1, num2) << endl;
	cout << num1 << "-" << num2 << "=" << subtract(num1, num2) << endl;
	cout << num1 << "*" << num2 << "=" << multiply(num1, num2) << endl;
	
	// for division dividing by zero is undefined, so we check the devisor first
	if (num2 != 0) {
		cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
    } else {
        cout << num1 << " / " << num2 << " = Error: cannot divide by zero" << endl;
	}
	
	return 0;
}

// Function definitions
// Adds two integers and returns the sum
int add(int a, int b) {
    return a + b;
}
 
// Subtracts b from a and returns the difference
int subtract(int a, int b) {
    return a - b;
}
 
// Multiplies two integers and returns the product
int multiply(int a, int b) {
    return a * b;
}
 
// Divides a by b and returns the quotient
double divide(int a, int b) {
    // Cast to double so the decimal part is kept
    return static_cast<double>(a) / b;
}
