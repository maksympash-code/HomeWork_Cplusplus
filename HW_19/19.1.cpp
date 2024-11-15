#include <iostream>
#include <vector>

using namespace std;

// int main() {
//     int n;
//     cout << "Enter the number of customers: ";
//     cin >> n;
//
//     vector<int> t(n);
//     vector<int> c(n);
//
//     cout << "Enter the service times for each customer: ";
//     for (int i = 0; i < n; i++) {
//         cin >> t[i];
//     }
//
//     c[0] = 0; // Перший покупець не чекає в черзі
//     for (int i = 1; i < n; i++) {
//         c[i] = c[i - 1] + t[i - 1] + 1;
//     }
//
//     int minTimeIndex = 0, maxTimeIndex = 0;
//     for (int i = 1; i < n; i++) {
//         if (t[i] < t[minTimeIndex]) {
//             minTimeIndex = i;
//         }
//         if (c[i] > c[maxTimeIndex]) {
//             maxTimeIndex = i;
//         }
//     }
//
//     cout << "Customer with minimum service time: " << (minTimeIndex + 1) << " (Time: " << t[minTimeIndex] << " minutes)" << endl;
//     cout << "Customer with maximum queue time: " << (maxTimeIndex + 1) << " (Time: " << c[maxTimeIndex] << " minutes)" << endl;
//
//     return 0;
// }
