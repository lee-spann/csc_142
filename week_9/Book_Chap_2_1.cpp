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

int main() {
    Operation op = Operation::Add;
    if (op == Operation::Add) {
        std::cout << "Operation is Add\n";
    }
    return 0;
}
