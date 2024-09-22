#include <iostream>
#include "6.22.h"

using namespace std;

 int LowerBits(int n, int k) {
    int lower_k = (1 << k) - 1;
    return n | ~lower_k;
}

// int main() {
//     int n;
//     int k;
//
//     cout << "Enter n: ";
//     cin >> n;
//     cout << "Enter k: ";
//     cin >> k;
//
//     int result = LowerBits(n, k);
//
//     cout << "Result: " << result << endl;
//
//     return 0;
// }