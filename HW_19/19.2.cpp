#include <cmath>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<double> inputVector(int d) {
    vector<double> v(d);
    cout << "Enter " << d << " elements of the vector: ";
    for (int i = 0; i < d; i++) {
        cin >> v[i];
    }
    return v;
}

double calculateNorm(const vector<double>& v) {
    double sum = 0;
    for (double el: v) {
        sum += el * el;
    }
    return sqrt(sum);
}

// int main() {
//     int n, d;
//
//     cout << "Enter the dimension (d) of the vectors: ";
//     cin >> d;
//
//     cout << "Enter the number of vectors (n): ";
//     cin >> n;
//
//     double sum = 0;
//
//     for (int i = 0; i < n; i++) {
//         cout << "Vector " << (i + 1) << ":\n";
//         vector<double> v = inputVector(d);
//         double norm = calculateNorm(v);
//         sum += norm;
//     }
//     cout << "Sum of norms of all vectors: " << sum << endl;
//     return 0;
//}