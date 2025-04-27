#include <iostream>
#include <cmath>
#include <random>

int main(){
    int random_number = 0;


    int i;
    srand(time(0));
    for (i=0; i<11;i++){
random_number = rand();
random_number = random_number % 5 + 1;

std::cout << random_number << "\n";


    }
}
