#pragma once

#include <iostream>
#include <algorithm>

template<typename T>
class MyArray {
private:
    T* data;
    size_t size;

public:
    // Конструкторы
    MyArray() : data(nullptr), size(0) {}

    MyArray(const T* arr, size_t arrSize) : size(arrSize) {
        data = new T[size];
        std::copy(arr, arr + size, data);
    }

    MyArray(const MyArray& other) : size(other.size) {
        data = new T[size];
        std::copy(other.data, other.data + size, data);
    }

    // Деструктор
    ~MyArray() {
        delete[] data;
    }

    // Получение размера массива
    size_t getSize() const {
        return size;
    }

    // Обмен содержимым с другим массивом
    void swap(MyArray& other) {
        std::swap(data, other.data);
        std::swap(size, other.size);
    }

    // Поиск элемента
    int find(const T& element) const {
        for (size_t i = 0; i < size; i++) {
            if (data[i] == element) {
                return i;
            }
        }
        return -1;
    }

    // Ввод элементов массива
    friend std::istream& operator>>(std::istream& is, MyArray& arr) {
        for (size_t i = 0; i < arr.size; i++) {
            is >> arr.data[i];
        }
        return is;
    }

    // Вывод элементов массива
    friend std::ostream& operator<<(std::ostream& os, const MyArray& arr) {
        for (size_t i = 0; i < arr.size; i++) {
            os << arr.data[i] << " ";
        }
        return os;
    }

    // Сортировка элементов
    void sort() {
        std::sort(data, data + size);
    }

    // Вставка элемента по индексу
    bool insert(const T& element, size_t index) {
        if (index > size) {
            return false; // Некорректный индекс
        }
        T* newData = new T[size + 1];
        std::copy(data, data + index, newData);
        newData[index] = element;
        std::copy(data + index, data + size, newData + index + 1);
        delete[] data;
        data = newData;
        size++;
        return true;
    }

    // Удаление элемента по индексу
    bool remove(size_t index) {
        if (index >= size) {
            return false; // Некорректный индекс
        }
        T* newData = new T[size - 1];
        std::copy(data, data + index, newData);
        std::copy(data + index + 1, data + size, newData + index);
        delete[] data;
        data = newData;
        size--;
        return true;
    }

    // Удаление элемента по значению (первое вхождение)
    bool removeZn(const T& element) {
        int index = find(element);
        if (index == -1) {
            return false; // Элемент отсутствует в массиве
        }
        return remove(index);
    }

    // Удаление всех элементов с заданным значением
    void removeAll(const T& element) {
        for (size_t i = 0; i < size; i++) {
            if (data[i] == element) {
                remove(i);
                i--; // Уменьшаем индекс, чтобы проверить текущий элемент еще раз
            }
        }
    }

    // Поиск максимального элемента
    T findMax() const {
        T maxElement = data[0];
        for (size_t i = 1; i < size; i++) {
            if (data[i] > maxElement) {
                maxElement = data[i];
            }
        }
        return maxElement;
    }

    // Поиск минимального элемента
    T findMin() const {
        T minElement = data[0];
        for (size_t i = 1; i < size; i++) {
            if (data[i] < minElement) {
                minElement = data[i];
            }
        }
        return minElement;
    }

    // Получение итератора на начало массива
    T* begin() const {
        return data;
    }

    // Получение итератора на конец массива
    T* end() const {
        return data + size;
    }

    // Вставка элемента перед итератором
    void insertBefore(T* iterator, const T& element) {
        size_t index = iterator - data;
        insert(element, index);
    }

    // Удаление элемента или диапазона элементов с помощью итераторов
    void erase(T* iterator) {
        size_t index = iterator - data;
        remove(index);
    }

    void erase(T* first, T* last) {
        size_t startIndex = first - data;
        size_t endIndex = last - data;
        for (size_t i = 0; i < endIndex - startIndex; i++) {
            remove(startIndex);
        }
    }

    // Перегрузка оператора получения ссылки на элемент по индексу
    T& operator[](size_t index) {
        return data[index];
    }

    // Перегрузка оператора присваивания
    MyArray& operator=(const MyArray& other) {
        if (this != &other) {
            MyArray temp(other);
            swap(temp);
        }
        return *this;
    }

    // Перегрузка оператора добавления элемента в конец массива
    MyArray& operator+(const T& element) {
        insert(element, size);
        return *this;
    }

    MyArray& operator+=(const T& element) {
        insert(element, size);
        return *this;
    }

    // Перегрузка оператора сложения (конкатенации) с другим массивом
    MyArray& operator+(const MyArray& other) {
        MyArray temp(*this);
        for (size_t i = 0; i < other.size; i++) {
            temp.insert(other.data[i], temp.size);
        }
        return temp;
    }

    MyArray& operator+=(const MyArray& other) {
        for (size_t i = 0; i < other.size; i++) {
            insert(other.data[i], size);
        }
        return *this;
    }

    // Перегрузка оператора сравнения
    bool operator==(const MyArray& other) const {
        if (size != other.size) {
            return false;
        }
        for (size_t i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const MyArray& other) const {
        return !(*this == other);
    }
};