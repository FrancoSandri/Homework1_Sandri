#include <iostream>
#include "ejercicio1.h"

using namespace std;


/*
a. Crear una función que dado un valor entero “n”, positivo y mayor a uno, devuelva una matriz cuadrada.
*/

vector<vector<int>> crearMatriz(int n) {
    // Creo una matriz cuadrada de n x n
    vector<vector<int>> matriz(n, vector<int>(n));
    // Inicializo la matriz con valores consecutivos
    int valor = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = valor++;
        }
    }
    return matriz;
}

/*
b. Proveer un código que imprima el contenido de la matriz, utilizando un único ciclo for, desde el mayor valor al menor.
*/
void imprimirMatriz(const vector<vector<int>>& matriz) {
    // Obtengo el tamaño de la matriz
    int n = matriz.size();
    // Imprimo los valores de la matriz desde el mayor al menor
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
    
    // Verifico que el valor ingresado sea mayor que 1
    // Si no lo es, muestro un mensaje de error y termino el programa.
    if (n <= 1) {
        cout << "El valor debe ser mayor que 1." << endl;
        return 1;
    }

    // Creo la matriz y la imprimo
    vector<vector<int>> matriz = crearMatriz(n);
    imprimirMatriz(matriz);

    return 0;
}
