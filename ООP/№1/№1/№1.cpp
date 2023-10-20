#include <iostream>
#include <locale.h>
#include <vector>
#include "Fraction.h"

void testFractionConvert()
{
    Fraction f;
    std::vector<std::pair<double, int>> data = {
        {0, 0},
        {0.521, 0},
        {0.521, 1},
        {0.521, 2},
        {0.521, 3}
    };

    for (const auto& pair : data) {
        f.convertFromDouble(pair.first, pair.second);
        std::cout << "convertFromDouble(" << pair.first << ", " << pair.second << ") = ";
        f.output();
        std::cout << '\n';
    }

    std::cout << "testFractionConvert ended, press any key to continue...";
    getchar();
}

int main() {
    setlocale(LC_ALL, "Russian");
    testFractionConvert();

    Fraction f1(2, 3);
    Fraction f2(3, 4);

    Fraction sum = f1 + f2;
    Fraction diff = f1 - f2;
    Fraction product = f1 * f2;
    Fraction quotient = f1 / f2;

    cout << "Сумма: ";
    sum.output();
    cout << endl;

    cout << "Разность: ";
    diff.output();
    cout << endl;

    cout << "Произведение: ";
    product.output();
    cout << endl;

    cout << "Частное: ";
    quotient.output();
    cout << endl;

    if (f1 > f2)
        cout << "f1 больше, чем f2" << endl;
    else if (f1 < f2)
        cout << "f1 меньше, чем f2" << endl;
    else if (f1 == f2)
        cout << "f1 равно f2" << endl;
    else
        cout << "f1 не равно f2" << endl;

    cout << "Дробь в виде десятичного числа: " << f1.convertToDouble() << endl;

    return 0;
}