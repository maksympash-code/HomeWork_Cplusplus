#include <iostream>
#include "practica_7.h"

#include <bitset>
#include <cstdint>

using namespace std;

const int max_size = 20;
void test() {
    uint32_t x = 0x0F070301;
    cout << bitset<32>(x) << endl;
    uint8_t* ptr = (uint8_t*) &x;
    // printf("%p\n", ptr);
    for (int i = -3; i < 4; i++) {
        cout << bitset<8>(*(ptr + i)) << endl;
    }
}

void endian() {
    uint32_t x = 1;
    uint8_t* ptr = (uint8_t*) &x;
    if (*ptr)
        cout <<  "little endian" << endl;
    else if (*(ptr + 3))
        cout <<  "big endian" << endl;
    else
        cout << "Middle endion" << endl;
}

// void print(int* arr, int n) {
//     for (int i = 0; i < n; i++) {
//         printf("%li ", arr[i]);
//     }
// }

// void input.txt(int* arr, int n) {
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
// }

void exercize_1(int* arr, int n, float number) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < number)
            count++;
        else
            break;
    }
    cout << count << endl;
}

void exercize_5(int arr[], int size, int &even, int &odd) {
    even = 0;
    odd = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
}

void input_vector(double vec[], int size) {
    for (int i = 0; i < size; i++)
        cin >> vec[i];
}

void output_vector(double* vec, int size) {
    for (int i = 0; i < size; i++) {
        cout << vec[i] << ' ';
    }
    cout << endl;
}

void sum_vectors(const double vec1[], const double vec2[], double result[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = vec1[i] + vec2[i];
    }
}
void scalar(const double vec1[], const double vec2[], int size) {
    double product = 0;
    for (int i = 0; i < size; i++) {
        product += vec1[i] * vec2[i];
    }
    cout << product << endl;
}
// int main() {
//     int n;
//     double vec1[max_size];
//     double vec2[max_size];
//     double result[max_size];
//     cout << "Enter n(n < 20 and n >= 0): ";
//     cin >> n;
//
//     if (n <= 0 || n >= 20) {
//         cout << "Invalid input.txt" << endl;
//         return 1;
//     }
//
//
//     cout << "Enter number of vector_1: ";
//     input_vector(vec1, n);
//
//     cout << "Enter number of vector_2: ";
//     input_vector(vec2, n);
//
//     sum_vectors(vec1,vec2,result, n);
//     cout << "Result sum_vectors: ";
//     output_vector(result, n);
//
//     cout << "Scalar: ";
//     scalar(vec1, vec2, n);
//     // const int max_size = 50;
//     // int arr[max_size];
//     // int count = 0, even, odd;
//     //
//     // cout << "Enter integer numbers: ";
//     // for (int i = 0; i < max_size; i++) {
//     //     int num;
//     //     cin >> num;
//     //
//     //     if (num == 0)
//     //         break;
//     //
//     //     arr[count++] = num;
//     // }
//     //
//     // exercize_5(arr, count, even, odd);
//     //
//     // cout << "Numbers after even numbers: " << even << endl;
//     // cout << "Numbers after odd numbers: " << odd << endl;
//
//     // float number;
//     // cin >> number;
//
//     //exercize_1(arr, n, number);
//     //
//     // input.txt(arr, n + 5);
//     // print(arr, n);
//     // printf("\n%lu", sizeof(arr) / sizeof(arr[0]));
//     // printf("%p\n", arr);
//     // for (int i = 0; i < n; i++) {
//     //     printf("%p %p\n", &arr[i], arr + i);
//     // }
//     return 0;
//}