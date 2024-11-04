#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

class Figure {
public:
    virtual double area() = 0;
    virtual double perimetr() = 0;
    virtual pair<double,double>center() const = 0;
};

class Rectangle: public Figure {
private:
    double x,y; // координати лівого верхнього кута
    double width, heighth;
public:
    Rectangle(double x, double y, double width, double heighth): x(x), y(y), width(width), heighth(heighth) {}

    double area() override{
        return width * heighth;
    }

    double perimetr() override {
        return (width + heighth) * 2;
    }

    pair<double, double>center() const override{
        return {x + width / 2, y - heighth / 2};
    }

    // Чи перетинаються 2 прямокутники
    bool intersects(const Rectangle& other) {
        return !(x + width < other.x || other.x + other.width < x || other.y - other.heighth > y || y - heighth > other.y);
    }
};

class Triangle: public Figure {
private:
    double x1, y1;
    double base; // довжина основи
    double angle1, angle2; // кути на основі

    // Обчислення 3 вершини
    pair<double, double> calculateTopVertex() const{
        double x2 = x1 + base, y2 = y1;

        double heighth = base * tan(angle1) * tan(angle2) / (tan(angle1) + tan(angle2));

        double x3 = x1 + base / 2;
        double y3 = y1 + heighth;

        return {x3, y3};
    }
public:
    Triangle(double x1, double y1, double base, double a1, double a2) : x1(x1), y1(y1), base(base), angle1(a1), angle2(a2) {}


    double area() override{
        double heighth = base * tan(angle1) * tan(angle2) / (tan(angle1) + tan(angle2));
        return 0.5 * heighth * base;
    }

    double perimetr() override {
        auto [x3, y3] = calculateTopVertex();
        double sideA = base;
        double sideB = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
        double sideC = sqrt(pow((x1 + base) - x3, 2) + pow(y1 - y3, 2));
        return sideA + sideB + sideC;
    }

    pair<double, double>center() const override{
        auto [x3, y3] = calculateTopVertex();
        double cx = (x1 + (x1 + base) + x3) / 3;
        double cy = (y1 + y1 + y3) / 3;
        return {cx, cy};
    }
};

class Ellipse : public Figure {
private:
    double x1, y1; // перший фокус
    double x2, y2; // другий фокус
    double majorRadius; // велика піввісь
    double minorRadius; // мала піввісь

public:
    Ellipse(double x1, double y1, double x2, double y2, double majorRadius, double minorRadius)
        : x1(x1), y1(y1), x2(x2), y2(y2), majorRadius(majorRadius), minorRadius(minorRadius) {}

    double area() override{
        return M_PI * majorRadius * minorRadius;
    }

    double perimetr() override{
        double a = majorRadius;
        double b = minorRadius;
        return M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b))); // наближений периметр
    }

    pair<double, double> center() const override {
        return {(x1 + x2) / 2, (y1 + y2) / 2};
    }
};

int main() {
    // Перевірка класу Rectangle
    Rectangle rect(0, 0, 10, 5);
    cout << "Rectangle Area: " << rect.area() << endl;
    cout << "Rectangle Perimeter: " << rect.perimetr() << endl;
    auto [rectCx, rectCy] = rect.center();
    cout << "Rectangle Center: (" << rectCx << ", " << rectCy << ")" << endl;

    // Перевірка класу Triangle
    Triangle tri(0, 0, 10, M_PI / 4, M_PI / 4);
    cout << "\nTriangle Area: " << tri.area() << endl;
    cout << "Triangle Perimeter: " << tri.perimetr() << endl;
    auto [triCx, triCy] = tri.center();
    cout << "Triangle Center: (" << triCx << ", " << triCy << ")" << endl;

    // Перевірка класу Ellipse
    Ellipse ellipse(0, 0, 4, 0, 5, 3);
    cout << "\nEllipse Area: " << ellipse.area() << endl;
    cout << "Ellipse Perimeter (Approx.): " << ellipse.perimetr() << endl;
    auto [ellipseCx, ellipseCy] = ellipse.center();
    cout << "Ellipse Center: (" << ellipseCx << ", " << ellipseCy << ")" << endl;

    return 0;
}