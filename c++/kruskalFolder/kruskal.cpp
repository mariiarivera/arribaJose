#include <iostream>
#include <fstream>
using namespace std;

struct Valor {
    int nodo1, nodo2, peso;
};

// ver archivo
int leerValores(Valor valores[], const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    int cantidad = 0;

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return -1;
    }

    while (archivo >> valores[cantidad].nodo1 >> valores[cantidad].nodo2 >> valores[cantidad].peso) {
        cantidad++;
    }

    archivo.close();
    return cantidad;
}

// bubble sort
void ordenarPorPeso(Valor valores[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (valores[j].peso > valores[j + 1].peso) {
                Valor temp = valores[j];
                valores[j] = valores[j + 1];
                valores[j + 1] = temp;
            }
        }
    }
}

// raíz (union-find) //https://www.geeksforgeeks.org/dsa/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
int encontrarRaiz(int padre[], int nodo) {
    while (padre[nodo] != nodo) {
        nodo = padre[nodo];
    }
    return nodo;
}

// juntar conjuntos (Union-Find) ////https://www.geeksforgeeks.org/dsa/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
void unirConjuntos(int padre[], int rango[], int raiz1, int raiz2) {
    if (rango[raiz1] < rango[raiz2]) {
        padre[raiz1] = raiz2;
    } else if (rango[raiz1] > rango[raiz2]) {
        padre[raiz2] = raiz1;
    } else {
        padre[raiz2] = raiz1;
        rango[raiz1]++;
    }
}


//https://www.geeksforgeeks.org/dsa/kruskals-minimum-spanning-tree-using-stl-in-c/
int main() {
    Valor valores[100];
    Valor seleccionados[100];
    int padre[100], rango[100];
    int cantidad = leerValores(valores, "grafo.txt");
    if (cantidad == -1) return 1;

    ordenarPorPeso(valores, cantidad);

    // nodo máximo para inicializar Union-Find
    int maxNodo = 0;
    for (int i = 0; i < cantidad; i++) {
        if (valores[i].nodo1 > maxNodo) maxNodo = valores[i].nodo1;
        if (valores[i].nodo2 > maxNodo) maxNodo = valores[i].nodo2;
    }

    for (int i = 0; i <= maxNodo; i++) {
        padre[i] = i;
        rango[i] = 0;
    }

    int seleccionadosCount = 0;
    int pesoTotal = 0;

    // mst
    for (int i = 0; i < cantidad; i++) {
        int n1 = valores[i].nodo1;
        int n2 = valores[i].nodo2;
        int p = valores[i].peso;

        int raiz1 = encontrarRaiz(padre, n1);
        int raiz2 = encontrarRaiz(padre, n2);

        if (raiz1 != raiz2) {
            unirConjuntos(padre, rango, raiz1, raiz2);
            seleccionados[seleccionadosCount++] = valores[i];
            pesoTotal += p;
        }
    }

    //  resultado final 
    cout << "Conexiones usadas: ";
    for (int i = 0; i < seleccionadosCount; i++) {
        cout << "[" << seleccionados[i].nodo1 << "," 
             << seleccionados[i].nodo2 << "," 
             << seleccionados[i].peso << "]";
        if (i < seleccionadosCount - 1) cout << ", ";
    }
    cout << ". Peso final: " << pesoTotal << endl;

    return 0;
}
