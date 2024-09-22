#include <iostream>
#include "6.26.h"

using namespace std;

bool ZeroBits(unsigned int a, unsigned int b) {
    unsigned int t = a | b;
    return ((~t) != 0);
}

// int main() {
//     unsigned int a, b;
//
//     cout << "Enter a number: ";
//     cin >> a;
//     cout << "Enter another number: ";
//     cin >> b;
//
//     if (ZeroBits(a, b)) {
//         cout << "Numbers do not have zero bits in the same position.";
//     }else {
//         cout << "Numbers have zero bits in the same positions.";
//     }
//     return 0;
// }