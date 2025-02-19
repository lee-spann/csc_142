/* 
   MPG.cpp
     Calculate the fuel efficiency of a vehicle
 
   Keyboard inputs:
     Vehicle description (string)
     Miles traveled (int)
     Fuel used in gallons (double)
 
   Outputs:
     Miles per gallon
 
   Name:
   Date:


  The starter file calculates the fuel efficiency of a vehicle in MPG (miles per gallon), a
    quantity commonly used in the US. In much of the rest of the world, fuel efficiency is
    often reported in L/100km (liters per 100 kilometers)

 
  Your task

    Extend the starter file to calculate both measures—MPG and L/100km—for the given
    user input.
    The starter file includes a constant for KM_PER_MILE which you must use in your
    calculation; you must also add a new constant for LITERS_PER_GALLON (you may need
    to use Google to find the correct conversion factor to use). Add appropriate constant(s),
    variable(s), assignment statement(s), and print statement(s) to the program to
    generate correct and understandable output. An example will be shown in class.
 

    For up to +2 points extra credit, format the output values to have exactly two digits to
    the right of the decimal place.
 */

#include <iostream>

int main(){   
    // Constant declarations
    const double KM_PER_MILE = 1.60934;
    const double LITERS_PER_GALLON = 3.7851178;
    
    // Variable declarations
    std::string desc;
    int miles;
    float gallons, liters;     
    float mpg, lkm, km;

    // Prompt for user inputs
    // Ensure that when typing input in the console, you give a whole number for miles,
    // otherwise you might run into miscalculations
    std::cout<<"Please enter a description of your car: ";
    std::getline(std::cin, desc);
    std::cout<<"How many miles did you drive? ";
    std::cin>>miles;
    std::cout<<"How many gallons of gas did you use? ";
    std::cin>>gallons;

    // Calculate the results
    mpg = miles / gallons;
    km = miles * KM_PER_MILE;
    liters = gallons * LITERS_PER_GALLON;
    lkm = liters / km * 100;

    // Print the user inputs and final results
    std::cout<<"\n";
    std::cout<<"Fuel efficiency of your " + desc + ":"<<std::endl;
    std::cout<<"You drove " << miles << " miles and used " << gallons << " gallons."<<std::endl;
    std::cout<<"Your fuel efficiency is " << mpg << " miles per gallon."<<std::endl;




    std::cout<<"\n";
    std::cout<<"Fuel efficiency of your " + desc + ":"<<std::endl;
    std::cout<<"You drove " << km << " kilometers and used " << gallons << " gallons."<<std::endl;
    std::cout<<"Your fuel efficiency is " << mpg << " miles per gallon."<<std::endl;    
    
    return 0;
}
