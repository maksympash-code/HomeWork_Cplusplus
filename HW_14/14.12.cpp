#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void mergeFiles(const string& file1, const string& file2, const string& outputFile) {
    ifstream input1(file1);
    ifstream input2(file2);
    ofstream output(outputFile);

    if (!input1.is_open() || !input2.is_open() || !output.is_open()) {
        cerr << "Error opening files!" << endl;
        return;
    }

    vector<string> lines2;
    string line;

    while (getline(input2, line)) {
        lines2.push_back(line);
    }

    int lines2Count = lines2.size();
    int index = 0;

    while (getline(input1, line)) {
        output << line;
        if (lines2Count > 0) {
            output << " " << lines2[index] << endl;
            index = (index + 1) % lines2Count;
        } else {
            output << endl;
        }
    }

    input1.close();
    input2.close();
    output.close();

    cout << "Files merged successfully into " << outputFile << endl;
}

// int main() {
//     string file1 = "B:/C++/HomeWork/HW_14/Name1.txt";
//     string file2 = "B:/C++/HomeWork/HW_14/Name2.txt";
//     string outputFile = "B:/C++/HomeWork/HW_14/MergedOutput.txt";
//
//     mergeFiles(file1, file2, outputFile);
//
//     return 0;
// }
