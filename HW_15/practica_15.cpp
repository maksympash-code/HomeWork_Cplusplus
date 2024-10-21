#include "practica_15.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Rational {
private:
    int numer;
    int denom;
    void init(int n, int d) {
        if (d <= 0) {
            throw logic_error("Zero or negative denominator");
        }
        numer = n;
        denom = d;
        reduce();
    }

    void reduce() {
        int d = gcd(numer, denom);
        numer /= d;
        denom /= d;
    }

public:

    Rational(int numer, int denom) {
        init(numer, denom);
    }
    Rational(): numer(1), denom(1){}// ініціалізуємо 1
    Rational(int numer): numer(numer), denom(1){}
    Rational(const Rational& r): Rational(r.numer, r.denom) {}

    static Rational random() {
        int n = rand() % 200 - 100;
        int d = rand() % 100 + 1;
        return Rational(n, d);
    }

    void print(ostream& out = cout) const {
        out << numer << '/' << denom;
    }

    void input(istream& inp = cin) {
        int n, d;
        inp >> n;
        inp.ignore(256, '/');
        inp >> d;
        init(n, d);
    }

    void add(const Rational& other) {
        numer = numer * other.denom + other.numer * denom;
        denom = denom * other.denom;
        reduce();
    }

    void mul(const Rational& other) {
        numer *= other.numer;
        denom *= other.denom;
        reduce();
    }

    Rational operator+ () const{return Rational(*this);}
    Rational operator- () const{return Rational(-numer, denom);}

    Rational operator+ (const Rational& other) const {
        Rational result(*this);
        result.add(other);
        return result;
    }

    static int abs(int x) {
        return (x < 0) ? -x : x;
    }

    static int gcd(int a, int b){
        while (b > 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    friend ostream& operator<<(ostream& out, const Rational& r) {
        r.print(out);
        return out;
    }

    friend istream& operator>>(istream& inp, Rational& r) {
        r.input(inp);
        return inp;
    }

    friend Rational operator- (const Rational& self, const Rational& other) {
        Rational result(self);
        result.add(-other);
        return result;
    }
};


int main() {
    srand(time(nullptr));

    int N = 4;
    Rational array[N] = {
        Rational(1,2),
        Rational(5),
        Rational(),
        Rational::random()
    };
    // cin >> array[0];
    // array[0].input();
    // array[0] = array[0] + Rational(1,3);
    array[0] = array[0] - Rational(1,3);
    for (int i = 0; i < N; i ++) {
        cout << array[i] << endl;
    }

    return 0;
}