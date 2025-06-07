#pragma once


#include <iostream>
#include <algorithm>


class BoolVector {
private:
    bool* data;
    size_t size;


private:
    // добавление одного бита в конец (для ввода)
    void append(bool bit) {
        bool* new_data = new bool[size + 1];
        for (size_t i = 0; i < size; ++i) new_data[i] = data[i];
        new_data[size] = bit;
        delete[] data;
        data = new_data;
        ++size;
    }
};