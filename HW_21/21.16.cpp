#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template <typename InputIt, typename OutputIt, typename UnaryPredicate, typename UnaryOperation>
OutputIt transform_if(InputIt first, InputIt last, OutputIt d_first, UnaryPredicate pred, UnaryOperation op) {
    while (first != last) {
        if (pred(*first)) {
            *d_first = op(*first);
            ++d_first;
        }
        ++first;
    }
    return d_first;
}

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> output;

    auto is_even = [](int x) { return x % 2 == 0; };
    auto square = [](int x) { return x * x; };

    transform_if(input.begin(), input.end(), std::back_inserter(output), is_even, square);

    cout << "Transformed elements: ";
    for (const auto& elem : output) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
