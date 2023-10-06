#include <iostream>
#include <string>
#include "Fraction.h"

Fraction::Fraction()
{
	numerator = 1;
	denominator = 1;
}

Fraction::Fraction(int numerator, int denominator)
{
	numerator = numerator;
	denominator = denominator;
}

void Fraction::printFraction()
{
	std::cout << numerator << '/' << denominator;
}

int main()
{
	Fraction a, b, c[3, 2];
	a.print();
	b.print();
	c.print();

	return 0;
}