#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n; // количество городов
    cout << "Введите количество городов: ";  cin >> n;
    cout << endl;

    vector<vector<int>> distance(n, vector<int>(n)); // матрица расстояний между городами

    // Генерация случайной стоимости маршрута
    srand(time(0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                distance[i][j] = rand() % 100 + 1; // случайное число от 1 до 100
            }
        }
    }

    // Вывод матрицы расстояний
    cout << "Матрица расстояний:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> route; // маршрут коммивояжёра

    int current_city = 0; // начинаем с первого города
    route.push_back(current_city);

    vector<bool> visited(n, false); // флаги посещения городов
    visited[current_city] = true;

    int total_distance = 0; // общая стоимость маршрута

    while (route.size() < n) {
        int next_city = -1;
        int min_distance = numeric_limits<int>::max();

        // Поиск ближайшего непосещенного города
        for (int i = 0; i < n; i++) {
            if (!visited[i] && distance[current_city][i] < min_distance) {
                min_distance = distance[current_city][i];
                next_city = i;
            }
        }

        route.push_back(next_city);
        visited[next_city] = true;
        current_city = next_city;

        total_distance += min_distance;
    }

    // Вывод маршрута
    cout << "Оптимальный маршрут коммивояжёра: ";
    for (int i = 0; i < n; i++) {
        cout << route[i] << " ";
    }
    cout << endl;

    // Вывод оптимальной стоимости маршрута
    cout << "Оптимальная стоимость маршрута: " << total_distance << endl;

    return 0;
}