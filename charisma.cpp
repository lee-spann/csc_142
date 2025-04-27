#include <iostream>

int main() {
   srand(time(0));

    int charisma = rand() % 20 + 1;

    std::cout << "Charisma: " << charisma << std::endl;

    if (charisma >= 10)
    std::cout << "You may enter the castle!";
else

    std::cout << "You shall not pass!";

    



    return 0;
}
