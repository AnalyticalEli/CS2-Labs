//Review CS001

// Pointer Primer


#include <iostream>		
using namespace std;

//int main(void) {

//	/* Pointers ******************/
//	int x = 5;
//	int* xPtr = &x;		  // set the pointer xPtr to the address of x, cstring
//
//	//int *xPtr = &x;       Bad practice DON'T do this!
//
//	cout << x << endl;  // on screen 5
//	cout << &x << endl;   // & address of x, so it's going to spit out the address in hexadecimal
//	cout << xPtr << endl;  // should be  the same as previous line.
//	cout << *xPtr << endl;		// * dereferences the pointer xPtr/allows us to spit out 5
//
//	cout << "*********************\n" << endl;
//
//
//	/* c-strings - character arrays terminated by '\0'  ***********/
//	char a[] = "Juan";			// c-string - character array terminated by '\0'
//	char* aPtr = &a[0];     // declare aPtr to be a character pointer
//
//
//	cout << a << endl;
//	cout << &a[1] << endl;		// a is actually a pointer to the first element in the array
//
//	cout << aPtr << endl;      // this spits out hte contents of the array, not address
//	cout << int(aPtr) << endl;		// integer address instead of hexidecimal
//
//	for (int i = 0; i <= 6; i++) {
//		cout << int(&a[i]) << endl;    //Goes pass the array, which is fine because we were doing addresses. 
//	}
//
//
//	//double xArr[5] = { 0.0, 1.0, 2.0, 3.0, 4.0 };
//
//
//	//for (int i = 0; i <= 6; i++) {
//	//	cout << int(&xArr[i]) << endl;    //Goes pass the array, which is fine because we were doing addresses. 
//	//}
//
//
//
//	//cout << xArr << " Space here " << xArr[0] << endl;  //gives us adresss for first element of array
//
//	cout << "*********************\n" << endl;
//
//
//	/* pointers and pointer arithmetic **********/
//	int b[] = { 1,2,3 };				// array store memory in sequential memory locations
//	int* bPtr = b;
//
//	cout << bPtr << endl;  //Show us the address of the first element.
//	cout << *bPtr << endl;
//	cout << bPtr + 1 << endl;		// the next memory address after bPtr or the next address
//
//	cout << *bPtr + 1 << endl;  //Added one to first elemnet of b, but doesn't change value in array
//	//Doesn't change value in array!
//
//	//*bPtr = *bPtr + 1;   	//If wanted to increment it by 1, you'd do this:
//
//
//
//	cout << *bPtr + 1 << endl;
//
//	cout << *(bPtr + 1) << endl;
//
//	for (int i = 0; i < 3; i++) {
//		cout << "Address " << bPtr + i << " contains " << *(bPtr + i) << endl;
//	}
//
//	cout << "*********************\n" << endl;
//
//
//	return(0);
//}



// Function Notes


//Function Implementations.

int squareFun1(int);		//pass by value
int squareFun2(int&);		//Pass by reference using reference arguments  
int squareFun3(int*);		//pass by reference using pointer arguments 


int main(void) {

	int x = 5;
	int* xPtr = &x;

	cout << squareFun1(x) << endl;
	cout << "x after function call = " << x << endl;	// function can not modify x

	cout << squareFun2(x) << endl;
	cout << "x after function call = " << x << endl;	// function can modify x

	cout << squareFun3(xPtr) << endl;
	cout << "x after function call = " << x << endl;	// function can modify x


	return(0);
}

// Function implementations
int squareFun1(int pass) {
	int result = pass * pass;
	pass = 10;    //This line did nothing. Nothing was changed in the original 
				  //and it didn't change value.
	return(result);

}

int squareFun2(int& pass) {
	int result = pass * pass;
	pass = 10;    //This line edited orginal Value of x to 10
	return(result);

}

int squareFun3(int* pass) {
	int result = (*pass) * (*pass);  // must dereference then mult
	*pass = 20;		//Changes value from 5 to 20, AFTER dereferencing it & changes main as well
	return(result);

}



//squareFun2 & squareFun3, same results. Spit out same crap, and both edit value in main
//Using pointers is more work, but what about arrays?
// 
// Both work when using arrays
//
//When using Linked list squareFun2 sucks because it requires more crap.
// 
//it's going of address and doing address arthimetic (using i in a for loop)
//pointer arithmetic works just fine


//Linked List DO NOT require sequential memory, like a for loop.
//They point individually to different places.



