//Class Notes Recursion 1g
//Day 4 Notes 


#include<iostream>

using namespace std;


// Recursive functions do func


bool isPrime(int p, int i = 2) {     //Recursive Function

	if (i == p) return 1;   //This is called a recursive stack 

	if (p % i == 0) return 0;  //starts with 7 % 2, then goes to 7 % 3, 7 % 4....all the way until 7 % 7
							   //where we finally get i == p, (7 == 7) so it breaks the loop and returns 1

	return isPrime(p, i + 1);



}

//Recursive functions are USUALLY faster than iterative fnctions (for loop)
//That speed comes at the cost of temperary memory.  (Recursive functions take more memory) 


bool iterPrime(int p) {   //Iterative Function for Prime Searching 

	for (int i = 2; i <= p; i++) {

		if (i == p) return 1;

		if (p % i == 0) return 0;

	}


}




int fibonacci(int x) {   //Fibonacci Sequence (With Recursion)

	if (x < 2) return x;
	return (fibonacci(x - 1) + fibonacci(x - 2));  //Basically saying if x < 2, then return 1;


}



int iterFib(int x) {   //Fibonacci Sequence (With Interation)

	int sum = 0;

	int x1 = 0;   //3

	int x2 = 1;   //5

	for (int i = 0; i < x; i++) {

		sum = x1 + x2;  //Will make sum = 8,

		x1 = x2;      //5

		x2 = sum;     //8


	}

	return sum;

}




int binarySearch(const int anArray[], int first, int last, int target) {   //Iterative 


	int index;

	if (first > last) {   //Assuming it's in numerical order
		index = -1;
	}


	else {

		int mid = first + (last - first) / 2;

		if (target == anArray[mid])
			index mid;

		else if (target < anArray[mid])
			index = binarySearch(anArray, first, mid - 1, target);


		else
			index = binarySearch(anArray, first, mid + 1, target);



	}

	return(index);

}






int main(void) {

	int x = 7;       //x = 7

	//bool y = isPrime(x);   //This is why we use 7 for the recursive stack isPrime above!! Because x = 7;

	bool y = iterPrime(x);   //This is the iterprime function.

	int z = fibonacci(x);     //Recursion Fibonacci


	int z2 = iterFib(x);     //Fibonacci with Iteration (For loop) 





	


	if (y == 0) {

		cout << x << "is not prime? ";


	}

	else {

		cout << x << "is prime ";

	}


	cout << "*************************" << endl << endl;

	cout << "The " << x << "fibonacci number is " << z << endl;   //X gives number in fibonnaci sequence
																  // 1,1,2,3,5,8,13. X=7, is 13 which is z



	//cout << binarySearch(arr, 0, 4, 8) << 

	if (y == 0) {

		cout << x << "is not prime? ";


	}

	else {

		cout << x << "is prime ";

	}



	return(0);
}
