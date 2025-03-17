#ifndef LOG_SYSTEM_H
#define LOG_SYSTEM_H

#include <string>
using namespace std;

// Niveles de log (actualizo en el inciso b y añado el SECURITY)
enum class LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL, SECURITY};

void logMessage(const string& mensaje, LogLevel nivel);

#endif