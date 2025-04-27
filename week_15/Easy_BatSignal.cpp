
#include <iostream>
#include <utility>

int main() {
    std::pair<std::string, std::string> alert{"Joker", "Arkham Asylum"};
    std::cout << alert.first << " spotted at " << alert.second << "!\n";
    return 0;
}
