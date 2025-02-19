#include <iostream>
#include <cstdio>
#include <string>
#include <format>

int main(){
    int hours = 5;

    printf("I worked %d hours. \n" , hours);

    std::string formatted = std::format("I worked{:d} hours. \n" , hours);
    std::cout<<formatted;

    return 0;
}