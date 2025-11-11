#include <iostream>
#include <vector>
#include <string>
using namespace std;

void floyd() {
    const int INF = 999999; // No hay conexión
    int V;

    cout << "Ingresa el número de nodos: ";
    cin >> V;

    vector<string> nodos(V);
    cout << "Ingresa los nombres de los nodos (una letra o palabra sin espacios):\n";
    for (int i = 0; i < V; i++) {
        cin >> nodos[i];
    }

    vector<vector<int>> dist(V, vector<int>(V, INF));

    cout << "\nIngresa el peso entre los nodos (usa " << INF << " si no hay conexión):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                dist[i][j] = 0; // mismo nodo
            } else {
                cout << "Peso de " << nodos[i] << " → " << nodos[j] << ": ";
                cin >> dist[i][j];
            }
        }
    }

    // Algoritmo de Floyd–Warshall
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Mostrar resultados
    cout << "\nMatriz de distancias más cortas:\n\n   ";
    for (int i = 0; i < V; i++) cout << nodos[i] << " ";
    cout << endl;

    for (int i = 0; i < V; i++) {
        cout << nodos[i] << " ";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    floyd();
    return 0;
}
