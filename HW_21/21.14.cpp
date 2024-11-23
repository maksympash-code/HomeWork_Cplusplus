#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <sstream>

using namespace std;

int monthToNumber(const string& month) {
    map<string, int> monthMap = {
        {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4},
        {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8},
        {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
    };
    if (isdigit(month[0])) {
        return stoi(month);
    }
    return monthMap[month];
}

struct Date {
    int day;
    int month;
    int year;

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

// Функція для виведення дати у потрібному форматі
ostream& operator<<(ostream& os, const Date& date) {
    os << date.year << "/" << date.month << "/" << date.day;
    return os;
}

// int main() {
//     ifstream inputFile("B:/C++/HomeWork/HW_21/dates.txt");
//     if (!inputFile.is_open()) {
//         cerr << "Unable to open file." << endl;
//         return 1;
//     }
//
//     set<Date> dates;
//     string line;
//
//     while (getline(inputFile, line)) {
//         stringstream ss(line);
//         int day, year;
//         string monthStr;
//         ss >> day >> monthStr >> year;
//
//         int month = monthToNumber(monthStr);
//         dates.insert({day, month, year});
//     }
//
//     inputFile.close();
//
//     cout << "Sorted dates without duplicates:" << endl;
//     for (const auto& date : dates) {
//         cout << date << endl;
//     }
//
//     return 0;
// }
