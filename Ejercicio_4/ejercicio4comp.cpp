#include <iostream>
#include <chrono>
#include <string>
#include "ejercicio4.h"

using namespace std;

constexpr bool compareStringsConstexpr(const char* str1, const char* str2) {
    return *str1 == '\0' ? *str2 == '\0' : (*str1 == *str2 && compareStringsConstexpr(str1 + 1, str2 + 1));
}

constexpr const char text1[] = "Esto es un texto para demostrar la funcion recursiva que compara strings.";
constexpr const char text2[] = "Esto es un texto para demostrar la funcion recursiva que compara strings.";

int main() {
    
    auto startTime = std::chrono::high_resolution_clock::now();
    constexpr bool areEqual = compareStringsConstexpr(text1, text2);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    std::cout << "Los strings son " << (areEqual ? "iguales" : "diferentes") << "." << std::endl;
    std::cout << "Tiempo de ejecución: " << elapsedTime.count() << " nanosegundos" << std::endl;

    return 0;
}

/*
**Conclusión**:
- La comparación en tiempo de compilación (`constexpr`) hace que el resultado se calcule antes de ejecutar el programa.
- Esto significa que el tiempo de ejecución medido es prácticamente cero, ya que el compilador ya resolvió la comparación.
- En contraste, la versión del ejercicio 4.2 realizaba la comparación en tiempo de ejecución, lo que introducía una penalización en rendimiento debido a la recursión y las operaciones en memoria.
*/
