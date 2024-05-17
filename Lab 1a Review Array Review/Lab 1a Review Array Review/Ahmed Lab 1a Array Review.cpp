//Eli Ahmed
//Lab 1a Reviewing Arrays


#include<iostream>
#include<ctime>   //for srand time
#include<cstdlib>   //for srand time

using namespace std;

// Regular C-type function prototypes
void printArray(const char arg[], const int n);      //This outputs the function 
void printArrayByPtr(const char arg[], const int n);    // this actually passes value by ptr.

int main(void) {
    srand(time(0));

    const int size = 15;    //15 elements, 16 spaces (for /0 null value)
    char a[size];

    // Populating the array with random letters from 'a' to 'z', using ASCII Values 
    for (int i = 0; i < size; i++) {      //for loop for random  

        a[i] = 'a' + rand() % 26;         //this uses the char value to get rand letter value a-z.
    }

    // Printing array memory addresses using index notation
    cout << "Printing array using index notation:" << endl;
    printArray(a, size);

    cout << "*************" << endl;  //Space between lines 

    // Printing array contents and memory addresses using pointers
    cout << "Printing array using pointers:" << endl;
    printArrayByPtr(a, size);

    return 0;
}

// Regular C-type function implementation to print array contents and memory addresses using index notation
void printArray(const char arg[], const int n) {
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = " << arg[i] << "\t Address: " << (void*)(&arg[i]) << endl;
        //&arg[i] is passing arg address, not actual value 

    }
}

// Regular C-type function implementation to print array contents and memory addresses using pointers
void printArrayByPtr(const char arg[], const int n) {
    const char* ptr = arg; // Pointer to the start of the array
    for (int i = 0; i < n; i++) {
        cout << "*(arg + " << i << ") = " << *(arg + i) << "\t Address: " << (void*)(ptr + i) << endl;

                                               //the ptr + 1; is pointer arithmetic, adding consecutively
                                               //what this does is goes to the next address in line!

                                               //*(arg + i) is dereferencing the ptr, and giving a value
                                               //instead of an address.

                                                //The void* ensures the data can be properly be ran through
                                                //given the data type.
    }
}