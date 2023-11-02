#include <iostream>
#include <vector>
#include <locale.h>
using namespace std;

void shellSort(vector<int>& arr) {

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

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> arr = { 9, 5, 2, 6, 1, 8, 3, 7, 4 };
    
    cout << "Исходный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    shellSort(arr);

    cout << "Отсортированный массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    if (isSorted(arr)) {
        cout << "Массив отсортирован." << endl;
    }
    else {
        cout << "Массив не отсортирован." << endl;
    }

    return 0;
}