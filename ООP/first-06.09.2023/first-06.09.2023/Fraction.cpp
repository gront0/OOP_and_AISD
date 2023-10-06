#include "Fraction.h"
#include <iostream>

Fraction Fraction::div(Fraction b)
{
    //Особый случай:
    if (denominator == 0) {
        std::cerr << "Fraction::div: error: b.numerator is 0, result will be 0/1.";
    }
    else {
        m_denominator = denominator;
    }

    if (m_denominator < 0) {
        m_numerator *= -1;
        m_denominator *= -1;
    }

    Fraction result;
    result.numerator = numerator * b.denominator;
    result.denominator = denominator * b.numerator;
    return result;
}