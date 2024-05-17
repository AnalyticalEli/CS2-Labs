//Code Snippets

#include<iostream>

using namespace std;


int sumUpTo(int n) {


	int sum = 0;

	if (n == 1) {
		sum = 1;
	}

	else
		sum = n + sumUpTo(n - 1);

	return sum;

}


int main(void) {

	cout << sumUpTo(8) << endl;

	return(0);




}