#include <iostream>
#include <string>
#include "Fraction.h"

void printFraction(Fraction fraction)
{
	std::cout << fraction.numerator << '/' << fraction.denominator << std::endl;
}

Fraction summaFraction(Fraction fraction1, Fraction fraction2)
{
	Fraction result;

	result.numerator = (fraction1.numerator * fraction2.denominator) + (fraction2.numerator * fraction1.denominator);
	result.denominator = fraction1.denominator * fraction2.denominator;
		return result;
}

int main()
{
	Fraction fraction, fraction1, fraction2, result;
	fraction.numerator = 3;
	fraction.denominator = 2;
	fraction1.numerator = 4;
	fraction1.denominator = 7;
	fraction2.numerator = 5;
	fraction2.denominator = 9;

	result = summaFraction(fraction1, fraction2);
	printFraction(fraction);
	
	std::cout << result.numerator << '/' << result.denominator << std::endl;

	return 0;
}