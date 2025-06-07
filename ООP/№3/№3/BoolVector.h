#pragma once


#include <iostream>
#include <algorithm>


class BoolVector {
private:
    bool* data;
    size_t size;


private:
    // вычисление длины C-строки
    static size_t cstr_len(const char* s) {
        size_t len = 0;
        while (s[len] != '\0') ++len;
        return len;
    }


    // добавление одного бита в конец (дл€ ввода)
    void append(bool bit) {
        bool* new_data = new bool[size + 1];
        for (size_t i = 0; i < size; ++i) new_data[i] = data[i];
        new_data[size] = bit;
        delete[] data;
        data = new_data;
        ++size;
    }

public:
    //  онструкторы
    BoolVector() : data(nullptr), size(0) {}

    BoolVector(size_t n, bool value) : data(new bool[n]), size(n) {
        for (size_t i = 0; i < n; ++i) data[i] = value;
    }

    BoolVector(const char* cstr) : data(nullptr), size(0) {
        size_t len = cstr_len(cstr);
        data = new bool[len];
        size = len;
        for (size_t i = 0; i < size; ++i) {
            data[i] = (cstr[i] == '1');
        }
    }

    BoolVector(const BoolVector& other) : data(new bool[other.size]), size(other.size) {
        for (size_t i = 0; i < size; ++i) data[i] = other.data[i];
    }

    BoolVector(BoolVector&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    ~BoolVector() {
        delete[] data;
    }

};