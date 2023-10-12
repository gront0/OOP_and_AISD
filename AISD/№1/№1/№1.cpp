#include <iostream>
#include <vector>
#include <ctime>
#include <locale.h>

using namespace std;

// генерация случайного числа в заданном диапазоне
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// заполнение матрицы случайными значениями
void fillMatrix(vector<vector<int>>& matrix, int n) {
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

 // вывод матрицы
void coutMatrix(vector<vector<int>> matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
}

// перебираем все возможные комбинации
void generatePermutations(vector<vector<int>>& permutations, vector<int>& nums, int start) {
    if (start == nums.size()) {
        permutations.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        generatePermutations(permutations, nums, start + 1);
        swap(nums[start], nums[i]);
    }
}

 // выстраиваем последовательность
vector<vector<int>> getPermutations(int n) {
    vector<int> nums(n);
    vector<vector<int>> permutations;

    for (int i = 0; i < n; i++) {
        nums[i] = i;
    }

    generatePermutations(permutations, nums, 0);

    return permutations;
}

// вычисление стоимости маршрута
int routeCost(const vector<vector<int>>& matrix, const vector<int>& path) {
    int cost = 0;
    int n = matrix.size();
    for (int i = 0; i < n - 1; i++) {
        cost += matrix[path[i]][path[i + 1]];
    }
    cost += matrix[path[n - 1]][path[0]];
    return cost;
}

// поиск оптимального маршрута методом полного перебора
vector<int> enumeration(const vector<vector<int>>& matrix, int startCity, int& minCost) {
    int n = matrix.size();
    vector<int> bestPath;

    vector<vector<int>> permutations = getPermutations(n);

    for (vector<int>& path : permutations) {
        if (path[0] == startCity) {
            int cost = routeCost(matrix, path);
            if (cost < minCost) {
                minCost = cost;
                bestPath = path;
            }
        }
    }

    return bestPath;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    int n; // количество городов
    int startCity = 0; // начальный город
    int minCost = INT_MAX; // мин. стоимость

    cout << "Пожалуйста, укажите количество городов (от 3): "; cin >> n;
    if (n < 3) return 0;
    cout << "Пожалуйста, укажите начальный город (отсчёт идёт с 0): "; cin >> startCity;
    if (startCity < 3 || startCity > n) return 0;

    for (int i = 3; i <= n; i++) {
        vector<vector<int>> matrix(i, vector<int>(i));
        fillMatrix(matrix, i);

        vector<int> bestPath = enumeration(matrix, startCity, minCost);

        cout << "\n" << endl;

        cout << "Матрица " << i << "x" << i << ":" << endl;
        coutMatrix(matrix);
        cout << endl;

        cout << "Цена пути: " << minCost << endl;
        cout << "Лучший путь: ";
        for (int city : bestPath) {
            cout << city << " ";
        }
        cout << endl;

        minCost = INT_MAX;
    }

    return 0;
}