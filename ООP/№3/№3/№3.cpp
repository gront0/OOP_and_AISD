#include <iostream>
#include "BoolVector.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "1) Конструктор по умолчанию:\n";
    BoolVector v1;
    std::cout << "v1 (пустой): '" << v1 << "' размер=" << v1.getSize() << "\n\n";

    std::cout << "2) Конструктор (размер, значение):\n";
    BoolVector v2(5, true);
    std::cout << "v2 (5 единиц): '" << v2 << "' размер=" << v2.getSize() << "\n\n";

    std::cout << "3) Конструктор из C-строки:\n";
    BoolVector v3("10110");
    std::cout << "v3 ('10110'): '" << v3 << "' размер=" << v3.getSize() << "\n\n";

    std::cout << "4) Конструктор копирования и оператор присваивания:\n";
    BoolVector v4(v3);
    BoolVector v5;
    v5 = v2;
    std::cout << "v4 (копия v3): '" << v4 << "'\n";
    std::cout << "v5 (присвоено от v2): '" << v5 << "'\n\n";

    std::cout << "5) Доступ по индексу (operator[]):\n";
    std::cout << "v3[2] = " << v3[2] << "\n\n";

    std::cout << "6) Инверсия всех битов (invert_all()):\n";
    v3.invert_all();
    std::cout << "v3 инвертирован: '" << v3 << "'\n\n";

    std::cout << "7) Инверсия одного бита (invert(i)) и установка значения (set(i)):\n";
    v3.invert(1);
    std::cout << "v3 после invert(1): '" << v3 << "'\n";
    v3.set(2, true);
    std::cout << "v3 после set(2, true): '" << v3 << "'\n\n";

    std::cout << "8) Вес (количество единиц):\n";
    std::cout << "v3 вес = " << v3.weight() << "\n\n";

    std::cout << "9) Обмен содержимым (swap()):\n";
    std::cout << "До swap v2='" << v2 << "', v3='" << v3 << "'\n";
    v2.swap(v3);
    std::cout << "После swap v2='" << v2 << "', v3='" << v3 << "'\n\n";

    std::cout << "10) Побитовые операции & | ^ :\n";
    BoolVector va("1100");
    BoolVector vb("1010");
    std::cout << "va = '" << va << "', vb='" << vb << "'\n";
    std::cout << "va & vb = '" << (va & vb) << "'\n";
    std::cout << "va | vb = '" << (va | vb) << "'\n";
    std::cout << "va ^ vb = '" << (va ^ vb) << "'\n\n";

    std::cout << "11) Побитовые сдвиги << >> :\n";
    BoolVector vs("1001");
    std::cout << "vs='" << vs << "'\n";
    std::cout << "vs << 2 = '" << (vs << 2) << "'\n";
    std::cout << "vs >> 1 = '" << (vs >> 1) << "'\n\n";

    std::cout << "12) Побитовая инверсия (~):\n";
    std::cout << "~vs = '" << (~vs) << "'\n\n";

    std::cout << "13) Ввод с консоли (введите биты):\n";
    BoolVector vin;
    std::cout << "Введите последовательность битов (например, 010101), затем пробел или Enter: ";
    std::cin >> vin;
    std::cout << "Вы ввели: '" << vin << "' размер=" << vin.size() << "\n";

    return 0;
}
