#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

set<string> readWords(const string& filename) {
    ifstream file(filename);
    set<string> words;
    string word;
    while (file >> word) {
        words.insert(word);
    }
    return words;
}

// int main() {
//     string file1 = "B:/C++/HomeWork/HW_20/file1.txt";
//     string file2 = "B:/C++/HomeWork/HW_20/file2.txt";
//
//     // Читання слів з двох файлів
//     set<string> words1 = readWords(file1);
//     set<string> words2 = readWords(file2);
//
//     // Знаходження спільних слів (перетин)
//     set<string> intersection;
//     set_intersection(words1.begin(), words1.end(), words2.begin(), words2.end(),
//                      inserter(intersection, intersection.begin()));
//
//     cout << "Spilni: " << endl;
//     for (const auto& word : intersection) {
//         cout << word << endl;
//     }
//
//     // Знаходження слів, які не є спільними (симетрична різниця)
//     set<string> symmetric_difference;
//     set_symmetric_difference(words1.begin(), words1.end(), words2.begin(), words2.end(),
//                              inserter(symmetric_difference, symmetric_difference.begin()));
//
//     cout << "\nNo spilni: " << endl;
//     for (const auto& word : symmetric_difference) {
//         cout << word << endl;
//     }
//
//     return 0;
// }
