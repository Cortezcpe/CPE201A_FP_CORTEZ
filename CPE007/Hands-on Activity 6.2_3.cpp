#include <iostream>   // cout, endl
#include <iomanip>    // setw
#include <cmath>      // floor
using namespace std;

// Function prototypes
int celsius(int f);      // Fahrenheit in, Celsius out
int fahrenheit(int c);   // Celsius in, Fahrenheit out

int main()
{
    // Table headers: each table has two columns
    cout << setw(5) << "C" << setw(6) << "F" << " |"
         << setw(5) << "C" << setw(6) << "F" << " |"
         << setw(5) << "F" << setw(6) << "C" << " |"
         << setw(5) << "F" << setw(6) << "C" << endl;
    cout << "------------+------------+------------+-----------" << endl;

    // The longest table (Fahrenheit 32..122) has 91 rows, so 91 lines
    // are enough for all four tables
    for (int i = 0; i <= 90; i++)
    {
        // Table 1: Celsius 0..50 (rows 0 to 50)
        if (i <= 50)
            cout << setw(5) << i << setw(6) << fahrenheit(i);
        else
            cout << setw(5) << "" << setw(6) << "";   // blank to keep alignment
        cout << " |";

        // Table 2: Celsius 51..100 (rows 0 to 49)
        if (i <= 49)
            cout << setw(5) << 51 + i << setw(6) << fahrenheit(51 + i);
        else
            cout << setw(5) << "" << setw(6) << "";
        cout << " |";

        // Table 3: Fahrenheit 32..122 (rows 0 to 90)
        cout << setw(5) << 32 + i << setw(6) << celsius(32 + i) << " |";

        // Table 4: Fahrenheit 123..212 (rows 0 to 89)
        if (i <= 89)
            cout << setw(5) << 123 + i << setw(6) << celsius(123 + i);

        cout << endl;
    }

    return 0;
}

// Returns the Celsius equivalent of a Fahrenheit temperature
// Formula: C = 5/9 * (F - 32), rounded to the nearest integer
int celsius(int f)
{
    return (int) floor(5.0 * (f - 32) / 9.0 + 0.5);
}

// Returns the Fahrenheit equivalent of a Celsius temperature
// Formula: F = 9/5 * C + 32, rounded to the nearest integer
int fahrenheit(int c)
{
    return (int) floor(9.0 * c / 5.0 + 32 + 0.5);
}
