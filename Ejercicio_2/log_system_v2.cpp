// log_system_v2.cpp
#include "log_system.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

void logMessage(const string& mensaje, LogLevel nivel) {
    ofstream logFile("log.txt", ios::app);
    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return;
    }

    string etiqueta;
    switch (nivel) {
        case LogLevel::DEBUG: etiqueta = "[DEBUG]"; break;
        case LogLevel::INFO: etiqueta = "[INFO]"; break;
        case LogLevel::WARNING: etiqueta = "[WARNING]"; break;
        case LogLevel::ERROR: etiqueta = "[ERROR]"; break;
        case LogLevel::CRITICAL: etiqueta = "[CRITICAL]"; break;
        case LogLevel::SECURITY: etiqueta = "[SECURITY]"; break;
    }

    logFile << etiqueta << " " << mensaje << endl;
    logFile.close();
}

void logMessage(const string& mensaje, const string& archivo, int linea) {
    ofstream logFile("log.txt", ios::app);
    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return;
    }
    logFile << "[ERROR] " << mensaje << " (Archivo: " << archivo << ", Línea: " << linea << ")" << endl;
    logFile.close();
}

void logMessage(const string& mensaje, const string& usuario) {
    ofstream logFile("log.txt", ios::app);
    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return;
    }
    logFile << "[SECURITY] " << mensaje << " (Usuario: " << usuario << ")" << endl;
    logFile.close();
}

int main() {
    logMessage("Mensaje de depuración", LogLevel::DEBUG);
    logMessage("Mensaje informativo", LogLevel::INFO);
    logMessage("Mensaje de advertencia", LogLevel::WARNING);
    logMessage("Mensaje de error", LogLevel::ERROR);
    logMessage("Mensaje crítico", LogLevel::CRITICAL);
    logMessage("Access Granted", "usuario123");
    logMessage("Access Denied", "invitado");
    
    try {
        throw runtime_error("Excepción de prueba");
    } catch (const exception& e) {
        logMessage(e.what(), __FILE__, __LINE__);
        return 1;
    }
    
    cout << "Mensajes registrados en log.txt" << endl;
    return 0;
}