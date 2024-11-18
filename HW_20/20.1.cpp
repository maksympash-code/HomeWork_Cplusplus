#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

ostream& operator<<(ostream& cout, const map<string, int>& m) {
    cout << "{ ";
    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << ", ";
    }
    cout << "}";
    return cout;
}

// int main() {
//     ifstream f("B:/C++/HomeWork/HW_20/tetx.txt");
//     if (!f.is_open()) {
//         cout << "File isn't open" << endl;
//         return 1;
//     }
//
//     map<string, int> count;
//     string word;
//
//     while (f >> word) {
//         ++count[word];
//     }
//
//     f.close();
//
//     cout << count << endl;
//
//     return 0;
//}
