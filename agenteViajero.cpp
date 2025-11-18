// Integrantes: 
// José Ángel De La Cruz Alonso - A01772695
// Amilka Daniela Lopez - A01029277
// Maria Rivera - A01029678


#include <iostream>
#include <vector>
#include <string>
using namespace std;

void tspBranchBound(vector<vector<int>>& dist, vector<bool>& visitado, vector<int>& camino, int costoActual, 
    int nivel, int actual, int V, int& minCosto, vector<int>& mejorCamino, const int INF) 

{
    // Dentro de este if verificamos si hemos visitado todos los nodos
    if (nivel == V) { 
        int costoTotal = costoActual + dist[actual][camino[0]]; 
        if (costoTotal < minCosto && dist[actual][camino[0]] != INF) { // dentro de nuesto if verificamos si el costo total es menor que el minimo costo encontrado hasta ahora
            minCosto = costoTotal; // por lo que min costo se actualiza al costo total
            mejorCamino = camino; // al igual que el mejor camino se actualiza al camino actual
        }
        return;
    }
    
    for (int i = 0; i < V; i++) { // dentro nuestro for recorremos todos los nodos
        if (!visitado[i] && dist[actual][i] != INF) { // si el nodo no ha sido visitado y existe una conexion
            int nuevoCosto = costoActual + dist[actual][i]; // entonces calculamos el nuevo costo sumando el costo actual y el costo de ir al nodo i
            
            // luego en este otro if donde si el nuevo costo es menor que el minimo costo encontrado hasta ahora se hace lo siguiente 
            if (nuevoCosto < minCosto) {
                visitado[i] = true; // marcamos el nodo i como visitado
                camino.push_back(i); // agregamos el nodo i al camino actual
                
                // despues hacemos una llamada recursiva a tspBranchBound para explorar mas a fondo este camino
                tspBranchBound(dist, visitado, camino, nuevoCosto, nivel + 1, i, V, minCosto, mejorCamino, INF);
                
                visitado[i] = false; // desmarcamos el nodo i para permitir otras exploraciones
                camino.pop_back(); // removemos el nodo i del camino actual para probar otros caminos

            }
        }
    }
}

// Esta parte me guie de nuestro archivo floyd.cpp
void agente_viajero() {
    const int INF = 999999; // // No hay conexión
    int V;

    cout << "Ingresa el numero de nodos: ";
    cin >> V;

    vector<string> nodos(V);
    cout << "Ingresa los nombres de los nodos (una letra o palabra sin espacios):\n";
    for (int i = 0; i < V; i++) {
        cin >> nodos[i];
    }

    vector<vector<int>> dist(V, vector<int>(V, INF));

    cout << "\nIngresa el peso entre los nodos (usa " << INF << " si no hay conexion):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                dist[i][j] = 0; // mismo nodo
            } else {
                cout << "Peso de " << nodos[i] << " a " << nodos[j] << ": ";
                cin >> dist[i][j];
            }
        }
    }

    // Seleccionar nodo inicial
    int inicio;
    cout << "\nSelecciona el nodo de inicio (0 a " << V-1 << "): ";
    for (int i = 0; i < V; i++) {
        cout << "\n  " << i << ": " << nodos[i];
    }
    cout << "\nOpcion: ";
    cin >> inicio;

    // Algoritmo Branch and Bound para el Agente Viajero

    int minCosto = INF; // aqui guardaremos el costo minimo encontrado
    vector<int> mejorCamino; // vector que guardara el mejor camino encontrado
    vector<bool> visitado(V, false); // vector que marca nodos visitados
    vector<int> camino; // camino actual
    visitado[inicio] = true; // marcamos el nodo inicial como visitado
    camino.push_back(inicio); // camino inicia en el nodo seleccionado
    
    tspBranchBound(dist, visitado, camino, 0, 1, inicio, V, minCosto, mejorCamino, INF); // llamamos al metdo principal con los parametros necesarios para iniciar la busqueda

    // Mostrar resultados
    if (minCosto < INF) {
        // ---- Recorrido normal ----
        cout << "\nRecorrido: ";
        for (int i = 0; i < mejorCamino.size(); i++) {
            cout << nodos[mejorCamino[i]] << " ";
        }
        cout << nodos[mejorCamino[0]] << endl;
        cout << "Costo: " << minCosto << endl;

        // recorrido inverso 
        cout << "Recorrido: " << nodos[mejorCamino[0]] << " ";
        for (int i = mejorCamino.size() - 1; i >= 0; i--) {
            cout << nodos[mejorCamino[i]] << " ";
        }
        cout << nodos[mejorCamino[0]] << endl;
        cout << "Costo: " << minCosto << endl;
    } else {
        cout << "\nNo se encontro un camino valido." << endl;
    }
}

int main() {
    cout << "hola\n";
    agente_viajero();
    return 0;
}
