#ifndef EJERCICIO4_H
#define EJERCICIO4_H

#include <string>

using namespace std;

// Se eligió el tipo string porque es más fácil de usar y manipular que un puntero a char.
// Además, string es un tipo de dato más seguro que char* ya que se encarga de la gestión de memoria.
// Función que compara dos strings y devuelve true si son iguales, false si son diferentes.
bool compareStrings(const string& str1, const string& str2);

// Función que mide el tiempo de ejecución de la función compareStrings.
void measureExecutionTime();

#endif 