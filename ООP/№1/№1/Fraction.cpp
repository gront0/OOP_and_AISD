#include "Fraction.h"
#include <iostream>

// Конструкторы
Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {}

// Методы установления/получения числителя и знаменателя
void Fraction::setNumerator(int num) { numerator = num; }

void Fraction::setDenominator(int den) { denominator = den; }

int Fraction::getNumerator() const { return numerator; }

int Fraction::getDenominator() const { return denominator; }

// Арифметические операции между дробями
Fraction Fraction::operator+(const Fraction& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator-(const Fraction& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator*(const Fraction& other) const {
    int num = numerator * other.numerator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction::operator/(const Fraction& other) const {
    int num = numerator * other.denominator;
    int den = denominator * other.numerator;
    return Fraction(num, den);
}

// Операции сравнения
bool Fraction::operator>(const Fraction& other) const {
    return (numerator * other.denominator) > (other.numerator * denominator);
}

bool Fraction::operator<(const Fraction& other) const {
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Fraction::operator==(const Fraction& other) const {
    return (numerator * other.denominator) == (other.numerator * denominator);
}

bool Fraction::operator!=(const Fraction& other) const {
    return (numerator * other.denominator) != (other.numerator * denominator);
}

// Приведение дроби к несократимой
void Fraction::reduce() {
    int gcd = computeGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

// Методы ввода/вывода в консоль
void Fraction::input() {
    std::cout << "Введите числитель: ";
    std::cin >> numerator;
    std::cout << "Введите знаменатель: ";
    std::cin >> denominator;
}

void Fraction::output() const {
    std::cout << numerator << "/" << denominator;
}

// Уникальные методы
double Fraction::convertToDouble() const {
    return static_cast<double>(numerator) / denominator;
}

Fraction Fraction::convertFromDouble(double value, int precision) {
    int num = static_cast<int>(value * precision);
    int den = precision;
    return Fraction(num, den);
}

// Метод для вычисления наибольшего общего делителя 
int Fraction::computeGCD(int a, int b) const {
    if (b == 0)
        return a;
    else
        return computeGCD(b, a % b);
}