#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Función para aplicar el algoritmo de Manacher
string manacher(string s) {
    // Insertamos '#' entre caracteres para manejar pares e impares
    string t = "@"; // símbolo al inicio para evitar índices negativos
    for (char c : s) {
        t += "#" + string(1, c);
    }
    t += "#$"; // símbolo al final para evitar desbordes

    int n = t.size();
    vector<int> p(n, 0); // p[i] = radio del palíndromo centrado en i
    int centro = 0, derecha = 0;  // centro y borde derecho actual
    int maxLen = 0, centroMax = 0; // para guardar el más largo

    for (int i = 1; i < n - 1; i++) {
        int espejo = 2 * centro - i; // posición espejo respecto al centro

        if (i < derecha)
            p[i] = min(derecha - i, p[espejo]);

        // Expansión alrededor del centro i
        while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
            p[i]++;

        // Si expandimos más allá de la derecha actual, actualizamos centro y derecha
        if (i + p[i] > derecha) {
            centro = i;
            derecha = i + p[i];
        }

        // Guardamos el palíndromo más largo encontrado
        if (p[i] > maxLen) {
            maxLen = p[i];
            centroMax = i;
        }
    }

    // Extraemos el palíndromo original (sin '#')
    int start = (centroMax - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string texto;
    cout << "Ingresa una cadena: ";
    cin >> texto;

    string resultado = manacher(texto);
    cout << "Palindromo más largo: " << resultado << endl;

    return 0;
}
