#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const double SALES_TAX_RATE = 0.06;
    bool keepGoing = true;
    
    while (keepGoing) {
        string description;
        string costInput;
        double cost;
        
        cout << "Enter a description of the purchase: ";
        getline(cin, description);
        
        do {
            cout << "Enter the cost of the purchase in dollars and cents: ";
            getline(cin, costInput);
            cost = stod(costInput);
            if (cost < 0) {
                cout << "Invalid input. Please enter a non-negative number." << endl;
            }
        } while (cost < 0);
        
        double salesTax = cost * SALES_TAX_RATE;
        double total = cost + salesTax;
        
        cout << fixed << setprecision(2);
        cout << "\nPurchase Details:" << endl;
        cout << "Description: " << description << endl;
        cout << "Cost: $" << cost << endl;
        cout << "Sales Tax: $" << salesTax << endl;
        cout << "Total Amount: $" << total << endl;
        
        string response;
        cout << "\nWould you like to enter another purchase? (Yes/No): ";
        getline(cin, response);
        
        if (response != "Yes" && response != "yes") {
            keepGoing = false;
        }
    }
    
    return 0;
}
