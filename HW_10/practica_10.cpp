#include "practica_10.h"
#include <iostream>
#include <string.h>

using namespace std;

// void print() {
//     cout << "Hello World!" << endl;
// }
// int** createMatrix(int n, int m) {
//     int **matrix = (int**)calloc(n, sizeof(*matrix));
//     for (int i = 0; i < n; i++) {
//         matrix[i] = (int*)calloc(m, sizeof(*matrix[i]));
//     }
//     return matrix;
// }
//
// void delete_matrix(int **matrix, int n, int m) {
//     for (int i = 0; i < n; i++) {
//         free(matrix[i]);
//     }
//     free(matrix);
// }
//
// void input(int **matrix, int n, int m) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> matrix[i][j];
//         }
//     }
// }
//
// void print(int **matrix, int n, int m) {
//     cout << "Matrix" << endl;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cout << matrix[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
//
// int** multi_matrix(int** matrix, int** newMatrix, int n, int m, int l) {
//     int** C = createMatrix(n, l);
//
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < l; j++) {
//             C[i][j] = 0;
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < l; j++) {
//             for (int k = 0; k < m; k++) {
//                 C[i][j] += matrix[i][k] * newMatrix[k][j];
//             }
//         }
//     }
//     return C;
// }

// struct struct_1 {
//     int n;
//     char s[25];
// };

// int main() {
//     struct struct_1 a;
//     a.n = 10;
//     strcpy(a.s, "hello world");
//     cout << a.s << endl;






















    // int n = 2, m = 3, l = 2;
    //
    // int **matrix = createMatrix(n, m);
    // int** newMatrix = createMatrix(m, l);
    // input(matrix, n, m);
    // print(matrix, n, m);
    //
    // input(newMatrix, m, l);
    // print(newMatrix, m, l);
    //
    // int** C = multi_matrix(matrix, newMatrix, n, m, l);
    // print(C, n, l);
    //
    // delete_matrix(matrix, n, m);
    // delete_matrix(newMatrix, n, m);
    // delete_matrix(C, n, m);
//     return 0;
// }