#include <cstdio>
#include <iostream>
#include <string>

#include <iostream>

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator {
    Operation op;

    Calculator(Operation operation) : op(operation) {}

    int calculate(int a, int b) {
        switch (op) {
            case Operation::Add:      return a + b;
            case Operation::Subtract: return a - b;
            case Operation::Multiply: return a * b;
            case Operation::Divide:
                if (b != 0) return a / b;
                std::cerr << "Error: Division by zero\n";
                return 0;
        }
        return 0;
    }
};

int main() {
    Calculator addCalc(Operation::Add);                          // direct init
    Calculator subCalc{Operation::Subtract};                    // brace init
    auto mulCalc = Calculator(Operation::Multiply);             // copy init
    auto divCalc = Calculator{Operation::Divide};               // brace + auto

    std::cout << "5 + 3 = " << addCalc.calculate(5, 3) << "\n";
    std::cout << "5 - 3 = " << subCalc.calculate(5, 3) << "\n";
    std::cout << "5 * 3 = " << mulCalc.calculate(5, 3) << "\n";
    std::cout << "5 / 3 = " << divCalc.calculate(5, 3) << "\n";

    return 0;
}
