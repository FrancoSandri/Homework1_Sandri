#include "log_system.h"
#include <iostream>
#include <fstream>

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
    }

    logFile << etiqueta << " " << mensaje << endl;
    logFile.close();
}

int main() {
    logMessage("Mensaje de depuración", LogLevel::DEBUG);
    logMessage("Mensaje informativo", LogLevel::INFO);
    logMessage("Mensaje de advertencia", LogLevel::WARNING);
    logMessage("Mensaje de error", LogLevel::ERROR);
    logMessage("Mensaje crítico", LogLevel::CRITICAL);
    
    cout << "Mensajes registrados en log.txt" << endl;
    return 0;
}