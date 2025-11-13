#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9; // Valor grande que representa "infinito"

// Algoritmo de Dijkstra
void dijkstra(int n, int start, vector<vector<pair<int, int>>> &grafo) {
    vector<int> dist(n, INF);       // Distancias desde el nodo inicial
    dist[start] = 0;

    // Cola de prioridad (distancia, nodo)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;   // distancia actual
        int u = pq.top().second;  // nodo actual
        pq.pop();

        if (d > dist[u]) continue; // Si ya hay una distancia mejor, se salta

        for (auto &edge : grafo[u]) {
            int v = edge.first;    // nodo vecino
            int peso = edge.second; // peso de la arista

            if (dist[u] + peso < dist[v]) { // Si encontramos un camino más corto
                dist[v] = dist[u] + peso;
                pq.push({dist[v], v});
            }
        }
    }

    // Mostrar distancias
    cout << "Distancias desde el nodo " << start << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) cout << i << ": Inalcanzable\n";
        else cout << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int n = 5; // número de nodos
    vector<vector<pair<int, int>>> grafo(n);

    // Agregar aristas: grafo[origen].push_back({destino, peso});
    grafo[0].push_back({1, 10});
    grafo[0].push_back({2, 3});
    grafo[1].push_back({2, 1});
    grafo[1].push_back({3, 2});
    grafo[2].push_back({1, 4});
    grafo[2].push_back({3, 8});
    grafo[2].push_back({4, 2});
    grafo[3].push_back({4, 7});
    grafo[4].push_back({3, 9});

    dijkstra(n, 0, grafo); // iniciar desde el nodo 0

    return 0;
}
