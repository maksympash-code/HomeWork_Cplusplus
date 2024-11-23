#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// int main() {
//     vector<int> V1,V2;
//     int n, el;
//
//     cout << "Enter the size of vector V1: ";
//     cin >> n;
//     cout << "Enter elements of vector V1: ";
//     for (int i = 0; i < n; i++) {
//         cin >> el;
//         V1.push_back(el);
//     }
//
//     cout << "Enter the size of vector V2: ";
//     cin >> n;
//     cout << "Enter elements of vector V2: ";
//     for (int i = 0; i < n; i++) {
//         cin >> el;
//         V2.push_back(el);
//     }
//
//     set<int> unique_elements;
//     set_union(V1.begin(), V1.end(), V2.begin(), V2.end(),
//         inserter(unique_elements, unique_elements.begin()));
//
//     cout << "Unique elements in non-decreasing order: ";
//     for (const int& val : unique_elements) {
//         cout << val << " ";
//     }cout << endl;
//
//     return 0;
// }