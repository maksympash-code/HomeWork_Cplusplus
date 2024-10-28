#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void copyWithIndentation(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile) {
        cerr << "Error: Unable to open input file " << inputFile << endl;
        return;
    }

    if (!outFile) {
        cerr << "Error: Unable to open output file " << outputFile << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        outFile << " " << line << endl;
    }

    inFile.close();
    outFile.close();
    cout << "File copied with indentation successfully!" << endl;
}

// int main() {
//     string inputFile = "B:/C++/HomeWork/HW_14/F.txt";
//     string outputFile = "B:/C++/HomeWork/HW_14/G.txt";
//
//     copyWithIndentation(inputFile, outputFile);
//
//     return 0;
// }
