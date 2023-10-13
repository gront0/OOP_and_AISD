#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n, startCity = 0;
    cout << "Введите количество городов: ";  cin >> n;
    cout << endl;

    // Начало измерения времени
    auto start = chrono::high_resolution_clock::now();

    vector<vector<int>> cost(n, vector<int>(n)); // матрица расстояний между городами

        // Генерация случайной стоимости маршрута
        srand(time(0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    cost[i][j] = rand() % 100 + 1;
                }
            }
        }

    // Вывод матрицы стоимости маршрутов
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

    // Конец измерения времени
    auto end = chrono::high_resolution_clock::now();

    // Вычисление времени выполнения в миллисекундах
    chrono::duration<double, milli> duration = end - start;
    double executionTime = duration.count();

    // Вывод времени выполнения
    cout << "Время выполнения: " << executionTime << " мс" << endl;

    return 0;
}