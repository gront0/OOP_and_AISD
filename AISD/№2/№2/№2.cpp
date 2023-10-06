#include <iostream>
#include <string>
#include <vector>
#include <locale.h>

using namespace std;

vector<int> BoyerMooreSearch(const string& text, const string& pattern) {
    vector<int> positions;

    int n = text.length();
    int m = pattern.length();

    if (m == 0) {
        return positions;
    }

    vector<int> badChar(256, -1);

    for (int i = 0; i < m; i++) {
        badChar[pattern[i]] = i;
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
                s += m - badChar[text[s + m]];
            }
            else {
                s += 1;
            }
        }
        else {
            s += max(1, j - badChar[text[s + j]]);
        }
    }

    return positions;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string text = "ABACAABABABACABA";
    string pattern = "ABA";

    int index = BoyerMooreSearch(text, pattern)[0];
    cout << "Индекс первого появления: " << index << endl;

    vector<int> indexes = BoyerMooreSearch(text, pattern);
    cout << "Индексы всех вхождений: ";

    for (int i = 0; i < indexes.size(); i++) {
        cout << indexes[i] << " ";
    }

    cout << endl;

    return 0;
}