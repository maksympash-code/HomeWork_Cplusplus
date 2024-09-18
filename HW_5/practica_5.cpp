#include "practica_5.h"
#include <iostream>
#include <cmath>
using namespace std;

// int fibrec(int n) {
//     if (n == 0) {
//         return 0;
//     }
//     else if (n == 1) {
//         return 1;
//     }
//     else {
//         return fibrec(n - 1) + fibrec(n - 2);
//     }
// }

// int fiba (int n) {
//     int f0 = 0;
//     int f1 = 1;
//     int f2;
//     for (int i = 0; i < n; i++) {
//         f2 = f1 + f0;
//         f0 = f1;
//         f1 = f2;
//     }
//     return f0;
// }
// int fibb (int a) {
//     int f0 = 0;
//     int f1 = 1;
//     int f2;
//     int i = 0;
//     for (; f1 <= a; i++) {
//         f2 = f1 + f0;
//         f0 = f1;
//         f1 = f2;
//     }
//     return i;
// }
//
// int fibc (int a) {
//     int f0 = 0;
//     int f1 = 1;
//     int f2;
//     int i = 1;
//     for (; f0 <= a; i++) {
//         f2 = f0 + f1;
//         f0 = f1;
//         f1 = f2;
//     }
//     return i;
// }
//
//  int fibd (int a) {
//      int f0 = 0;
//      int f1 = 1;
//      int f2, sum = f0 + f1;
//      for (int i = 2; f1 <= 1000; i++) {
//          f2 = f0 + f1;
//          if (f2 > 1000) {
//              break;
//          }
//          sum += f2;
//          f0 = f1;
//          f1 = f2;
//      }
//      return sum;
// }

// int countSteps(int n) {
//     int steps = 0;
//     while (n != 1) {
//         if (n %2 == 0){
//             n = n / 2;
//         }
//         else {
//             n = 3 * n + 1;
//         }
//         steps++;
//     }
//     return steps;
// }

double sum(int n) {
    double a1 = 0, a2 = 1;
    double b1 = 1, b2 = 0;
    double a_prev2 = a1, a_prev1 = a2;
    double b_prev1 = b1, b_prev2 = b2;
    double sum = 0;

    sum += pow(2,1) / (a1 + b1);
    sum += pow(2,2) / (a2 + b2);

    for (int k = 3; k <= n; k++) {
        double ak = (a_prev1 / k) + a_prev2 * b_prev1;
        double bk = b_prev1 + a_prev1;

        sum += pow(2, k) / (ak + bk);


        a_prev2 = a_prev1;
        a_prev1 = ak;
        b_prev2 = b_prev1;
        b_prev1 = bk;
    }
    return sum;
}


void practica_5() {

    int n;

    cout << "Enter n: " << endl;
    cin >> n;

    double result = sum(n);
    cout << result << endl;
    // int maxSteps = 0;
    // int numberWithMaxSteps = 0;
    //
    // for (int n = 1; n < 1000; n++) {
    //     int steps = countSteps(n);
    //     if (steps > maxSteps) {
    //         maxSteps = steps;
    //         numberWithMaxSteps = n;
    //     }
    // }
    // cout << numberWithMaxSteps << endl;
    // cout << maxSteps << endl;
    // cout << fiba(n) << endl;
    // cout << fibb(a) << endl;
    // cout << fibc(n) << endl;
    // cout << fibd(a) << endl;

}
