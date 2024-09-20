#include "5.16ж.h"
#include <iostream>

using namespace std;

double sum_epsilon(double x, double epsilon) {
    if (epsilon <= 0) {
        cout << "The epsilon value must be greater than 0." << endl;
        return 0;
    } else if (x >= 1 || x <= -1) {
        cout << "The value of |x| must be less than 1." << endl;
        return 0;
    }

    double term = x;
    double sum = 2 * term;
    double x_power = x * x * x;
    int n = 3;

    while (term >= epsilon || term <= -epsilon) {
        term = x_power / n;
        sum += 2 * term;

        x_power *= x * x;
        n += 2;
    }
    return sum;
}

// int main() {
//     double x, epsilon;
//
//     cout << "Enter x(|x| < 1): ";
//     cin >> x;
//     cout << "Enter epsilon: ";
//     cin >> epsilon;
//
//     double result = sum_epsilon(x, epsilon);
//     cout << "Result: " << result << endl;
// }
