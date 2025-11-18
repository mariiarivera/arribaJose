#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Nodo {
    string nombre;
    double f;

    bool operator>(const Nodo& other) const {
        return f > other.f;
    }
};

vector<string> AStar(string start, string goal,
                     unordered_map<string, vector<pair<string,double>>> grafo,
                     unordered_map<string,double> h) {

    vector<string> nodos_libres;
    vector<string> nodos_visitados;

    unordered_map<string,double> g;
    unordered_map<string,double> f;
    unordered_map<string,string> padre;

    g[start] = 0;
    f[start] = g[start] + h[start];

    nodos_libres.push_back(start);

    while(!nodos_libres.empty()) {

        // seleccionar n con f mínimo
        string n = nodos_libres[0];
        for (auto &x : nodos_libres)
            if (f[x] < f[n]) n = x;

        // quitarlo de libres y ponerlo en visitados
        nodos_libres.erase(remove(nodos_libres.begin(), nodos_libres.end(), n), nodos_libres.end());
        nodos_visitados.push_back(n);

        if (n == goal) {
            vector<string> camino;
            string actual = goal;
            while(actual != "") {
                camino.push_back(actual);
                actual = padre[actual];
            }
            reverse(camino.begin(), camino.end()); // 👈 Aquí usamos reverse
            return camino;
        }

        // Para los vecinos
        for (auto &v : grafo[n]) {
            string m = v.first;
            double costo = v.second;

            double g_nuevo = g[n] + costo;

            if (!g.count(m) || g_nuevo < g[m]) {
                g[m] = g_nuevo;
                f[m] = g_nuevo + h[m];
                padre[m] = n;

                // agregamos si no está en visitados
                if (find(nodos_visitados.begin(), nodos_visitados.end(), m) == nodos_visitados.end())
                    nodos_libres.push_back(m);
            }
        }
    }

    return {}; // no hay camino
}

int main() {

    // Grafo (diccionario ciudad: costo)
    unordered_map<string, vector<pair<string,double>>> grafo = {
        {"A", {{"B",2}, {"C",4}}},
        {"B", {{"D",7}}},
        {"C", {{"D",1}}},
        {"D", {}}
    };

    // Heurística
    unordered_map<string,double> h = {
        {"A",5}, {"B",4}, {"C",2}, {"D",0}
    };

    vector<string> camino = AStar("A","D",grafo,h);

    cout << "Camino encontrado:\n";
    for (auto &c : camino) cout << c << " ";
}
