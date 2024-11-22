#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
template<class con>
void print(const con& c) {
    cout << "[";
    for (const auto& item: c)
        cout << item << ",";
    cout << "\b]" << endl;
}

// int main() {
//     vector<int> v1 = {-6, 0, -4, 3, 7, 1, 2};
//     int arr[] = {-6, 0, -4, 3, 7, 1, 2};
//     sort(arr, arr+7);
//     sort(v1.begin(), v1.end(), greater<int>());
//     print(v1);
//     print(arr);
//
//     cout << accumulate(v1.begin(), v1.end(), 0, [](int x, int y){return x * y;}) << endl;
//     cout << find_if(v1.begin(), v1.end(), 0, [](int x) {return x % 2 == 0;ф}) << endl;
//
// }