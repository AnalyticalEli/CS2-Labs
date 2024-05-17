////eli ahmed
////lab 1a
//
//#include<iostream>
//#include<ctime>   //for srand time
//#include<cstdlib>	//for srand time
//
//
//using namespace std;
//
//
//
////regular c-type function prototype
//
//void printarray(int arg[], const int n);  //this prints/outputs our function
//
//
//void printarraybyptr(int* arg, const int n); // this actually passes value by ptr.
//
//
//int main(void) {
//
//	srand(time(0));
//
//	const int size = 15;  //15 elements, 16 spaces (for /0 null value)
//	int a[size];
//	
//
//	for (int i = 0; i < size; i++) {      //for loop for random  
//
//		a[i] = 'a' + rand() % 26;   //this uses the char value to get rand letter value a-z.
//
//	}
//
//
//	printArray(a, size);    //Printing array using indexing notation.
//
//
//	cout << "*************" << endl;
//
//
//	printArrayByPtr(a, size);   //passes values of array above into ptr, which points to address
//
//								//a is being passed as ptr (address) and size, is being passed as const int
//
//	return(0);
//
//}
//
//
//
//
////c-type function implementation (for print array)
//
//
//
//void printArray(char arg[], const int n) {     //void printarray(int arg[], const int n)
//
//
//	for (int i = 0; i < n; i++) {
//
//
//		cout << "a[ " << i << " ]" << "\tAddress" << reinterpret_cast<int>(&arg[i]) << endl;  
//													//&arg[i] is passing arg address, not actual value 
//													//Reinterpert Cast, turns our char address to an int
//
//
//	}
//
//
//
//
//}
//
//
//
//void printArrayByPtr(char* arg, const int n) {
//
//
//	for (int i = 0; i < n; i++) {
//
//
//		cout << i << *(arg + i) << "has address " << arg + i << endl;  //the arg + 1; is pointer arithmetic, adding consecutively
//												//what this does is goes to the next address in line!
//
//												//*(arg + i) is dereferencing the ptr, and giving a value
//												//instead of an address.
//	}
//
//}
//
//
//
//
//
//
//
