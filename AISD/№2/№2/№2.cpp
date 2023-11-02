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

    return 0;
}