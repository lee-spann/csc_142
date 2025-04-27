
#include <iostream> 

using namespace std;  // standard namespace (p. 16)

int main() {  // main function entry point (p. 20)

    // initialize two arrays for comparison (p. 56)
    int arr1[] = {1, 2, 3, 4, 6};
    int arr2[] = {1, 2, 3, 4, 5};
    int biggestsize = 0;

    //+++++++++++++++++++++++++++++++++++++++++
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    if (size2 > size1){

        biggestsize = size2;
    }
    else biggestsize = size1;

    if (size1 != size2){
        printf ("Not the same.\n");
        return 0;
    }

    printf ("Biggest Size = %d\n", biggestsize);

    // flag to track if arrays are identical (p. 78)
    bool same = true;

    // iterate over elements of arrays using a for loop (p. 42)
    for (int i = 0; i < biggestsize; i++) {

        // check if elements at current index are different (p. 92)
        if (arr1[i] != arr2[i]) {

            // print the index where arrays differ (p. 15)
            cout << "Arrays differ at index " << i << endl;

            // print the differing values clearly (p. 92)
            cout << arr1[i] << " != " << arr2[i] << endl;

            // set boolean to false if a difference is found (p. 74)
            same = false;
        }
    }

    // output message if arrays are identical (p. 80)
    if (same) {
        cout << "Arrays are identical." << endl;
    }

    // exit the program successfully (p. 22)
    return 0;
}

