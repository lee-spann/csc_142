
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
            case Operation::Add:
                return a + b;
            case Operation::Subtract:
                return a - b;
            case Operation::Multiply:
                return a * b;
            case Operation::Divide:
                if (b != 0) return a / b;
                std::cerr << "Error: Division by zero\n";
                return 0;
        }
        return 0; // fallback
    }
};

int main() {
    Calculator calc(Operation::Multiply);
    std::cout << "5 * 3 = " << calc.calculate(5, 3) << "\n";
    return 0;
}

