#ifndef LOG_SYSTEM_H
#define LOG_SYSTEM_H

#include <string>
using namespace std;

enum class LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL };

void logMessage(const string& mensaje, LogLevel nivel);

#endif