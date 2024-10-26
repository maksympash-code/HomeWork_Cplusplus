#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void processSentence(string& s) {
    stringstream ss(s);
    string word, prevWord;
    string result;

    while (ss >> word) {
        string prewWordLower = prevWord;
        transform(prewWordLower.begin(), prewWordLower.end(), prewWordLower.begin(), ::tolower);
        if (prewWordLower == "a" || prewWordLower == "an" || prewWordLower == "the") {
            word[0] = tolower(word[0]);
        }
        if (!result.empty()) {
            result += ' ';
        }
        result += word;
        prevWord = word;
    }
    cout << result << endl;
}

int main() {
    string s;

    cout << "Enter sentence:";
    getline(cin, s);

    processSentence(s);

    return 0;
}