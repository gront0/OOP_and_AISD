﻿#include <iostream>
#include "array.h"
#include <locale.h>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // создание объекта MyArray
    int MyArr[] = { 5, 2, 8, 3, 1 };
    MyArray<int> arr(MyArr, 5);
    
    int NyArr[] = { 10, 3, 0, 12, 1, 5, 7, 9 };
    MyArray<int> arr1(NyArr, 8);

    // вывод элементов массива
    cout << "Элементы массива: " << arr << endl;

    // сортировка элементов
    arr.sort();

    // вывод отсортированных элементов массива
    cout << "Отсортированные элементы массива: " << arr << endl;

    // вставка элемента по индексу
    int element, index;
    cout << "Введите элемент для вставки: ";
    cin >> element;
    cout << "Введите индекс для вставки: ";
    cin >> index;
    if (arr.insert(element, index)) {
        cout << "Элемент успешно вставлен" << endl;
    }
    else {
        cout << "Неверный индекс" << endl;
    }

    // вывод элементов массива после вставки
    cout << "Элементы массива после вставки: " << arr << endl;

    // удаление элемента по индексу
    cout << "Введите индекс для удаления элемента: ";
    cin >> index;
    if (arr.remove(index)) {
        cout << "Элемент успешно удален" << endl;
    }
    else {
        cout << "Неверный индекс" << endl;
    }

    // вывод элементов массива после удаления
    cout << "Элементы массива после удаления: " << arr << endl;

    // удаление элемента по значению
    cout << "Введите значение элемента для удаления: ";
    cin >> element;
    if (arr.removeOne(element)) {
        cout << "Элемент успешно удален" << endl;
    }
    else {
        cout << "Элемент не найден в массиве" << endl;
    }

    // вывод элементов массива после удаления по значению
    cout << "Элементы массива после удаления по значению: " << arr << endl;

    // удаление всех элементов с заданным значением
    cout << "Введите элемент для удаления всех вхождений: ";
    cin >> element;
    arr.removeAll(element);

    // вывод элементов массива после удаления всех вхождений
    cout << "Элементы массива после удаления всех вхождений: " << arr << endl;

    // поиск максимального элемента
    int maxElement = arr.findMax();
    cout << "Максимальный элемент: " << maxElement << endl;

    // поиск минимального элемента
    int minElement = arr.findMin();
    cout << "Минимальный элемент: " << minElement << endl;


    // итерация по массиву и вывод элементов
    std::cout << "Элементы:";
    for (int* it = arr1.begin(); it != arr1.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // вставка элемента перед итератором
    int newElement = 6;
    arr1.insertBefore(arr1.begin() + 2, newElement);
    std::cout << "После вставки итератором (3 эл.):";
    for (int* it = arr1.begin(); it != arr1.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // удаление элемента с помощью итератора
    arr1.erase(arr1.begin() + 1);
    std::cout << "После удаления итератором (второй эл.):";
    for (int* it = arr1.begin(); it != arr1.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Удаление диапазона элементов
    auto start = arr1.begin() + 1;
    auto end = arr1.begin() + 4;

    arr1.eraseRange(start, end);

    std::cout << "Массив после удаления диапазона:";
    for (int* it = arr1.begin(); it != arr1.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // перегрузка оператора присваивания
    MyArray<int> anotherArray;
    anotherArray = arr1;
    std::cout << "копия массива:";
    for (int* it = anotherArray.begin(); it != anotherArray.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // перегрузка оператора добавления элемента в конец массива
    int newElement2 = 7;
    anotherArray += newElement2;
    std::cout << "Массив после добавления в конец:";
    for (int* it = anotherArray.begin(); it != anotherArray.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    // Перегрузка оператора сложения (конкатенации) с другим массивом
    int arr2[] = { 8, 9, 10 };
    MyArray<int> newArray(arr2, 3);
    MyArray<int> concatenatedArray = anotherArray + newArray;
    std::cout << "После конкатенации:";
    for (int* it = concatenatedArray.begin(); it != concatenatedArray.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;

    return 0;
}