#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

template<class Con>
void print(const Con c) {
    cout << "[ ";
    for (const auto& item: c) {
        cout << item << ", ";
    }
    cout << "\b\b]" << endl;
}

using namespace std;

// int main() {
//     set<int> s1 = {1,3,6,7,9,12,15};
//     set<int> s2 = {2,3,4,7,8,10,12,14,15};
//
//
//     s1.insert(4);// додати елемент
//     s1.erase(3); // видалити елемент(за ключем)
//     vector<int> v(min(s1.size(), s2.size()));
//
//     // перетин множин
//     vector<int>::iterator it = set_intersection(s1.begin(), s1.end(), s2.begin(),
//         s2.end(), v.begin());// де знаходиться останній елемент
//     set<int> s3(v.begin(), it);
//     print(s1);
//     print(s2);
//     print(s3);
// }