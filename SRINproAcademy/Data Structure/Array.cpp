#include <iostream>
using namespace std;


int main()
{
    // --------------------------------------------------------------
    
    // program to demonstrate that array elements are stored
    // contiguous locations

    // an array of 10 integers.  If arr[0] is stored at
    // address x, then arr[1] is stored at x + sizeof(int)
    // arr[2] is stored at x + sizeof(int) + sizeof(int)
    // and so on.
    int arr[5], i;
    
    printf("Size of integer in this compiler is %u\n", sizeof(int));
    
    for (i=0; i<5; i++)
        // The use of '&' before a variable name, yields
        // address of variable.
        printf("Address arr[%d] is %u\n", i, &arr[i]);
 

    // --------------------------------------------------------------

    // Array declaration by specifying size
    int arr2[10];

    // Array declaration by initializing elements 
    int arr3[] = {10, 20, 30, 40};
 
    // Array declaration by initializing elements, but with not enough initial data
    // This will make the rest of the data filled automatically with 0
    int arr4[10] = { 10, 20, 30, 40 }; // the rest will be filled with { 0, 0, 0, 0, 0, 0 }

    // A trick to declare + initialize array to 0
    int arr5[1000] = { 0 };

    // --------------------------------------------------------------

    // in primitive C/C++ (no access to String.h) an array of char is used to represent string
    char str[] = "sidangdut";
    cout << str << endl;

    // --------------------------------------------------------------

    return 0;
}