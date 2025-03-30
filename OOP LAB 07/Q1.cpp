#include <iostream>
#include <algorithm> // For __gcd()
using namespace std;

class Fraction {
    int numerator, denominator;

    void simplify() {
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int n, int d) {
        if (d == 0) {
            cout << "Error: Denominator cannot be zero!" << endl;
            exit(1);
        }
        if (d < 0) {
            n = -n;
            d = -d;
        }
        numerator = n;
        denominator = d;
        simplify();
    }

    Fraction operator+(Fraction other) {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator-(Fraction other) {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator*(Fraction other) {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(Fraction other) {
        if (other.numerator == 0) {
            cout << "Error: Division by zero!" << endl;
            exit(1);
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(Fraction other) {
        return numerator * other.denominator == other.numerator * denominator;
    }

    bool operator!=(Fraction other) {
        return !(*this == other);
    }

    bool operator>(Fraction other) {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool operator<(Fraction other) {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>=(Fraction other) {
        return !(*this < other);
    }

    bool operator<=(Fraction other) {
        return !(*this > other);
    }

    void display() {
        cout << numerator << " / " << denominator << endl;
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(1, 2);

    Fraction f3;
    f3 = f1.operator+(f2);
    f3.display();

    cout << endl;

    f3 = f1.operator-(f2);
    f3.display();

    cout << endl;

    f3 = f1.operator*(f2);
    f3.display();

    cout << endl;

    f3 = f1 / f2;
    f3.display();

    cout << endl;

    if (f1 == f2) {
        cout << "both fractions are same" << endl;
    } else {
        cout << "both fractions are not same" << endl;
    }

    cout << endl;

    if (f1 != f2) {
        cout << "both fractions are not same" << endl;
    } else {
        cout << "both fractions are same" << endl;
    }

    cout << endl;

    if (f1 > f2) {
        cout << "f1 is greater" << endl;
    } else {
        cout << "f1 is smaller" << endl;
    }

    cout << endl;

    if (f1 < f2) {
        cout << "f1 is smaller" << endl;
    } else {
        cout << "f1 is greater" << endl;
    }

    cout << endl;

    if (f1 >= f2) {
        cout << "f1 is greater or equal" << endl;
    } else {
        cout << "f1 is smaller" << endl;
    }

    cout << endl;

    if (f1 <= f2) {
        cout << "f1 is smaller or equal" << endl;
    } else {
        cout << "f1 is greater" << endl;
    }
}
