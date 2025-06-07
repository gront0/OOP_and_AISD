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

    // добавление одного бита в конец (для ввода)
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

    ~BoolVector() {
        delete[] data;
    }

    // Размер
    size_t getSize() const noexcept { return size; }

    // Обмен
    void swap(BoolVector& o) noexcept {
        bool* tmp = data;
        data = o.data;
        o.data = tmp;


        size_t s = size;
        size = o.size;
        o.size = s;
    }


    // Доступ по индексу (только чтение)
    bool operator[](size_t i) const { return data[i]; }


    // Ввод/вывод
    friend std::istream& operator>>(std::istream& is, BoolVector& v) {
        delete[] v.data;
        v.data = nullptr;
        v.size = 0;
        char c;
        while (is.get(c) && (c == '0' || c == '1')) {
            v.append(c == '1');
        }
        if (is) is.unget();
        return is;
    }


    friend std::ostream& operator<<(std::ostream& os, const BoolVector& v) {
        for (size_t i = 0; i < v.size; ++i)
            os << (v.data[i] ? '1' : '0');
        return os;
    }


    // Инверсия всего вектора
    void invert_all() noexcept {
        for (size_t i = 0; i < size; ++i) data[i] = !data[i];
    }

    // Инверсия i-го бита
    void invert(size_t i) { data[i] = !data[i]; }

    // Установка i-го бита
    void set(size_t i, bool value) { data[i] = value; }

    // Вес (количество единиц)
    size_t weight() const noexcept {
        size_t cnt = 0;
        for (size_t i = 0; i < size; ++i) if (data[i]) ++cnt;
        return cnt;
    }

    // Побитовые операции
    friend BoolVector operator&(const BoolVector& a, const BoolVector& b) {
        size_t n = a.size < b.size ? a.size : b.size;
        BoolVector r(n, false);
        for (size_t i = 0; i < n; ++i) r.data[i] = a.data[i] & b.data[i];
        return r;
    }

    friend BoolVector operator|(const BoolVector& a, const BoolVector& b) {
        size_t n = a.size < b.size ? a.size : b.size;
        BoolVector r(n, false);
        for (size_t i = 0; i < n; ++i) r.data[i] = a.data[i] | b.data[i];
        return r;
    }

    friend BoolVector operator^(const BoolVector& a, const BoolVector& b) {
        size_t n = a.size < b.size ? a.size : b.size;
        BoolVector r(n, false);
        for (size_t i = 0; i < n; ++i) r.data[i] = a.data[i] ^ b.data[i];
        return r;
    }


    friend BoolVector operator<<(const BoolVector& v, size_t s) {
        BoolVector r(v.size, false);
        for (size_t i = s; i < v.size; ++i) r.data[i] = v.data[i - s];
        return r;
    }


    friend BoolVector operator>>(const BoolVector& v, size_t s) {
        BoolVector r(v.size, false);
        for (size_t i = 0; i + s < v.size; ++i) r.data[i] = v.data[i + s];
        return r;
    }

    friend BoolVector operator~(const BoolVector& v) {
        BoolVector r(v);
        r.invert_all();
        return r;
    }

    // Присваивание
    BoolVector& operator=(const BoolVector& o) {
        if (this != &o) {
            BoolVector tmp(o);
            swap(tmp);
        }
        return *this;
    }

    BoolVector& operator=(BoolVector&& o) noexcept {
        if (this != &o) {
            delete[] data;
            data = o.data;
            size = o.size;
            o.data = nullptr;
            o.size = 0;
        }
        return *this;
    }
};