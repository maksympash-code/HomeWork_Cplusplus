#include <iostream>
using namespace std;

class Car {
protected:
    double fuel;
    double mileage;
public:
    Car(double initialFuel): fuel(initialFuel), mileage(0){}

    virtual double fuelPerKm() const = 0;

    bool go(double distance) {
        double requiredFuel = distance * fuelPerKm();
        if (requiredFuel <= fuel) {
            fuel -= requiredFuel;
            mileage += distance;
            return true;
        }else{return false;}
    }
    double getFuel() const {return fuel;}
    double getMileage() const {return mileage;}

};

class Personal: public Car {
private:
    int passengers; // кількість пасажирів
public:
    Personal(double initialFuel, int passengers): Car(initialFuel), passengers(passengers){}
    double fuelPerKm() const override{
        double baseConsuption = 0.1;
        return baseConsuption * (1 + 0.1 * passengers);
    }
};

class Truck: public Car {
private:
    double load;
public:
    Truck(double initialFuel, double load): Car(initialFuel), load(load){}
    double fuelPerKm() const override {
        double baseConsuption = 0.25;
        return baseConsuption * (1 + 0.25 * load);
    }
};

// int main() {
//     Personal personalCar(20,3);
//     double distance = 50;
//
//     if (personalCar.go(distance)) {
//         cout << "Personal car passed " << distance << "km. The remaining fuel: " << personalCar.getFuel() << endl;
//     }else {
//         cout << "Insufficient fuel for a personal car for a distance " << distance  << "km." << endl;
//     }
//
//     Truck truck(50, 5);
//     if (truck.go(distance)) {
//         cout << "Truck passed " << distance << "km. The remaining fuel: " << truck.getFuel() << endl;
//     }else {
//         cout << "Not enough fuel for a truck to cover the distance " << distance << "km." << endl;
//     }
//
//     return 0;
// }