#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class Matrix {
private:
    vector<vector<T>> data;

public:
    Matrix(size_t rows, size_t cols, T value = T()) : data(rows, vector<T>(cols, value)) {}

    size_t rows() const { return data.size(); }
    size_t cols() const { return data.empty() ? 0 : data[0].size(); }

    vector<T>& operator[](size_t index) { return data[index]; }
    const vector<T>& operator[](size_t index) const { return data[index]; }

    friend ostream& operator<<(ostream& os, const Matrix<T>& matrix) {
        for (const auto& row : matrix.data) {
            for (const auto& element : row) {
                os << element << " ";
            }
            os << endl;
        }
        return os;
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows() != other.rows() || cols() != other.cols()) {
            throw invalid_argument("Matrix dimensions must match for addition.");
        }
        Matrix<T> result(rows(), cols());
        for (size_t i = 0; i < rows(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                result[i][j] = data[i][j] + other[i][j];
            }
        }
        return result;
    }

    vector<T> operator*(const vector<T>& vec) const {
        if (cols() != vec.size()) {
            throw invalid_argument("Matrix columns must match vector size for multiplication.");
        }
        vector<T> result(rows(), T());
        for (size_t i = 0; i < rows(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                result[i] += data[i][j] * vec[j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (cols() != other.rows()) {
            throw invalid_argument("Matrix dimensions must align for multiplication.");
        }
        Matrix<T> result(rows(), other.cols());
        for (size_t i = 0; i < rows(); ++i) {
            for (size_t j = 0; j < other.cols(); ++j) {
                for (size_t k = 0; k < cols(); ++k) {
                    result[i][j] += data[i][k] * other[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    Matrix<int> mat1(2, 3, 1);
    Matrix<int> mat2(2, 3, 2);

    cout << "Matrix 1:\n" << mat1;
    cout << "Matrix 2:\n" << mat2;

    Matrix<int> sum = mat1 + mat2;
    cout << "Sum of matrices:\n" << sum;

    vector<int> vec = {1, 2, 3};
    vector<int> vec_result = mat1 * vec;
    cout << "Matrix 1 multiplied by vector:\n";
    for (int val : vec_result) {
        cout << val << " ";
    }
    cout << endl;

    Matrix<int> mat3(3, 2, 1);
    Matrix<int> product = mat1 * mat3;
    cout << "Product of matrices:\n" << product;

    Matrix<float> mat4(2, 2, 1.5f);
    Matrix<float> mat5(2, 2, 2.5f);
    Matrix<float> float_sum = mat4 + mat5;
    cout << "Sum of float matrices:\n" << float_sum;

    return 0;
}
