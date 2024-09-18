#include "5.12б.h"
#include <iostream>
using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

double sum(int n, double u, double v) {
    double a1 = u, a2, a_k;
    double b1 = v, b2, b_k;
    double sum = 0;

    a2 = 2 * b1 + a1 - 1;
    b2 = 2 * a1 + b1 - 1;

    sum += (a1 * b1) / factorial(2);
    sum += (a2 * b2) / factorial(3);

    for (int k = 3; k <= n; k++) {
        a_k = 2 * b2 + a2;
        b_k = 2 * a2 + b2;

        sum += (a_k * b_k) / factorial(k + 1);

        a2 = a_k;
        b2 = b_k;
    }
    return sum;
}

