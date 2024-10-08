#include "10.06ж.h"
#include <iostream>

using namespace std;

struct point {
    double x;
    double y;
    double z;
};

struct Sphere {
    point center;
    double radius;
};

void input(Sphere &sphere) {
    cout << "Enter sphere points(x,y,z):";
    cin >> sphere.center.x >> sphere.center.y >> sphere.center.z;
    cout << "Enter sphere radius:";
    cin >> sphere.radius;
}

void print_sphere(const Sphere &sphere){
    cout << "x = " << sphere.center.x << ", y = " << sphere.center.y << ", z = " << sphere.center.z << endl;
    cout << "Radius =  " << sphere.radius << endl;
}

// int main() {
//     Sphere my_sphere;
//
//     input(my_sphere);
//
//     print_sphere(my_sphere);
//     return 0;
// }