#include "10.13б.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    string firstName;
    string lastName;
    char gender;
    Date birthDate;
    string position;
};

void input(Employee &employee) {
    cout << "Enter First Name:";
    cin >> employee.firstName;
    cout << "Enter Last Name:";
    cin >> employee.lastName;
    cout << "Enter Gender(M or F):";
    cin >> employee.gender;
    cout << "Enter Birth Date:";
    cin >> employee.birthDate.day >> employee.birthDate.month >> employee.birthDate.year;
    cout << "Enter Position:";
    cin >> employee.position;
}

void findEmployeesWithSameNames(const vector<Employee>& employees) {
    bool found = false;
    for (int i = 0; i < employees.size(); i++) {
        for (int j = i + 1; j < employees.size(); j++) {
            if (employees[i].firstName == employees[j].firstName) {
                found = true;
                cout << "Employees with the same first name: " << employees[i].firstName << endl;
                cout << employees[i].firstName << " " << employees[i].lastName << endl;
                cout << employees[j].firstName << " " << employees[j].lastName << endl;
            }
        }
    }

    if (!found) {
        cout << "No employees with the same first name found." << endl;
    }
}


int main() {
    int N;
    cout << "Enter number of employees:";
    cin >> N;

    vector<Employee> employees(N);

    for (int i = 0; i < N; i++) {
        cout << "Enter information for emploee "<< i + 1 << ":" << endl;
        input(employees[i]);
    }

    findEmployeesWithSameNames(employees);

    return 0;
}
