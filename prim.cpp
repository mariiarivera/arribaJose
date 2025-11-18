#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> prim(vector<vector<int>> grafo, int inicio) {
    int n = grafo.size();

    vector<bool> MST(n, false);     // nodos añadidos al MST
    vector<int> dist(n, INF);       // distancias mínimas
    vector<int> arista(n, -1);      // padre de cada nodo (arista resultante)

    dist[inicio] = 0;

    // mientras haya nodos no añadidos al MST
    for (int cont = 0; cont < n; cont++) {

        // seleccionar nodo U con dist mínima que no está en MST
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!MST[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        MST[u] = true; // añadir a MST

        // para cada vecino v de u
        for (int v = 0; v < n; v++) {
            if (grafo[u][v] && !MST[v] && grafo[u][v] < dist[v]) {
                dist[v] = grafo[u][v];
                arista[v] = u;  // v viene de u
            }
        }
    }

    return arista;
}

int main() {
    // Matriz de adyacencia (0 = no hay conexión)
    vector<vector<int>> grafo = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int inicio = 0;
    vector<int> resultado = prim(grafo, inicio);

    cout << "Aristas del MST:\n";
    for (int i = 0; i < resultado.size(); i++) {
        if (resultado[i] != -1)
            cout << resultado
