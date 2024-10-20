#include "12.16.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

void processFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile) {
        cout << "Error opening input file: " << inputFileName << endl;
        return;
    }

    if (!outputFile) {
        cout << "Error opening output file: " << outputFileName << endl;
        return;
    }

    int number;

    outputFile << fixed << setprecision(5);

    while (inputFile >> number) {
        if (number > 0) {
            double root = sqrt(number);
            outputFile << number << ", " << root << endl;
        }

        inputFile.ignore(256, ' ');
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    string inputFileName = "B:/C++/HomeWork/HW_12/F.txt";
    string outputFileName = "B:/C++/HomeWork/HW_12/G.txt";

    processFile(inputFileName, outputFileName);

    cout << "Processing complete. Check the output file: " << outputFileName << endl;

    return 0;
}
