#include "12.06.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

void processinput(istream &inp) {
    double value;

    while (!inp.eof()) {
        inp.ignore(256, '{');
        inp >> value;


        if (value <= 0){
            cout << "None" << endl;
        }else {
            cout << scientific << "Scientific:" << value << endl;
            cout << fixed << "Decimal:" << value  << endl;
            cout.width(5);
            cout << "log("<< value << ") = " << log(value) << endl;
        }
        inp.ignore(256, ',');
    }
}

// int main() {
//     string input = "{ 32, 44, 65 }, { 12, 84, 22 }";
//     stringstream ss(input);
//
//     processinput(ss);
//
//     return 0;
// }