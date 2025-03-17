#include "ejercicio2.h"
#include <iostream>
#include <fstream>

// Función que registra un mensaje en el archivo de log
void logMessage(const string& mensaje, LogLevel nivel) {
    // Abro el archivo de log en modo append
    ofstream logFile("log.txt", ios::app);
    // Si no se pudo abrir el archivo, muestro un mensaje de error y termino la función
    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return;
    }
    // Defino la etiqueta del mensaje según el nivel. En el inciso b, añado el SECURITY.
    string etiqueta;
    switch (nivel) {
        case LogLevel::DEBUG: etiqueta = "[DEBUG]"; break;
        case LogLevel::INFO: etiqueta = "[INFO]"; break;
        case LogLevel::WARNING: etiqueta = "[WARNING]"; break;
        case LogLevel::ERROR: etiqueta = "[ERROR]"; break;
        case LogLevel::CRITICAL: etiqueta = "[CRITICAL]"; break;
        case LogLevel::SECURITY: etiqueta = "[SECURITY]"; break;
    }
    // Registro el mensaje en el archivo de log
    logFile << etiqueta << " " << mensaje << endl;
    logFile.close();
}

// Función que registra un mensaje de error en el archivo de log, incluyendo el archivo y la línea donde se generó el error
void logMessage(const string& mensaje, const string& archivo, int linea) {
    // Abro el archivo de log en modo append
    ofstream logFile("log.txt", ios::app);
    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return;
    }
    // Registro el mensaje de error en el archivo de log, incluyendo el archivo y la línea.
    logFile << "[ERROR] " << mensaje << " (Archivo: " << archivo << ", Línea: " << linea << ")" << endl;
    logFile.close();
}

// Función que registra un mensaje de seguridad en el archivo de log, incluyendo el usuario que realizó la acción
void logMessage(const string& mensaje, const string& usuario) {
    // Abro el archivo de log en modo append
    ofstream logFile("log.txt", ios::app);
    if (!logFile) {
        cerr << "Error al abrir el archivo de log." << endl;
        return;
    }
    // Registro el mensaje de seguridad en el archivo de log, incluyendo el usuario.
    logFile << "[SECURITY] " << mensaje << " (Usuario: " << usuario << ")" << endl;
    logFile.close();
}

int main() {
    // Registro mensajes de diferentes niveles en el archivo de log. Uno de cada tipo.
    logMessage("Mensaje de depuración", LogLevel::DEBUG);
    logMessage("Mensaje informativo", LogLevel::INFO);
    logMessage("Mensaje de advertencia", LogLevel::WARNING);
    logMessage("Mensaje de error", LogLevel::ERROR);
    logMessage("Mensaje crítico", LogLevel::CRITICAL);
    logMessage("Acceso Garantizado", "usuario123");
    logMessage("Acceso Denegado", "invitado");
    
    // Registro un mensaje de error en el archivo de log, incluyendo el archivo y la línea donde se generó el error
    try {
        // Lanzo una excepción de prueba
        throw runtime_error("Excepción de prueba");
    } catch (const exception& e) {
        // Registro el mensaje de error en el archivo de log, incluyendo el archivo y la línea.
        logMessage(e.what(), __FILE__, __LINE__);
        return 1;
    }
    
    //Imprimo este mensaje para ver si se ejecutan los diferentes mensajes.
    cout << "Mensajes registrados en log.txt" << endl;
    return 0;
}