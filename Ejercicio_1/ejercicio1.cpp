#include <iostream>
#include "ejercicio1.h"

using namespace std;


/*
a. Crear una función que dado un valor entero “n”, positivo y mayor a uno, devuelva una matriz cuadrada con valores como en los siguientes ejemplos para n=2 y n=3:
*/

vector<vector<int>> crearMatriz(int n) {
    vector<vector<int>> matriz(n, vector<int>(n));
    int valor = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = valor++;
        }
    }
    return matriz;
}

/*
b. Proveer un código que imprima el contenido de la matriz, utilizando un único ciclo for, desde el mayor valor al menor, es decir, para el ejemplo de Para 𝑀2:
*/
void imprimirMatriz(const vector<vector<int>>& matriz) {
    int n = matriz.size();
    for (int i = n * n - 1; i >= 0; --i) {
        int fila = i / n;
        int columna = i % n;
        cout << "M[" << fila << "][" << columna << "]=" << matriz[fila][columna] << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el valor de n (mayor que 1): ";
    cin >> n;
    
    if (n <= 1) {
        cout << "El valor debe ser mayor que 1." << endl;
        return 1;
    }

    vector<vector<int>> matriz = crearMatriz(n);
    imprimirMatriz(matriz);

    return 0;
}
