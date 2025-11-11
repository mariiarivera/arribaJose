#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

// Variables globales
const int p = 31;
const long long mod = 1000000009;

// Diccionario de letras (27 letras incluyendo la ñ)
unordered_map<char, int> letraValor = {
    {'a', 1},  {'b', 2},  {'c', 3},  {'d', 4},  {'e', 5},
    {'f', 6},  {'g', 7},  {'h', 8},  {'i', 9},  {'j', 10},
    {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'n', 15},
    {'o', 16}, {'p', 17}, {'q', 18}, {'r', 19}, {'s', 20},
    {'t', 21}, {'u', 22}, {'v', 23}, {'w', 24}, {'x', 25},
    {'y', 26}, {'z', 27}
};

// Función hash
void hashString(const string& s) {
    double hashSinMod = 0;
    long long hashConMod = 0;

    for (size_t i = 0; i < s.length(); i++) {
        char letra = tolower(s[i]);
        if (letraValor.count(letra)) {
            int valor = letraValor[letra];

            // Usar pow normalmente
            double potenciaP = pow(p, i);
            hashSinMod += valor * potenciaP;

            // Convertir pow a entero para el hash con módulo
            long long potenciaPMod = static_cast<long long>(pow(p, i));
            hashConMod = (hashConMod + (valor * potenciaPMod) % mod) % mod;
        }
    }

    cout << "Hash sin mod: " << hashSinMod << endl;
    cout << "Hash con mod: " << hashConMod << endl;
}

int main() {
    string texto;
    cout << "String: ";
    getline(cin, texto);

    hashString(texto);

    return 0;
}
