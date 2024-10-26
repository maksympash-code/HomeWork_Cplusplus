#include "13.14.h"
#include <iostream>
#include <string>

using namespace std;

int countWord(const string& text, const string& word) {
    int count = 0;
    size_t pos = text.find(word);

    while (pos != string::npos) {
        bool isWord = (pos == 0 || isspace(text[pos - 1]) || (pos + word.length() == text.length() || isspace(text[pos + word.length()])));

        if (isWord) {
            count++;
        }
        pos = text.find(word, pos + 1);
    }
    return count;
}

int countSubstring(const string& text, const string& substring) {
    int count = 0;
    size_t pos = text.find(substring);

    while (pos != string::npos) {
        count++;
        pos = text.find(substring, pos + 1);
    }
    return count;

}

// int main() {
//     string text, word, substring;
//
//     cout << "Enter text:";
//     getline(cin, text);
//
//     cout << "Enter word:";
//     cin >> word;
//
//     cout << "Enter substring:";
//     cin >> substring;
//
//     int cWord = countWord(text, word);
//     int cSubstring = countSubstring(text, substring);
//
//     cout << cWord << endl;
//     cout << cSubstring << endl;
//
//     return 0;
// }