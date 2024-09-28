#include "8.23.h"
#include <iostream>

using namespace std;

void rotateMatrix(int matrix[][50], int size) {
    int temp[50][50];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp[j][size - 1 - i] = matrix[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}


int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    int size = 2 * n;
    int matrix[50][50];

    cout << "Enter matrix elements: " << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> matrix[i][j];
        }
    }

    // 3 рази по 90
    rotateMatrix(matrix, size);
    rotateMatrix(matrix, size);
    rotateMatrix(matrix, size);

    cout << "Rotated matrix:" << endl;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}