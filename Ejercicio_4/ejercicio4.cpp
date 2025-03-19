#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include "ejercicio4.h"

/*
Enunciado:
Se requiere el código de una función recursiva que compare dos variables que
contengan texto e indique mediante una variable bool si son iguales (true si son
iguales, false si no lo son). Explique su elección entre los tipos string y char* (lea
el siguiente item de este ejercicio antes de elegir el tipo de variable) y demuestre
la funcionalidad de su código con un texto de, al menos, 64 caracteres.
*/

// Se eligió el tipo string porque es más fácil de usar y manipular que un puntero a char.
// Además, string es un tipo de dato más seguro que char* ya que se encarga de la gestión de memoria.

// Función que compara dos strings de forma recursiva y devuelve true si son iguales, false si son diferentes.
bool compareStrings(const string& str1, const string& str2, size_t index = 0) {
    // Si las longitudes de los strings son diferentes, no son iguales y devuelvo false.
    if (str1.length() != str2.length()) {
        return false;
    }
    // Si llego al final de los strings, son iguales y devuelvo true.
    if (index == str1.length()) {
        return true;
    }
    // Si los caracteres en la posición actual son diferentes, no son iguales y devuelvo false.
    if (str1[index] != str2[index]) {
        return false;
    }
    // Llamo a la función recursivamente con el siguiente índice.
    return compareStrings(str1, str2, index + 1);
}

int main() {
    // Textos de prueba
    string text1 = "El Club Atlético Colegiales es un club de fútbol argentino, radicado en el barrio de Munro, partido de Vicente López, provincia de Buenos Aires. Fue fundado el 1 de abril de 1908 bajo el nombre Libertarios Unidos, nombre que actualmente lleva su estadio. Desde 2025 participará en la Primera Nacional, la segunda categoría del fútbol argentino.";
    string text2 = "El Club Atlético Colegiales es un club de fútbol argentino, radicado en el barrio de Munro, partido de Vicente López, provincia de Buenos Aires. Fue fundado el 1 de abril de 1908 bajo el nombre Libertarios Unidos, nombre que actualmente lleva su estadio. Desde 2025 participará en la Primera Nacional, la segunda categoría del fútbol argentino.";
    
    // Código previsto en el enunciado del Homework
    auto startTime = std::chrono::high_resolution_clock::now();
    bool areEqual = compareStrings(text1, text2, text1.length());
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    // Imprimo el resultado de la comparación y el tiempo que tomó el proceso a medir.
    cout << "Los strings son " << (areEqual ? "iguales" : "diferentes") << "." << endl;
    cout << "A mi proceso a medir le tomó: " << elapsedTime.count() << " nanosegundos" << endl;

    return 0;
}