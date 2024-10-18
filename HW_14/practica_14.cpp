#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

double evaluateExpression(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open the file." << endl;
        exit(1);
    }

    double result = 0.0, number = 0.0;
    char sign = '+';
    string line, token;

    getline(file, line);
    stringstream ss(line);

    while (ss >> token) {
        if (token == "+" || token == "-") {
            sign = token[0];
        } else {
            number = stod(token);
            if (sign == '+') {
                result += number;
            } else if (sign == '-') {
                result -= number;
            }
        }
    }

    file.close();
    return result;
}


string decryptWord(const string& word) {
    string decrypted = word;
    reverse(decrypted.begin(), decrypted.end());
    return decrypted;
}

void decryptFile(const string& inputFilename, const string& outputFilename) {
    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);

    if (!inputFile) {
        cerr << "Error: Could not open the input file." << endl;
        exit(1);
    }

    if (!outputFile) {
        cerr << "Error: Could not open the output file." << endl;
        exit(1);
    }

    string line, word;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        bool firstWord = true;

        while (ss >> word) {
            if (!firstWord) {
                outputFile << " ";
            }
            outputFile << decryptWord(word);
            firstWord = false;
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();
    cout << "Decryption completed successfully!" << endl;
}

struct Student {
    string name;
    int course;
    string group;
    vector<int> grades;
};

double avarageGrade(const vector<int>& grades) {
    int sum = 0;
    for (int i = 0; i < grades.size(); i++) {
        sum += grades[i];
    }
    return static_cast<double>(sum) / grades.size();
}

vector<Student> readStudentsFromFile(const string& filename) {
    ifstream file(filename);
    vector<Student> students;

    if (!file) {
        cout << "Error: Could not open the file." << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student student;

        getline(ss, student.name, ',');
        ss >> student.course;
        ss.ignore();
        getline(ss, student.group, ',');

        int grade;
        while (ss >> grade) {
            student.grades.push_back(grade);
            if (ss.peek() == ',')
                ss.ignore();
        }
        students.push_back(student);
    }

    file.close();
    return students;
}

string findWorstStudent(const vector<Student>& students) {
    double minAverageGrade = numeric_limits<double>::max();
    string worstStudent;

    // for (const Student& student : students) {
    //     double averageGrade = averageGrade(student.grades);
    //     if (averageGrade < minAverageGrade) {
    //         minAverageGrade = averageGrade;
    //         worstStudent = student.name;
    //     }
    // }
    return worstStudent;
}
// int main() {
//
//     string fileName = "B:/C++/HomeWork/HW_14/students.txt";
//
//     vector<Student> students = readStudentsFromFile(fileName);
//
//     string WorstStudent = findWorstStudent(students);
//     cout << WorstStudent << endl;
//
//
//     // string inputFilename = "B:/C++/HomeWork/HW_14/encrypted.txt";
//     // string outputFilename = "B:/C++/HomeWork/HW_14/decrypted.txt";
//     //
//     // decryptFile(inputFilename, outputFilename);
//
//     // string filename = "B:/C++/HomeWork/HW_14/expression.txt";
//     //
//     // double result = evaluateExpression(filename);
//     // cout << "Result: " << result << endl;
//     return 0;
// }