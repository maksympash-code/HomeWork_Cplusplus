#include <iostream>
#include "6.22.h"

using namespace std;

unsigned int LowerBits(unsigned int n, int k) {
    unsigned int lower_k = (1 << k) - 1;
    return n | ~lower_k;
}

int main() {
    unsigned int n;
    int k;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    unsigned int result = LowerBits(n, k);

    cout << "Result: " << result << endl;

    return 0;
}