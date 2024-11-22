#include <iostream>
#include <vector>
#include <algorithm>

class BoolVector {
private:
    std::vector<bool> data;

public:
    BoolVector(size_t size, bool value = false) : data(size, value) {}

    void push_back(bool value) {
        data.push_back(value);
    }

    BoolVector conjunction(const BoolVector& other) const {
        size_t size = std::min(data.size(), other.data.size());
        BoolVector result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] && other.data[i];
        }
        return result;
    }

    BoolVector disjunction(const BoolVector& other) const {
        size_t size = std::min(data.size(), other.data.size());
        BoolVector result(size);
        for (size_t i = 0; i < size; ++i) {
            result.data[i] = data[i] || other.data[i];
        }
        return result;
    }

    BoolVector negation() const {
        BoolVector result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = !data[i];
        }
        return result;
    }

    size_t count_ones() const {
        return std::count(data.begin(), data.end(), true);
    }

    size_t count_zeros() const {
        return std::count(data.begin(), data.end(), false);
    }

    void print() const {
        for (bool value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    BoolVector vec1(5, true);
    BoolVector vec2(5, false);

    vec2.push_back(true);

    std::cout << "Vector 1: ";
    vec1.print();

    std::cout << "Vector 2: ";
    vec2.print();

    BoolVector and_result = vec1.conjunction(vec2);
    BoolVector or_result = vec1.disjunction(vec2);
    BoolVector not_result = vec1.negation();

    std::cout << "\nAND (Conjunction): ";
    and_result.print();

    std::cout << "OR (Disjunction): ";
    or_result.print();

    std::cout << "NOT (Negation): ";
    not_result.print();

    std::cout << "\nVector 1: " << vec1.count_ones() << " ones, " << vec1.count_zeros() << " zeros\n";
    std::cout << "Vector 2: " << vec2.count_ones() << " ones, " << vec2.count_zeros() << " zeros\n";

    return 0;
}
