#include <iostream>
#include <numeric>

class Rational {
private:
    int numerator = 0, denominator = 1;
    void Normalize();
public:
    Rational() = default;
    Rational(int, int);
    void Print() const;

    int Numerator() const;
    int Denominator() const;

    Rational& operator += (const Rational&);
    Rational& operator += (const int&);
    Rational& operator -= (const Rational&);
    Rational& operator -= (const int&);
    Rational& operator *= (const Rational&);
    Rational& operator *= (const int&);
    Rational& operator /= (const Rational&);
    Rational& operator /= (const int&);

    Rational operator + ();
    Rational operator - ();
};

int Rational::Numerator() const {
    return numerator;
}

int Rational::Denominator() const {
    return denominator;
}
Rational& Rational::operator += (const Rational& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    Normalize();
    return *this;
}

Rational& Rational::operator += (const int& other) {
    numerator = numerator + other * denominator;
    Normalize();
    return *this;
}

Rational& Rational::operator -= (const Rational& other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
    Normalize();
    return *this;
}

Rational& Rational::operator -= (const int& other) {
    numerator = numerator - other * denominator;
    Normalize();
    return *this;
}

Rational& Rational::operator *= (const Rational& other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    Normalize();
    return *this;
}

Rational& Rational::operator *= (const int& other) {
    numerator *= other;
    Normalize();
    return *this;
}

Rational& Rational::operator /= (const Rational& other) {
    numerator *= other.denominator;
    denominator *= other.numerator;
    Normalize();
    return *this;
}

Rational& Rational::operator /= (const int& other) {
    denominator *= other;
    Normalize();
    return *this;
}

Rational Rational::operator + () {
    return *this;
}

Rational Rational::operator - () {
    return Rational(-numerator, denominator);
}

void Rational::Normalize() {
    int n = std::gcd(numerator, denominator);
    if (n != 1) {
        numerator /= n;
        denominator /= n;
    }
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }
    if (numerator == 0) denominator = 1;
}

Rational::Rational(int n, int d): numerator(n), denominator(d) {
    Normalize();
}

void Rational::Print() const {
    std::cout << numerator << " / " << denominator << std::endl;
}

bool operator == (const Rational& first, const Rational& second) {
    return first.Numerator() == second.Numerator() && first.Denominator() == second.Denominator();
}

bool operator == (const int& first, const Rational& second) {
    return first == second.Numerator() && second.Denominator() == 1;
}

bool operator == (const Rational& first, const int& second) {
    return second == first;
} 

template <typename T1, typename T2>
bool operator != (const T1& first, const T2& second) {
    return !(first == second);
}

template <typename T1, typename T2>
Rational operator + (const T1& first, const T2& last) {
    Rational r;
    r += first;
    r += last;
    return r;
}

template <typename T1, typename T2>
Rational operator - (const T1& first, const T2& last) {
    Rational r;
    r += first;
    r -= last;
    return r;
}

template <typename T1, typename T2>
Rational operator * (const T1& first, const T2& last) {
    Rational r(1, 1);
    r *= first;
    r *= last;
    return r;
}

template <typename T1, typename T2>
Rational operator / (const T1& first, const T2& last) {
    Rational r(1, 1);
    r *= first;
    r /= last;
    return r;
}

int main() {
    Rational r1(-1, 6);
    Rational r2 = 1 + r1;
    r2.Print();
}