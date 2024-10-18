#include "11.06б.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool IsOddSquare(int num) {
    int root = sqrt(num);
    return (root * root == num && root % 2 != 0);
}

int countOddSquare(const string& fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Error" << endl;
        exit(1);
    }

    int count = 0, num;

    while (file >> num) {
        if (IsOddSquare(num)) {
            count++;
        }
    }
    file.close();
    return count;
}

// int main() {
//     string fileName = "B:/C++/HomeWork/HW_11/numbers.txt";
//
//     int result = countOddSquare(fileName);
//     cout << result << endl;
//
//     return 0;
// }