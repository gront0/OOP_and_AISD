#include <iostream>
#include <string>
#include <vector>
#include <locale.h>

using namespace std;

vector<int> boyermooresearch(const string& text, const string& pattern) {
    vector<int> positions;

    int n = text.length();
    int m = pattern.length();

    if (m == 0) {
        return positions;
    }

    vector<int> badchar(256, -1);

    for (int i = 0; i < m; i++) {
        badchar[pattern[i]] = i;
    }

    int s = 0;

    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            positions.push_back(s);

            if (s + m < n) {
                s += m - badchar[text[s + m]];
            }
            else {
                s += 1;
            }
        }
        else {
            s += max(1, j - badchar[text[s + j]]);
        }
    }

    return positions;
}

vector<int> findall(const string& text, const string& pattern, int start, int end) {
    vector<int> indices;
    int pattern_length = pattern.length();
    int text_length = text.length();

    if (pattern_length > text_length || start >= end + 1)
        return indices;

    for (int i = start; i <= end + 1 - pattern_length; i++) {
        bool match = true;
        for (int j = 0; j < pattern_length; j++) {
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            indices.push_back(i);
        }
    }

    return indices;
}

int main() {
    setlocale(LC_ALL, "russian");
    string text = "abacaabababacaba";
    string pattern = "aba";

    cout << "Текст: " << text << endl;
    cout << "Шаблон:" << pattern << endl;
    cout << endl;
    int index = boyermooresearch(text, pattern)[0];
    cout << "индекс первого появления: " << index << endl;

    vector<int> indexes = boyermooresearch(text, pattern);
    cout << "индексы всех вхождений: ";

    for (int i = 0; i < indexes.size(); i++) {
        cout << indexes[i] << " ";
    }

    cout << "\n================================" << endl;

    text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
    pattern = "tor";

    cout << "Текст: " << text << endl;
    cout << "Шаблон:" << pattern << endl;
    cout << endl;

    // примеры использования функции
    std::vector<int> indices = findall(text, pattern, 0, 91);
    cout << "поиск во всем тексте: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;

    indices = findall(text, pattern, 17, 91);
    cout << "поиск в подстроке 'r is an iterator adaptor which behaves exactly like the underlying iterator': ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;

    indices = findall(text, pattern, 28, 36);
    cout << "поиск в подстроке 'rator ad': ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}