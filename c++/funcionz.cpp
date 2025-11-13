#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> calcularZ(string s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}


void buscarPatron(const string& patron, const string& texto) {
    string combinado = patron + "$" + texto;
    vector<int> z = calcularZ(combinado);
    int longitudPatron = patron.length();
    int repeticiones = 0;

    cout << "Patrón encontrado en las posiciones: ";
    bool encontrado = false;

    for (int i = 0; i < z.size(); ++i) {
        if (z[i] == longitudPatron) {
            cout << (i - longitudPatron) << " ";
            repeticiones++;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Ninguna";
    }

    cout << endl;
    cout << "El patrón se repite " << repeticiones << " veces en el texto." << endl;
    cout << "Vector Z: [";
        for (int i = 0; i < z.size(); ++i) {
            cout << z[i];
            if (i != z.size() - 1)
                cout << ", ";
        }
    cout << "]" << endl;
}

int main() {
    string patron, texto;
    cout << "Ingresa el patrón: ";
    cin >> patron;
    cout << "Ingresa el texto: ";
    cin >> texto;

    buscarPatron(patron, texto);
    return 0;
}
