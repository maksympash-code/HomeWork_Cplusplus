#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int getFirst(double num) {
    num = fabs(num);
    while (num >= 10) {
        num /= 10;
    }
    return static_cast<int>(num);
}

// int main() {
//     vector<float> V;
//     int n;
//     double el;
//
//     cout << "Enter the size of vector V: ";
//     cin >> n;
//
//     cout << "Enter the elements of vector V: ";
//     for (int i = 0; i < n; i++) {
//         cin >> el;
//         V.push_back(el);
//     }
//
//     map<int, double> groupSums;
//
//     for (size_t i = 0; i < V.size(); i++) {
//         int first = getFirst(V[i]);
//         double sum = 0;
//
//         for (size_t j = i + 1; j < V.size(); j++) {
//             if (getFirst(V[j]) == first) {
//                 sum += V[j];
//             }
//         }
//         if (sum == 0 && groupSums.find(first) == groupSums.end()) {
//             groupSums[first] = 0;
//         } else if (groupSums.find(first) == groupSums.end()) {
//             groupSums[first] = sum;
//         }
//     }
//     vector<pair<int, double>> sortedGroups(groupSums.begin(), groupSums.end());
//     sort(sortedGroups.begin(), sortedGroups.end());
//
//     cout << "Result (digit, sum):" << endl;
//     for (const auto& pair : sortedGroups) {
//         cout << pair.first << ": " << pair.second << endl;
//     }
//
//     return 0;
//}