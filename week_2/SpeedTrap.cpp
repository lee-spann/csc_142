#include <iostream>
using namespace std;

// Name: [Lee Spann]
// Date: [Febuary 2025]
// Program: SpeedTrap - Checks if a driver is speeding

int main() {
    int speedLimit;
    double driverSpeed;
    
    cout << "Enter the speed limit: ";
    cin >> speedLimit;
    
    cout << "Enter the driver's speed: ";
    cin >> driverSpeed;
    
    if (driverSpeed <= speedLimit)
        cout << "The speed is legal." << endl;
    else
        cout << "The driver will receive a speeding ticket." << endl;
    
    return 0;
}
