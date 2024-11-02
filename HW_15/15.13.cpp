#include "15.13.h"
#include <iostream>
#include <cmath>

using namespace std;

class Vector3 {
public:
    double x, y, z;

    Vector3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3 &other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    double operator*(const Vector3 &v)const {
        return x * v.x + y * v.y + z * v.z;
    }

    double abs() const {
        return sqrt(x * x + y * y + z * z);
    }

    void print() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
};

class Matrix3 {
public:
    double m[3][3];

    Matrix3() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] = 0;
            }
        }
    }

    Vector3 operator*(const Vector3& v) const {
        Vector3 result;
        result.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z;
        result.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z;
        result.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z;
        return result;
    }

    double det() const {
        return m[0][0] * (m[1][1] * m [2][2] - m[2][1] * m[1][2])
                - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
                + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
    }

    double abs() const {
        double sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                sum += m[i][j] * m[j][i];
            }
        }
        return sqrt(sum);
    }

    void print() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// int main() {
//     Vector3 v1(1, 2, 3);
//     Vector3 v2(4, 5, 6);
//
//     Vector3 vSum = v1 + v2;
//     cout << "Sum: ";
//     vSum.print();
//
//     double dotProduct = v1 * v2;  // Скалярний добуток
//     cout << "Product: " << dotProduct << endl;
//
//     cout << "abs() v1:\n " << v1.abs() << endl;
//
//     Matrix3 matrix;
//     matrix.m[0][0] = 1; matrix.m[0][1] = 2; matrix.m[0][2] = 3;
//     matrix.m[1][0] = 4; matrix.m[1][1] = 5; matrix.m[1][2] = 6;
//     matrix.m[2][0] = 7; matrix.m[2][1] = 8; matrix.m[2][2] = 9;
//
//     cout << "Matrix:\n";
//     matrix.print();
//
//     cout << "det(): " << matrix.det() << endl;
//     cout << "abs(): " << matrix.abs() << endl;
//
//     Vector3 result = matrix * v1;
//     cout << "Product Matrix:" << endl;
//     result.print();
//     return 0;
// }