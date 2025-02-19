#include <iostream>
using namespace std;

int main() {
    int number;
    
    do {
        cout << "Enter an integer between 1 and 10: ";
        cin >> number;
        
        if (number < 1 || number > 10) {
            cout << "Invalid input. Please enter a number between 1 and 10." << endl;
        }
    } while (number < 1 || number > 10);
    
    string romanNumeral;
    if (number == 1) romanNumeral = "I";
    else if (number == 2) romanNumeral = "II";
    else if (number == 3) romanNumeral = "III";
    else if (number == 4) romanNumeral = "IV";
    else if (number == 5) romanNumeral = "V";
    else if (number == 6) romanNumeral = "VI";
    else if (number == 7) romanNumeral = "VII";
    else if (number == 8) romanNumeral = "VIII";
    else if (number == 9) romanNumeral = "IX";
    else if (number == 10) romanNumeral = "X";
    
    cout << "The Roman numeral for " << number << " is " << romanNumeral << "." << endl;
    
    return 0;
}