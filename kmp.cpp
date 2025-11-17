#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Construir la funcion PI
vector<int> buildKMPPI(const string& pattern) {
    int m = (int)pattern.size();
    vector<int> pi(m, 0);
    int len = 0;
    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            ++len;
            pi[i] = len;
            ++i;
        } else {
            if (len != 0) len = pi[len - 1];
            else {
                pi[i] = 0;
                ++i;
            }
        }
    }
    return pi;
}

// KMP: retorna true si pattern aparece en text
bool KMP(const string& text, const string& pattern) {
    if (pattern.empty()) return false;
    int n = (int)text.size();
    int m = (int)pattern.size();
    if (m > n) return false;

    vector<int> pi = buildKMPPI(pattern);
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            ++i; ++j;
            if (j == m) return true;
        } else {
            if (j != 0) j = pi[j - 1];
            else ++i;
        }
    }
    return false;
}

int main() {
    string text, pattern;

    cout << "Ingrese el texto: ";
    getline(cin, text);

    cout << "Ingrese el patrón a buscar: ";
    getline(cin, pattern);

    cout << (KMP(text, pattern) ? "true" : "false") << endl;

    return 0;
}
