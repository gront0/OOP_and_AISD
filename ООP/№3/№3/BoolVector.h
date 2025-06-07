#pragma once

#include <iostream>
#include <algorithm>

class BoolVector {
private:
    bool* data;
    size_t size;

private:
    // Вычисление длины C-строки
    static size_t cstr_len(const char* s) {
        size_t len = 0;
        while (s[len] != '\0') ++len;
        return len;
    }

    // Добавление одного бита в конец (используется при вводе)
    void append(bool bit) {
        bool* new_data = new bool[size + 1];
        for (size_t i = 0; i < size; ++i) new_data[i] = data[i];
        new_data[size] = bit;
        delete[] data;
        data = new_data;
        ++size;
    }

public:
    // Конструкторы
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

    // Деструктор
    ~BoolVector() {
        delete[] data;
    }

    // Получение размера
    size_t getSize() const noexcept { return size; }

    // Обмен с другим вектором
    void swap(BoolVector& other) noexcept {
        bool* temp_data = data;
        data = other.data;
        other.data = temp_data;
        size_t temp_size = size;
        size = other.size;
        other.size = temp_size;
    }

    // Доступ по индексу (только чтение)
    bool operator[](size_t index) const { return data[index]; }

    // Ввод
    friend std::istream& operator>>(std::istream& in, BoolVector& v) {
        delete[] v.data;
        v.data = nullptr;
        v.size = 0;
        char c;
        while (in.get(c) && (c == '0' || c == '1')) {
            v.append(c == '1');
        }
        if (in) in.unget();
        return in;
    }

    // Вывод
    friend std::ostream& operator<<(std::ostream& out, const BoolVector& v) {
        for (size_t i = 0; i < v.size; ++i)
            out << (v.data[i] ? '1' : '0');
        return out;
    }

    // Инверсия всех битов
    void invert_all() noexcept {
        for (size_t i = 0; i < size; ++i) data[i] = !data[i];
    }

    // Инверсия одного бита
    void invert(size_t index) { data[index] = !data[index]; }

    // Установка i-го бита в заданное значение
    void set(size_t index, bool value) { data[index] = value; }

    // Вес (количество единиц)
    size_t weight() const noexcept {
        size_t count = 0;
        for (size_t i = 0; i < size; ++i) if (data[i]) ++count;
        return count;
    }

    // Побитовые операции
    friend BoolVector operator&(const BoolVector& a, const BoolVector& b) {
        size_t n = a.size < b.size ? a.size : b.size;
        BoolVector result(n, false);
        for (size_t i = 0; i < n; ++i) result.data[i] = a.data[i] & b.data[i];
        return result;
    }

    friend BoolVector operator|(const BoolVector& a, const BoolVector& b) {
        size_t n = a.size < b.size ? a.size : b.size;
        BoolVector result(n, false);
        for (size_t i = 0; i < n; ++i) result.data[i] = a.data[i] | b.data[i];
        return result;
    }

    friend BoolVector operator^(const BoolVector& a, const BoolVector& b) {
        size_t n = a.size < b.size ? a.size : b.size;
        BoolVector result(n, false);
        for (size_t i = 0; i < n; ++i) result.data[i] = a.data[i] ^ b.data[i];
        return result;
    }

    friend BoolVector operator<<(const BoolVector& v, size_t shift) {
        BoolVector result(v.size, false);
        for (size_t i = shift; i < v.size; ++i) result.data[i] = v.data[i - shift];
        return result;
    }

    friend BoolVector operator>>(const BoolVector& v, size_t shift) {
        BoolVector result(v.size, false);
        for (size_t i = 0; i + shift < v.size; ++i) result.data[i] = v.data[i + shift];
        return result;
    }

    friend BoolVector operator~(const BoolVector& v) {
        BoolVector result(v);
        result.invert_all();
        return result;
    }

    // Присваивание (копирование)
    BoolVector& operator=(const BoolVector& other) {
        if (this != &other) {
            BoolVector temp(other);
            swap(temp);
        }
        return *this;
    }

    // Присваивание (перемещение)
    BoolVector& operator=(BoolVector&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};