#include <iostream>
#include <chrono>
#include <string>
#include "ejercicio4.h"

// Este archivo esta hecho para que se ejecute en tiempo de compilación.
// Se le agrega la palabra constexpr a las declaraciones de las funciones y las variables.
// Cambio el tipo de dato de string a char* para que se pueda ejecutar en tiempo de compilación.
// Esto lo hice porque char* permite que los datos se almacenen en la memoria estática del compilador y puedan ser evaluados en tiempo de compilación.


// Función que compara dos strings de forma recursiva y devuelve true si son iguales, false si son diferentes.
constexpr bool compareStringsConstexpr(const char* str1, const char* str2) {
    return *str1 == '\0' ? *str2 == '\0' : (*str1 == *str2 && compareStringsConstexpr(str1 + 1, str2 + 1));
}

constexpr const char text1[] = "El Club Atlético Colegiales es un club de fútbol argentino, radicado en el barrio de Munro, partido de Vicente López, provincia de Buenos Aires. Fue fundado el 1 de abril de 1908 bajo el nombre Libertarios Unidos, nombre que actualmente lleva su estadio. Desde 2025 participará en la Primera Nacional, la segunda categoría del fútbol argentino.";
constexpr const char text2[] = "El Club Atlético Colegiales es un club de fútbol argentino, radicado en el barrio de Munro, partido de Vicente López, provincia de Buenos Aires. Fue fundado el 1 de abril de 1908 bajo el nombre Libertarios Unidos, nombre que actualmente lleva su estadio. Desde 2025 participará en la Primera Nacional, la segunda categoría del fútbol argentino.";

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
Se evita el uso de memoria dinámica y se almacena en la memoria estática del compilador.
Se evita también, que se tenga que gestionar la pila para cada llamado recursivo, reemplazando la función con su resultado final. 

Es por eso que todos estos procesos de manejo de memoria que se evitan, ayudan a que el tiempo que tardan en ejecutarse ambos archivos sean diferentes.
Siento este mismo, considerablemente menor, al primero. 
*/
