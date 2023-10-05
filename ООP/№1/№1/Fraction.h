#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;   // Числитель
    int denominator; // Знаменатель

public:
    // Конструкторы
    Fraction();
    Fraction(int num, int den);

    // Методы установления/получения числителя и знаменателя
    void setNumerator(int num);
    void setDenominator(int den);
    int getNumerator() const;
    int getDenominator() const;

    // Арифметические операции между дробями
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // Операции сравнения
    bool operator>(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;

    // Приведение дроби к несократимой
    void reduce();

    // Методы ввода/вывода в консоль
    void input();
    void output() const;

    // Уникальные методы
    double convertToDouble() const;
    Fraction convertFromDouble(double value, int precision);

private:
    // Метод для вычисления наибольшего общего делителя
    int computeGCD(int a, int b) const;
};
