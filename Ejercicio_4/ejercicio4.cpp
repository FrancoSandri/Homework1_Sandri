#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include "ejercicio4.h"

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
    string text1 = "This is a sample text to demonstrate the recursive string comparison function.";
    string text2 = "This is a sample text to demonstrate the recursive string comparison function.";

    auto startTime = std::chrono::high_resolution_clock::now();
    bool areEqual = compareStrings(text1, text2, text1.length());
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

    std::cout << "Los strings son " << (areEqual ? "iguales" : "diferentes") << "." << std::endl;
    std::cout << "Tiempo de ejecución: " << elapsedTime.count() << " nanosegundos" << std::endl;

    return 0;
}