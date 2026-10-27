#include <iostream> 
#include <string> 
using namespace std;

string toUpperCase(string text) {
    // Loop through every character in the string, one at a time
    // text.length() gives the total number of characters
    for (int i = 0; i < text.length(); i++) {

        // Check if the current character is a lowercase letter (a to z)
        if (text[i] >= 'a' && text[i] <= 'z') {

            // In ASCII, 'a' = 97 and 'A' = 65, a difference of 32
            // Subtracting 32 changes a lowercase letter to its uppercase form
            text[i] = text[i] - 32;
        }
        // Characters that are not lowercase letters (spaces, numbers,
        // symbols, and capital letters) are left unchanged
    }

    // Send the converted string back to the place where the function was called
    return text;
}

int main() {
    string input;   // variable that stores the user's sentence

    // Ask the user to type a string
    cout << "Enter a string in lowercase: ";

    // getline() reads the whole line, including spaces
    getline(cin, input);

    // Function call
    // Argument: 'input' is passed to the parameter 'text' of toUpperCase()
    // The returned string is stored in 'upper'
    string upper = toUpperCase(input);

    // Display the converted string
    cout << "Uppercase: " << upper << endl;

    return 0;
}
