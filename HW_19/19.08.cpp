#include <iostream>
#include <list>
#include <cmath>

using namespace std;

class NumberList {
private:
    list<int> numbers;

public:
    void add(int value) {
        numbers.push_back(value);
    }

    void remove(int value) {
        numbers.remove(value);
    }

    int findClosest(int target) const {
        if (numbers.empty()) {
            throw runtime_error("The list is empty!");
        }

        int closest = *numbers.begin();
        int minDifference = abs(target - closest);

        for (int num : numbers) {
            int diff = abs(target - num);
            if (diff < minDifference) {
                closest = num;
                minDifference = diff;
            }
        }

        return closest;
    }

    void print() const {
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;
    }
};

// int main() {
//     NumberList numList;
//
//     numList.add(10);
//     numList.add(20);
//     numList.add(30);
//     numList.add(25);
//
//     cout << "List of numbers: ";
//     numList.print();
//
//     int target = 22;
//     try {
//         int closest = numList.findClosest(target);
//         cout << "Closest number to " << target << ": " << closest << endl;
//     } catch (const runtime_error& e) {
//         cout << e.what() << endl;
//     }
//
//     numList.remove(20);
//     cout << "List after removing 20: ";
//     numList.print();
//
//     return 0;
// }
