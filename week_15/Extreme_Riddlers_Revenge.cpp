#include <iostream>
#include <tuple>
#include <string>

std::tuple<int, std::string, bool> getRiddleInfo() {
    return std::make_tuple(7, "What has roots as nobody sees, is taller than trees...", true);
}

int main() {
    int riddleNumber;
    std::string riddleText;
    bool solved;

    std::tie(riddleNumber, riddleText, solved) = getRiddleInfo();

    std::cout << "Riddle #" << riddleNumber << ": \"" << riddleText << "\"\n";
    std::cout << "Solved: " << (solved ? "Yes" : "No") << "\n";

    return 0;
}
