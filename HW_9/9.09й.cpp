#include <iostream>
#include "9.09й.h"

using namespace std;

void input(double** a, int N, int M) {
    for (int i = 0; i < N; i++) {
        cout << "Enter a row_" << i << ":";
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
}

void print(double** a, int N, int M) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

double** removeRow(double** a, int& N, int M, int k) {
    if (k < 0 || k >= N) {
        cout << "Invalid K!" << endl;
        return a;
    }

    delete[] a[k];

    double** newA = new double*[N-1];

    for (int i = 0, j = 0; i < N; i++) {
        if (i != k) {
            newA[j] = a[i];
            j++;
        }
    }

    N--;

    delete[] a;
    return newA;
}

// int main() {
//     int N, M, k;
//     cout << "Enter N:";
//     cin >> N;
//
//     cout << "Enter M:";
//     cin >> M;
//
//     double** a = new double*[N];
//
//     for (int i = 0; i < N; i++) {
//         a[i] = new double[M];
//     }
//
//     input.txt(a, N, M);
//     print(a, N, M);
//
//     cout << "Which row to delete? (Enter a number):";
//     cin >> k;
//
//     a = removeRow(a, N, M, k);
//     print(a, N, M);
//
//     for (int i = 0; i < N; i++) {
//         delete[] a[i];
//     }
//     delete []a;
//
//     return 0;
// }