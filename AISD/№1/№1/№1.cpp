#include <iostream>
#include <vector>
#include <ctime>
#include <locale.h>
#include <chrono>

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
    minCost = INT_MAX;
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

    int n = 0; // количество городов
    int startCity = 0; // начальный город
    int minCost = INT_MAX; // мин. стоимость
    int task; // свойство выполнения
    int evr = 0; // эвристика

    cout << "Пожалуйста, укажите свойство выполнения (1 - одна генерация / 0 - все генерации): "; cin >> task;
    if (task > 1 || task < 0) return 0;
    cout << "Пожалуйста, укажите нужно ли выполнять эвристику (1 - да / 0 - нет): "; cin >> evr;
    if (evr < 0 || evr > 1) return 0;
    cout << "Пожалуйста, укажите количество городов (от 3): "; cin >> n;
    if (n < 3 || (task == -1 && n != 5)) return 0;
    cout << "Пожалуйста, укажите начальный город (отсчёт идёт с 0): "; cin >> startCity;
    if (startCity < 0 || startCity > n) return 0;

    vector<vector<int>> cost(n, vector<int>(n)); // матрица для эвристики

    vector<vector<int>> matrix(n, vector<int>(n));
    fillMatrix(matrix, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = matrix[i][j];
        }
    }

    // Начало измерения времени
    auto start = chrono::high_resolution_clock::now();

    if (task == 0) {
        for (int i = 3; i <= n; i++) {
            vector<vector<int>> cosma(i, vector<int>(i));
            fillMatrix(cosma, i);

            vector<int> bestPath = enumeration(cosma, startCity, minCost);

            cout << "\n" << endl;

            cout << "Матрица " << i << "x" << i << ":" << endl;
            coutMatrix(cosma);
            cout << endl;

            cout << "Цена пути: " << minCost << endl;
            cout << "Лучший путь: ";
            for (int city : bestPath) {
                cout << city << " ";
            }
            cout << endl;

            minCost = INT_MAX;
        }
    }
    else if (task == 1) {
        vector<int> bestPath = enumeration(matrix, startCity, minCost);

        cout << "\n" << endl;

        cout << "Матрица " << n << "x" << n << ":" << endl;
        coutMatrix(matrix);
        cout << endl;

        cout << "Цена пути: " << minCost << endl;
        cout << "Лучший путь: ";
        for (int city : bestPath) {
            cout << city << " ";
        }
        cout << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    double executionTime = duration.count();
    cout << "Время выполнения точного алгоритма: " << executionTime << " мс" << endl;

    if (evr == 1) {
        auto start = chrono::high_resolution_clock::now();

        // Вывод матрицы стоимости маршрутов
        cout << endl;
        cout << "Матрица стоимости:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << cost[i][j] << " ";
            }
            cout << endl;
        }

        vector<int> route;

        int current_city = 0;
        route.push_back(current_city);

        vector<bool> visited(n, false);
        visited[current_city] = true;

        int total_cost = 0;

        while (route.size() < n) {
            int next_city = -1;
            int min_cost = numeric_limits<int>::max();

            // Поиск ближайшего непосещенного города
            for (int i = 0; i < n; i++) {
                if (!visited[i] && cost[current_city][i] < min_cost) {
                    min_cost = cost[current_city][i];
                    next_city = i;
                }
            }

            route.push_back(next_city);
            visited[next_city] = true;
            current_city = next_city;

            total_cost += min_cost;
        }

        // Возврат в начальный город
        total_cost += cost[current_city][startCity];

        // Вывод маршрута
        cout << "Оптимальный маршрут коммивояжёра: ";
        for (int i = 0; i < n; i++) {
            cout << route[i] << " ";
        }
        cout << endl;

        // Вывод оптимальной стоимости маршрута
        cout << "Оптимальная стоимость маршрута: " << total_cost << endl;


        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = end - start;
        double executionTime = duration.count();
        cout << "Время выполнения эвристического алгоритма: " << executionTime << " мс" << endl;
    }

    return 0;
}