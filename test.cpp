#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char op;
    char choice;

    do {
        cout << "=== BASIC CALCULATOR ===\n";
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;
        cout << "Enter second number: ";
        cin >> num2;

        switch (op) {
            case '+':
                cout << "Result: " << num1 + num2 << "\n";
                break;
            case '-':
                cout << "Result: " << num1 - num2 << "\n";
                break;
            case '*':
                cout << "Result: " << num1 * num2 << "\n";
                break;
            case '/':
                if (num2 != 0)
                    cout << "Result: " << num1 / num2 << "\n";
                else
                    cout << "Error: Division by zero!\n";
                break;
            default:
                cout << "Invalid operator!\n";
        }

        cout << "\nCalculate again? (y/n): ";
        cin >> choice;
        cout << "\n";
    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!\n";
    return 0;
}
