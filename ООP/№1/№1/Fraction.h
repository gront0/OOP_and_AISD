#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;   // ���������
    int denominator; // �����������

public:
    // ������������
    Fraction();
    Fraction(int num, int den);

    // ������ ������������/��������� ��������� � �����������
    void setNumerator(int num);
    void setDenominator(int den);
    int getNumerator() const;
    int getDenominator() const;

    // �������������� �������� ����� �������
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // �������� ���������
    bool operator>(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;

    // ���������� ����� � ������������
    void reduce();

    // ������ �����/������ � �������
    void input();
    void output() const;

    // ���������� ������
    double convertToDouble() const;
    Fraction convertFromDouble(double value, int precision);

private:
    // ����� ��� ���������� ����������� ������ ��������
    int computeGCD(int a, int b) const;
};