#include "7.8б.h"
#include <iostream>

using namespace std;

bool isCube(int num) {
    for (int i = 1; i * i * i <= num; i++) {
        if (i * i * i == num)
            return true;

    }
    return false;
}

// int main() {
//     int n;
//
//     cout << "Enter n: ";
//     cin >> n;
//
//     int arr[n];
//
//
//     cout << "Enter array elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//
//     int counter = 0;
//
//     for (int i = 0; i < n; i++) {
//         if (arr[i] % 2 == 0 && isCube(arr[i]))
//             counter++;
//     }
//
//     cout <<  "The number of the cubes is: " << counter << endl;
//
//     return 0;
// }