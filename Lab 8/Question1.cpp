#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    Complex operator + (const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator - (const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator * (const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    Complex operator / (const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        double r = (real * other.real + imag * other.imag) / denom;
        double i = (imag * other.real - real * other.imag) / denom;
        return Complex(r, i);
    }

    friend ostream& operator << (ostream& out, const Complex& c) {
        out << "(" << c.real;
        if (c.imag >= 0) out << " + " << c.imag << "i)";
        else out << " - " << -c.imag << "i)";
        return out;
    }

    friend double magnitude(const Complex& c);
};

double manualSqrt(double number) {
    if (number <= 0) return 0;
    double guess = number;
    for (int i = 0; i < 20; i++) {
        guess = (guess + number / guess) / 2;
    }
    return guess;
}

double magnitude(const Complex& c) {
    return manualSqrt(c.real * c.real + c.imag * c.imag);
}

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);

    cout << "Complex Numbers:\n";
    cout << "c1 = " << c1 << "\n";
    cout << "c2 = " << c2 << "\n\n";

    cout << "Add: c1 + c2 = " << c1 + c2 << "\n";
    cout << "Subtract: c1 - c2 = " << c1 - c2 << "\n";
    cout << "Multiply: c1 * c2 = " << c1 * c2 << "\n";
    cout << "Divide: c1 / c2 = " << c1 / c2 << "\n\n";

    cout << "MAGNITUDE of c1 = " << magnitude(c1) << "\n";
    cout << "MAGNITUDE of c2 = " << magnitude(c2) << "\n";

    return 0;
}
