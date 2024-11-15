#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class BlackBox {
private:
    vector<T> elements;
    int max_size = 100;
public:
    BlackBox() {
        srand(time(0));
    }

    BlackBox(T* arr, int size) {
        if (size > max_size)
            throw overflow_error("Array size exceeds max size of BlackBox");

        elements.assign(arr, arr + size);
        srand(time(0));
    }

    void push(const T& element) {
        if (elements.size() >= max_size) {
            throw overflow_error("BlackBox is full");
        }
        elements.push_back(element);
    }

    T pop() {
        if (elements.empty())
            throw underflow_error("BlackBox is empty");

        int random_index = rand() % elements.size();
        T element = elements[random_index];
        elements.erase(elements.begin() + random_index);
        return element;
    }

    T xpop() const {
        if (elements.empty())
            throw underflow_error("BlackBox is empty");

        int random_index = rand() % elements.size();
        return elements[random_index];
    }

};

// int main() {
//     try {
//         BlackBox<int> box;
//
//         for (int i = 0; i < 5; ++i) {
//             box.push(i * 10);
//         }
//
//         cout << "Random element (xrop): " << box.xpop() << endl;
//
//         cout << "Random element removed (pop): " << box.pop() << endl;
//
//     } catch (const exception& e) {
//         cerr << "Error: " << e.what() << endl;
//     }
//
//     return 0;
// }