#include <iostream>


int main() {
	// Is arrayOne the same as arrayTwo?
    int arrayOne[5]={2,4,6,8,10};
    int arrayTwo[5]={2,4,6,8,10};


        if (arrayOne == arrayTwo){
            printf ("They are the same.\n"); }
        else {
            printf ("They are NOT the same.\n"); }
       


// Print the memory addresses
std::cout << arrayOne << "\n";
std::cout << arrayTwo << "\n";


return 0;


}
