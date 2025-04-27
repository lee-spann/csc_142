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
};

int main() {
    Calculator calc(Operation::Subtract);
    std::cout << "Calculator created.\n";
    return 0;
}

