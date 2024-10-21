#include "5.09в.h"
#include <iostream>

using namespace std;

double solve_v(int i) {
    if (i == 0 || i == 1)
        return 0;
    else if (i == 2)
        return 1.5;

    double v_0 = 0;  // v_0 = 0
    double v_1 = 0;  // v_1 = 0
    double v_2 = 1.5;  // v_2 = 1.5
    double v_3 = 0;

    for (int k = 3; k <= i; k++) {
        v_3 = ((k - 2) / (double)((k - 3) * (k - 3) + 1)) + v_2 - 2 * v_1 * v_0 + 1;

        v_0 = v_1;
        v_1 = v_2;
        v_2 = v_3;
    }

    return v_3;
}
