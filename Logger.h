#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
enum LogLevel { INFO, WARNING, ERROR };

class Logger {
private:
    ofstream logFile;
public:
    Logger(const string& filename) {
        logFile.open(filename, ios::app);
    }

    ~Logger() {
        if (logFile.is_open()) logFile.close();
    }

    void log(LogLevel level, const string& message) {
        string prefix;
        switch (level) {
        case INFO: prefix = "[INFO] "; break;
        case WARNING: prefix = "[WARNING] "; break;
        case ERROR: prefix = "[ERROR] "; break;
        }

        cout << prefix << message << endl;

        if (logFile.is_open()) {
            logFile << prefix << message << endl;
        }
    }
};
