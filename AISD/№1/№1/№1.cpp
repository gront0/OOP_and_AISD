#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <locale.h>

using namespace std;

// генерация случайного числа в заданном диапазоне
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// заполнение матрицы случайными значениями
void fillMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            }
            else {
                matrix[i][j] = randomInt(1, 100);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    int n = 5; // количество городов
    int startCity = 0; // начальный город

    vector<vector<int>> matrix(n, vector<int>(n));
    fillMatrix(matrix);

    return 0;
}
