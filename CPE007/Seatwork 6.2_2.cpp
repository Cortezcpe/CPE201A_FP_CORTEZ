#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    // Open the text file for reading
    ifstream inFile("mixed.txt");

    // Check that the file opened correctly before using it
    if (!inFile)
    {
        cout << "Error: could not open mixed.txt" << endl;
        return 1;   // stop the program: there is nothing to read
    }

    string line;            // stores the current line from the file
    int lineNo = 0;         // current line number
    int printedLines = 0;   // how many valid lines were printed
    int skippedLines = 0;   // how many invalid lines were skipped

    // LOOP OVER FILE CONTENT:
    // Reads one line per iteration until end of file is reached
    while (getline(inFile, line))
    {
        lineNo++;   // move the line counter forward

        // Turn the line into a stream so we can split it into tokens
        // (tokens are the pieces separated by spaces)
        istringstream lineStream(line);

        string token;             // one space-separated piece of the line
        vector<double> numbers;   // stores the numbers found on this line
        bool lineIsValid = true;  // assume the line is good until proven bad
        bool hasToken = false;    // tracks whether the line had any content

        // INNER LOOP: read the line one token (word/number) at a time
        while (lineStream >> token)
        {
            hasToken = true;   // the line is not blank

            // Put this single token into its own stream for testing
            istringstream tokenStream(token);

            double value;      // will hold the converted number
            char leftover;     // catches any extra characters after the number

            // A token is a valid number only if:
            //  1) a number can be read from it  (tokenStream >> value)
            //  2) no characters remain after it (!(tokenStream >> leftover))
            // Example: "5" is valid, but "5x" or "apples" is not.
            if (tokenStream >> value && !(tokenStream >> leftover))
            {
                numbers.push_back(value);   // save the valid number
            }
            else
            {
                // Invalid text found on this line
                tokenStream.clear();    // clear the stream's error state
                lineIsValid = false;    // mark the whole line as bad
                break;                  // stop checking the rest of the line
            }
        }

        // If the line had no tokens, it was blank: ignore it entirely
        if (!hasToken)
            continue;

        if (lineIsValid)
        {
            // Every token was a number, so print them all
            cout << "Line " << lineNo << " -> ";
            for (size_t i = 0; i < numbers.size(); i++)
            {
                cout << numbers[i] << " ";   // print each number
            }
            cout << endl;
            printedLines++;   // count this valid line
        }
        else
        {
            // The line contained invalid text: report it and move on.
            // The loop continues, so the program is never halted.
            cout << "Line " << lineNo
                 << " skipped (contains invalid text): " << line << endl;
            skippedLines++;   // count this skipped line
        }
    }

    // Print a summary after the file is fully processed
    cout << "\nValid lines: " << printedLines
         << ", Skipped lines: " << skippedLines << endl;

    // Close the file to free system resources
    inFile.close();

    return 0;   // program ended normally
}
