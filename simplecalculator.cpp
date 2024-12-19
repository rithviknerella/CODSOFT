#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char oper;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the operator (+, -, *, /): ";
    cin >> oper;

    cout << "Enter the second number: ";
    cin >> num2;

    double result;

    switch (oper) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else
                cout << "Error: Division by zero!" << endl;
            break;
        default:
            cout << "Error: Invalid operator!" << endl;
            return 1; // exit with error code
    }

    cout << "Result: " << result << endl;

    return 0;
}
