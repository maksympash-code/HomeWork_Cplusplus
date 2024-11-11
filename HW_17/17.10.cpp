#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

class Vector {
private:
    double* elements;
    int size;
public:
    Vector(int n): size (n) {
        if (n <= 0)
            throw invalid_argument("Vector size must be positive.");
        elements = new double[n];
        for (int i = 0; i < n; i++) {
            elements[i] = 0;
        }
    }

    Vector (const Vector& other): size(other.size) {
        elements = new double[size];
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }

    ~Vector() {
        delete[] elements;
    }

    void setElement(int index, double value) {
        if (index < 0 || index >= 0)
            throw invalid_argument("Invalid index.");
        elements[index] = value;
    }

    double getElement(int index) const {
        if (index < 0 || index >= 0)
            throw out_of_range("Index out of bounds.");;
        return elements[index];
    }

    void inputVector() {
        cout << "Enter " << size << " elements for the vector:\n";
        for (int i = 0; i < size; i++) {
            cin >> elements[i];
            if (cin.fail())
                throw invalid_argument("Invalid input.");
        }
    }

    double product(const Vector& other) const {
        if (size != other.size)
            throw invalid_argument("Vectors must have the same size for dot product.");

        double result = 0;
        for (int i = 0; i < size; i++) {
            result += elements[i] * other.elements[i];
        }
        return result;
    }

    Vector crossProduct(const Vector& other) {
        if (size != 3 || other.size != 3)
            throw invalid_argument("Cross product is only defined for 3D vectors.");

        Vector result(3);

        result.elements[0] = elements[1] * other.elements[2] - elements[2] * other.elements[1];
        result.elements[1] = elements[2]* other.elements[0] - elements[0] * other.elements[2];
        result.elements[2] = elements[0] * other.elements[1] - elements[1] * other.elements[0];
        return result;
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        if (!file)
            throw runtime_error("Could not open file for writing.");

        for (int i = 0; i < size; i++)
            file << elements[i] << " ";

        file.close();
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file)
            throw runtime_error("Could not open file for reading.");

        for (int i = 0; i < size; i++) {
            file >> elements[i];
            if (file.fail())
                throw runtime_error("File contains invalid data.");
        }

        file.close();
    }

    friend ostream& operator<< (ostream& out, Vector& v) {
        for (int i = 0; i < v.size; i++) {
            out << v.elements[i] << " ";
        }
        return out;
    }

};

// int main() {
//     try {
//         int n;
//         cout << "Enter the size of the vector: ";
//         cin >> n;
//
//         Vector vec1(n);
//         vec1.inputVector();
//
//         cout << "Vector 1: " << vec1 << endl;
//
//         Vector vec2(n);
//         cout << "Enter elements for Vector 2:\n";
//         vec2.inputVector();
//
//         cout << "Dot Product of vec1 and vec2: " << vec1.product(vec2) << endl;
//
//         if (n == 3) {
//             Vector crossProd = vec1.crossProduct(vec2);
//             cout << "Cross Product of vec1 and vec2: " << crossProd << endl;
//         }
//
//         vec1.saveToFile("B:/C++/HomeWork/HW_17/vector.txt");
//         cout << "Vector saved to file.\n";
//
//         Vector vecFromFile(n);
//         vecFromFile.loadFromFile("B:/C++/HomeWork/HW_17/vector.txt");
//         cout << "Vector loaded from file: " << vecFromFile << endl;
//
//     } catch (const exception& e) {
//         cerr << "Error: " << e.what() << endl;
//     }
//
//     return 0;
// }