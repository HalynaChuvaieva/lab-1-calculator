#pragma once 
#include "Logger.h"

class Calculator {
private:
    Logger& logger;
public:
    Calculator(Logger& log) : logger(log) {}

    int add(int a, int b) {
        logger.log(INFO, "addition done: " + std::to_string(a) + " + " + std::to_string(b));
        return a + b;
    }

    int subtract(int a, int b) {
        logger.log(INFO, "substraction done: " + std::to_string(a) + " - " + std::to_string(b));
        return a - b;
    }

    int multiply(int a, int b) {
        logger.log(INFO, "multiplication done: " + std::to_string(a) + " * " + std::to_string(b));
        return a * b;
    }

    int divide(int a, int b) {
        if (b == 0) {
            logger.log(ERROR, "attempt to devide " + std::to_string(a) + " by 0!");
            throw std::runtime_error("division by 0 is impossible");
        }
        logger.log(INFO, "division done: " + std::to_string(a) + " / " + std::to_string(b));
        return a / b;
    }
};

