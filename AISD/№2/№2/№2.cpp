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

    return positions;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string text = "ABACAABABABACABA";
    string pattern = "ABA";

    int index = BoyerMooreSearch(text, pattern)[0];
    cout << "Индекс первого появления: " << index << endl;

    cout << endl;

    return 0;
}