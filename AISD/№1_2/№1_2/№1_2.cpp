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

    return 0;
}