#include "practica_6.h"
#include <iostream>
#include <bitset>
#include <cstdint>

using namespace std;

long long exercice_6_1(int n){

    if(n >= 64) {
        cout << n << " is not a valid number (n >= 64)" << endl;
        return 1;
    }

    unsigned long long result = 1ULL << n;
    cout << "2^" << n << " = " << result << endl;
    return 0;
}

int exercice_6_2(int n, int k) {
    int result = n | (1 << k);
    cout <<"Result: " << result << endl;
}

long long exercice_6_3(unsigned long long m, int j) {

    if (j < 0 || j > 63) {
        cout << "The bit number must be in the range from 0 to 63." << endl;
        return 1;
    }

    unsigned long long result = m & ~(1ULL << j);
    cout << "Result in decimal format: " << result << endl;
    cout << "Result in hexadecimal format: " << hex << result << endl;
    return 0;
}

long long exercice_6_4(uint32_t number) {

    uint32_t first_8_bits = (number << 24) & 0xFF;

    uint32_t last_8_bits = number & 0xFF;

    uint32_t middle_bits = number & 0x00FFFF00;

    uint32_t result = last_8_bits << 24 | middle_bits | first_8_bits;

    cout << "Result in decimal format: " << result << endl;
    cout << "Result in hexadecimal format: " << hex << result << endl;
}

int exercice_6_5(int number) {
    int max = 0;
    int curent_max = 0;

    while (number > 0) {
        if (number & 1) {
            curent_max++;
            if (curent_max > max) {
                max = curent_max;
            }
        }else {
            curent_max = 0;
        }
        number >>= 1;
    }

    cout << "Max = " << max << endl;
}

void exercice_6_6_a(int x) {
    bool y = (x & (x - 1)) > 0;
    if (y) {
        cout << "The number " << x << " is not a power of two" << endl;
    }else {
        cout << "The number " << x << " is a power of two" << endl;
    }
}

void exercice_6_6_b(int x) {
    int y = x & (-x);
    cout << "The smallest set bit of the number " << x << " = " << y << endl;
}
int main() {

    // unsigned int n;
    //
    // cout << "Enter a number(n < 64): ";
    // cin >> n;
    //
    // exercice_6_1(n);



    // int n,k;
    // cout << "Enter n: " << endl;
    // cin >> n;
    // cout << "Enter k: " << endl;
    // cin >> k;
    //
    // exercice_6_2(n,k);



    // unsigned long m;
    // int j;
    //
    // cout << "Enter a 64-bit number m: ";
    // cin >> m;
    // cout << "Enter the number of bit j (from 0 to 63): ";
    // cin >> j;
    //
    // exercice_6_3(m, j);



    // uint32_t number;
    //
    // cout << "Enter a 32-bit number: ";
    // cin >> number;
    // exercice_6_4(number);



    // int number;
    //
    // cout << "Enter a number: ";
    // cin >> number;
    //
    // exercice_6_5(number);



    // int x;
    //
    // cout << "Enter a number: " << endl;
    // cin >> x;
    //
    // exercice_6_6_a(x);
    // exercice_6_6_b(x);


    return 0;
}