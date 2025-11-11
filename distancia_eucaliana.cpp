#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
using namespace std;

void distancia_euclidiana() {
    int n;
    cout << "Ingresa el número de puntos: ";
    cin >> n;

    vector<string> puntos(n);
    vector<pair<double, double>> coordenadas(n);

    cout << "Ingresa los nombres de los puntos (una letra o palabra sin espacios):\n";
    for (int i = 0; i < n; i++) {
        cin >> puntos[i];
    }

    cout << "Ingresa las coordenadas (x y) de cada punto:\n";
    for (int i = 0; i < n; i++) {
        cout << "Coordenadas de " << puntos[i] << ": ";
        cin >> coordenadas[i].first >> coordenadas[i].second;
    }

    vector<double> distancias;  // Aquí guardaremos todas las distancias
    double distancia_minima = numeric_limits<double>::max();
    string punto1_min, punto2_min;

    // Calcular distancias euclidianas y guardarlas en el array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // evitar duplicados (A-B y B-A)
            double dx = coordenadas[i].first - coordenadas[j].first;
            double dy = coordenadas[i].second - coordenadas[j].second;
            double distancia = sqrt(dx * dx + dy * dy);
            distancias.push_back(distancia);

            // Verificar si es la distancia mínima
            if (distancia < distancia_minima) {
                distancia_minima = distancia;
                punto1_min = puntos[i];
                punto2_min = puntos[j];
            }
        }
    }

    cout << "\nLa distancia mínima es: " << distancia_minima 
         << " entre los puntos " << punto1_min << " y " << punto2_min << endl;
}

int main() {
    distancia_euclidiana();
    return 0;
}
