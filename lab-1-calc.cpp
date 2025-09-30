#include "Calculator.h"
#include <iostream>
using namespace std;
int main() {
    Logger logger("logs.txt");
    Calculator calc(logger);

    int a, b;
    char op;

    cout << "Enter the first number: ";
    cin >> a;

    cout << "Enter operation (+, -, *, /): ";
    cin >> op;

    cout << "Enter the second number: ";
    cin >> b;

    try {
        int result;
        switch (op) {
        case '+':
            result = calc.add(a, b);
            break;
        case '-':
            result = calc.subtract(a, b);
            break;
        case '*':
            result = calc.multiply(a, b);
            break;
        case '/':
            result = calc.divide(a, b);
            break;
        default:
            logger.log(WARNING, "Unknown operation: " + string(1, op));
            cout << "Error: unknown operation!" << endl;
            return 1;
        }

        cout << "Result: " << result << std::endl;
    }
    catch (const exception& ex) {
        logger.log(ERROR, std::string("Execution error: ") + ex.what());
        cout << "Error: " << ex.what() << endl;
    }

    return 0;
}

