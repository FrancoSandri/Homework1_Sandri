#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include "ejercicio4.h"

/*
Se requiere el código de una función recursiva que compare dos variables que
contengan texto e indique mediante una variable bool si son iguales (true si son
iguales, false si no lo son). Explique su elección entre los tipos string y char* (lea
el siguiente item de este ejercicio antes de elegir el tipo de variable) y demuestre
la funcionalidad de su código con un texto de, al menos, 64 caracteres.
*/

// Se eligió el tipo string porque es más fácil de usar y manipular que un puntero a char.
// Además, string es un tipo de dato más seguro que char* ya que se encarga de la gestión de memoria.

bool compareStrings(const string& str1, const string& str2, size_t index = 0) {
    if (str1.length() != str2.length()) {
        return false;
    }
    if (index == str1.length()) {
        return true;
    }
    if (str1[index] != str2[index]) {
        return false;
    }
    return compareStrings(str1, str2, index + 1);
}

int main() {
    string text1 = "Esto es un texto para demostrar la funcion recursiva que compara strings";
    string text2 = "Esto es un texto para demostrar la funcion recursiva que compara strings";

    auto startTime = std::chrono::high_resolution_clock::now();
    bool areEqual = compareStrings(text1, text2, text1.length());
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    std::cout << "Los strings son " << (areEqual ? "iguales" : "diferentes") << "." << std::endl;
    std::cout << "A mi proceso a medir le tomó: " << elapsedTime.count() << " nanosegundos" << std::endl;

    return 0;
}