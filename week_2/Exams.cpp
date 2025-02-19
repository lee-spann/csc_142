#include <iostream>
#include <string>

int main(){
std:: string name;
int exam1, exam2, exam3;
float average;

std::cout << "What is your name?:";
std::cin >> name ;

std::cout << "What is your first exam score?:";
std::cin >> exam1 ;

std::cout << "What is your second exam score?:";
std::cin >> exam2 ;

std::cout << "What is your third exam score?:";
std::cin >> exam3 ;

average = (exam1 + exam2 + exam3) /3.0f; 
printf ("The average score is %.2f\n",average);


}