#include <iostream>
#include <vector>
#include <locale.h>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();

    // находим интервал между элементами, который будет уменьшаться после каждой итерации
    for (int gap = n / 2; gap > 0; gap /= 2) {

        // применяем алгоритм сортировки вставками для каждого интервала
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }

}

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> arr = { 9, 5, 2, 6, 1, 8, 3, 7, 4 };
    
    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    shellSort(arr);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}