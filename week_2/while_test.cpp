#include <iostream>

int main(){

    double score;

    do {

        std:: cout<< "Enter a score between 1-100:";
        std:: cin >> score;
    } while(score < 1 || score > 100);
}