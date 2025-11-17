#include <iostream>
using namespace std; 

int fibonacciMemo (int n){
    int n1 = 0, n2 = 1, f; 
    if (n <= n2) return n;
    else{
        n1 = fibonacciMemo(n-1);
        n2 = fibonacciMemo(n-2);
        f = n1+n2;
        n1 = n2;
        n2 = f;
    }
    return f; 
}

//Fibonacci Interativo solo que no le cambiamos el nombre 
// int fibonacciMemo(int n) {
//     if (n == 0) return 0;
//     if (n == 1) return 1;

//     vector<int> fib(n + 1);
//     fib[0] = 0;
//     fib[1] = 1;

//     for (int i = 2; i <= n; i++) {
//         fib[i] = fib[i - 1] + fib[i - 2];
//     }

//     return fib[n];
// }

// int main() {
//     int n = 40;
//     cout << "Fibonacci con memoización de " << n << " = " << fibonacciMemo(n) << endl;
//     return 0;
// }



int main (){
    cout << "Resultado: " << fibonacciMemo(40) << endl; 
}