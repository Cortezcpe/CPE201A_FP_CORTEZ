#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    // Create an input file stream and try to open the file for reading
    ifstream inFile("numbers.txt");

    // If the file could not be opened (missing, wrong folder, etc.),
    // show an error message and stop the program with a non-zero code
    if (!inFile)
    {
        cout << "Error: could not open numbers.txt" << endl;
        return 1;
    }

    // Create an output file stream to record warnings in a log file
    ofstream logFile("warnings.log");

    string line;          // holds the current line read from the file
    int lineNo = 0;       // tracks the current line number (for messages)
    int validCount = 0;   // counts how many valid numbers were found
    double sum = 0.0;     // running total of all valid numbers

    // LOOP OVER FILE CONTENT:
    // getline reads one whole line into 'line'. It returns false when
    // the end of the file is reached, which ends the loop automatically.
    while (getline(inFile, line))
    {
        lineNo++;   // we are now on the next line of the file

        // If the line is empty, skip it quietly (nothing to read)
        if (line.empty())
            continue;   // jump straight to the next loop iteration

        // Copy the line into a string stream. This lets us test the
        // line separately, so errors never damage the main file stream.
        istringstream iss(line);

        double value;    // will hold the number if the conversion works
        string extra;    // will catch any leftover text after the number

        // Two conditions must both be true for a valid line:
        //  1) (iss >> value)   : a floating-point number was read
        //  2) !(iss >> extra)  : nothing else remains on the line
        // Example: "7.5x" reads 7.5 but 'x' is left over -> invalid
        if (iss >> value && !(iss >> extra))
        {
            // Valid line: print the number and update totals
            cout << "Line " << lineNo << ": valid number = " << value << endl;
            sum += value;     // add to the running total
            validCount++;     // count this valid number
        }
        else
        {
            // Invalid line: show a warning on the screen
            cout << "WARNING: Line " << lineNo
                 << " skipped (invalid data: \"" << line << "\")" << endl;

            // Also write the warning to the log file
            logFile << "Line " << lineNo
                    << ": invalid data \"" << line << "\"" << endl;

            // Clear the error flags (failbit, etc.) so the stream is back
            // in a good state. This is the "clear the error" step.
            iss.clear();

            // No extra code needed to skip: the next getline() call
            // automatically moves on to the next line of the file.
        }
    }

    // Display a summary after the whole file has been processed
    cout << "\nValid numbers read: " << validCount << endl;
    cout << "Sum of valid numbers: " << sum << endl;

    // Close both files to release system resources
    inFile.close();
    logFile.close();

    return 0;   // 0 means the program finished successfully
}
