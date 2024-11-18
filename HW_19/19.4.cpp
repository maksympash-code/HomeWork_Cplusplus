#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxInRow(const vector<int>& row) {
    return *max_element(row.begin(), row.end());
}

// int main() {
//     int n,m;
//
//     cout << "Enter the number of rows (n): ";
//     cin >> n;
//     cout << "Enter the number of columns (m): ";
//     cin >> m;
//
//     vector<vector<int>> matrix(n,vector<int>(m));
//
//     cout << "Enter the elements of the matrix:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> matrix[i][j];
//         }
//     }
//
//     sort(matrix.begin(), matrix.end(), [](const vector<int>& a, const vector<int>& b) {
//         return maxInRow(a) > maxInRow(b);
//     });
//
//     cout << "Matrix after sorting rows by descending max elements:\n";
//     for (const auto&row : matrix) {
//         for (int elements: row) {
//             cout << elements << " ";
//         }
//         cout << endl;
//     }
//
//     return 0;
// }