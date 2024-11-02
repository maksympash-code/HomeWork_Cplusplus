#include <iostream>
using namespace std;

class Human {
protected:
    string name;
public:
    Human(string name): name(name) {
        cout << "Human " << name << " created" << endl;
    }
    virtual ~Human() {
        cout << "Deleting Human" << name << endl;
    }

    virtual void print() {
        cout << name << endl;
    }

    void hello(){cout << "Hello from "; print(); cout << endl;}
};

class Student: public Human {
protected:
    int course;
    string univ;
public:
    Student(string name, int course, string univ):
    Human(name), course(course), univ(univ) {
        cout << "Creating Student " << name << endl;
    }
    virtual ~Student(){cout << "Deleting Stugent " << name << endl;}
    void print() override {cout << ' ' << univ << ' ' << course;}
};




// int main() {
//     const int N = 2;
//     Human* arr[N] = {
//         new Human("Bobser"),
//         new Student("Shaitan", 2, "KNU")
//     };
//     for (int i = 0; i < N; i++) {
//         arr[i] -> hello();
//     }
//     for (int i = 0; i < N; i++) {
//         delete arr[i];
//     }
//
//     return 0;
// }