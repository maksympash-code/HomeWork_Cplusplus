#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "9.08.h"

using namespace std;

// void input(int* a, int n) {
//     cout << "Enter vector: " << endl;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
// }

// void print_vector(int* a, int n) {
//     cout << "Vector: ";
//     for (int i = 0; i < n; i++) {
//         cout << a[i] << " ";
//     }
//     cout << endl;
// }

float sum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return static_cast<float>(sum) / n;
}

void dispersia(int *a, int n, int result) {
    cout << "Dispersia:" << endl;

    for (int i = 0; i < n; i++) {
        int dispersia = a[i] - result;
        if (dispersia < 0 )
            dispersia = - dispersia;
        cout << dispersia << " ";
    }
    cout << endl;
}

// int main() {
//     int n;
//     cout << "Enter n: ";
//     cin >> n;
//
//     int* a = new int[n];
//
//     input(a, n);
//     print_vector(a,n);
//
//     float result = sum(a, n);
//     cout << "Result: " << result << endl;
//
//     dispersia(a, n, result);
//
//     delete [] a;
//     return 0;
// }
