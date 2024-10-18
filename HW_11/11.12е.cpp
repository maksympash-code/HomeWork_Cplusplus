#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Toy {
    string name;
    double price;
    int age_min;
    int age_max;
};

vector<Toy> readToys(const string& filename) {
    ifstream file(filename);
    vector<Toy> toys;

    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        exit(1);
    }

    Toy toy;
    while (file >> toy.name >> toy.price >> toy.age_min >> toy.age_max) {
        toys.push_back(toy);
    }

    file.close();
    return toys;
}

void writeToysToBinary(const Toy& toy1, const Toy& toy2) {
    ofstream output("result.bin", ios::binary);
    if (!output.is_open()) {
        cerr << "Error: Could not create the binary file." << endl;
        return;
    }

    output.write(reinterpret_cast<const char*>(&toy1), sizeof(Toy));
    output.write(reinterpret_cast<const char*>(&toy2), sizeof(Toy));
    output.close();
}

// Функція для пошуку двох іграшок з умовами
void findToysForAgeAndBudget(const vector<Toy>& toys, int age, double budget) {
    bool found = false;

    for (size_t i = 0; i < toys.size(); ++i) {
        for (size_t j = i + 1; j < toys.size(); ++j) {
            if (toys[i].age_min <= age && toys[i].age_max >= age &&
                toys[j].age_min <= age && toys[j].age_max >= age &&
                (toys[i].price + toys[j].price <= budget)) {

                cout << "Found toys: " << toys[i].name << " and " << toys[j].name
                     << " with total price: " << (toys[i].price + toys[j].price) << " UAH" << endl;

                writeToysToBinary(toys[i], toys[j]);
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) {
        cout << "No suitable toys found." << endl;
    }
}

int main() {
    string filename = "B:/C++/HomeWork/HW_11/toys.txt";

    vector<Toy> toys = readToys(filename);

    int age;
    double budget;
    cout << "Enter the age of the child: ";
    cin >> age;
    cout << "Enter the maximum budget (UAH): ";
    cin >> budget;

    findToysForAgeAndBudget(toys, age, budget);

    return 0;
}
