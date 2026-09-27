#include <iostream>

using namespace std;

class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex(double r, double i);
    Complex(const Complex& other);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    friend ostream& operator<<(ostream& os, const Complex& number);
};

Complex Complex::operator+(const Complex& other) const
{
		return Complex(real + other.real, imaginary + other.imaginary);
}

Complex Complex::operator-(const Complex& other) const
{
		return Complex(real - other.real, imaginary - other.imaginary);
}
Complex Complex::operator*(const Complex& other) const
{
    double newReal = real * other.real - imaginary * other.imaginary;
    double newImaginary = real * other.imaginary + imaginary * other.real;

    return Complex(newReal, newImaginary);
}
Complex Complex::operator/(const Complex& other) const
{
    
    double denominator = other.real * other.real + other.imaginary * other.imaginary;

    if (denominator == 0)
    {
        cout << "Blad: dzielenie przez zero!" << endl;
        return Complex(0, 0);
    }

    double newReal = (real * other.real + imaginary * other.imaginary) / denominator;
    double newImaginary = (imaginary * other.real - real * other.imaginary) / denominator;

    return Complex(newReal, newImaginary);
}
ostream& operator<<(ostream& os, const Complex& number)
{
    os << number.real;

    if (number.imaginary >= 0)
    {
        os << " + " << number.imaginary << "i";
    }
    else
    {
        os << " - " << -number.imaginary << "i";
    }

    return os;
}

Complex::Complex(double r, double i)
{
    real = r;
    imaginary = i;
}
Complex::Complex(const Complex& other)
{
    real = other.real;
    imaginary = other.imaginary;
}


int main()
{
    Complex a(3, 2);
    Complex b(4, 5);

    Complex c = a + b;
    Complex d = a - b;
    Complex e = a * b;
    Complex f = a / b;

    cout << "Dodawanie: " << c << endl;
    cout << "Odejmowanie: " << d << endl;
    cout << "Mnozenie: " << e << endl;
    cout << "Dzielenie: " << f << endl;

    Complex copy(a);
    cout << "Kopia a: " << copy << endl;

    return 0;
}