#include <iostream>
#include <chrono>
#include <string>
#include "ejercicio4.h"

// Este archivo esta hecho para que se ejecute en tiempo de compilación.
// Se le agrega la palabra constexpr a las declaraciones de las funciones y las variables.
// Se cambia el tipo de dato de string a char* para que se pueda ejecutar en tiempo de compilación.

// Función que compara dos strings de forma recursiva y devuelve true si son iguales, false si son diferentes.
constexpr bool compareStringsConstexpr(const char* str1, const char* str2) {
    return *str1 == '\0' ? *str2 == '\0' : (*str1 == *str2 && compareStringsConstexpr(str1 + 1, str2 + 1));
}

constexpr const char text1[] = "Esto es un texto de prueba para demostrar la funcion recursiva que compara strings.";
constexpr const char text2[] = "Esto es un texto de prueba para demostrar la funcion recursiva que compara strings.";

int main() {
    // Código previsto en el enunciado del Homework.
    auto startTime = std::chrono::high_resolution_clock::now();
    constexpr bool areEqual = compareStringsConstexpr(text1, text2);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    // Imprimo el resultado de la comparación y el tiempo que tomó el proceso a medir en tiempo de compilación.
    cout << "Los strings son " << (areEqual ? "iguales" : "diferentes") << "." << endl;
    cout << "Tiempo de ejecución: " << elapsedTime.count() << " nanosegundos" << endl;

    return 0;
}

/*
Conclusión:
La comparación en tiempo de compilación (`constexpr`) hace que el resultado se calcule antes de ejecutar el programa.
Esto significa que el tiempo de ejecución medido es prácticamente cero, ya que el compilador ya resolvió la comparación.
En contraste, la versión del ejercicio 4.2 realizaba la comparación en tiempo de ejecución, lo que afectaba el rendimiento debido a la recursión 
y las operaciones en memoria.
*/
