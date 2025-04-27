#include <iostream>

int main() {
    int numberOfLikes = 0;

std::cout << "How many likes?: ";
std::cin >> numberOfLikes;

for (int i = 1; i <= numberOfLikes; ++i) {
        std::cout << "\n"<< "Like #" << i << std::endl;

        if (i == 10) {
        std::cout << "Your post is popular" << std::endl;
        }
    }

    return 0;
}
