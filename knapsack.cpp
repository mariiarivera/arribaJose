#include <iostream>
#include <vector>
using namespace std;

int Knapsack(int W, vector<int> w, vector<int> v, int n) {
    vector<vector<int>> A(n+1, vector<int>(W+1, 0)); // Inicializado en 0

    for (int i = 1; i <= n; i++) {
        for (int x = 1; x <= W; x++) {

            if (w[i-1] > x) {
                A[i][x] = A[i-1][x];
            } else {
                A[i][x] = max(A[i-1][x], A[i-1][x - w[i-1]] + v[i-1]);
            }
        }
    }

    return A[n][W];
}

int main() {
    vector<int> peso  = {2, 3, 4, 5};
    vector<int> valor = {3, 4, 5, 6};
    int W = 5;
    int n = peso.size();

    cout << "Valor máximo posible = " << Knapsack(W, peso, valor, n);
}
