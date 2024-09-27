#include "practica_8.h"
#include <iostream>
#define N 3
#define M 3

const int max_size = 25;

using namespace std;

void print(int matrix[][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%i ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

void print_ptr(int matrix[][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%p ", &matrix[i][j]);
        }
        printf("\n");
    }
}

void input_matrix(int matrix[][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%i", &matrix[i][j]);
        }
    }
}

void exercise_1(int matrix[][M], int n, int m) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == m){
                matrix[i][j] = n;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void exercise_4(int matrix[max_size][max_size], int n, int m) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ":";
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void exercise_5(int matrix[][3], int n){
    cout << "Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Transform:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

void getMinor(double matrix[max_size][max_size], double temp[max_size][max_size], int n, int row, int col) {
    int tempRow = 0, tempCol = 0;

    for (int i = 0; i < n; i++) {
        if (i == row)
            continue;

        tempCol = 0;
        for (int j = 0; j < n; j++) {
            if (j == col)
                continue;

            temp[tempRow][tempCol] = matrix[i][j];
            tempCol++;
        }
        tempRow++;
    }
}

double determinant(double matrix[max_size][max_size], int n) {
    if (n == 1)
        return matrix[0][0];

    if (n == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    double det = 0;
    double temp[max_size][max_size];
    int sing = 1;

    for (int i = 0; i < n; i++) {
        getMinor(matrix, temp, n, i, 0);

        det += sing * matrix[0][i] * determinant(temp, n - 1);

        sing = -sing;
    }
    return det;
}

int main() {
    int n;

    cout << "Enter n:";
    cin >> n;

    if (n <= 0 || n > max_size) {
        cout << "Incorect" << endl;
        return 1;
    }

    double matrix[max_size][max_size];

    cout << "Matrix element(" << n << "x" << n << "):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Обчислення детермінанта
    double det = determinant(matrix, n);

    cout << "Determinant: "<< det << endl;

    // exercise_5(matrix, n);
    // cout << "Enter m:";
    // cin >> m;

    // exercise_1(matrix, n, m);
    // exercise_4(matrix, n, m);

    return 0;
}


    // print(matrix, 3, 3);
    // input_matrix(matrix, 3,3);
    // print(matrix, 3, 3);
    // printf("%p \n", &matrix);
    // printf("%p \n", &matrix + 1);
