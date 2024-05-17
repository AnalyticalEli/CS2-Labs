////Eli Ahmed
////Lab 2b Binary Search (Harder No Vectors) USE THE OTHER ONE WITH VECTORS
//
//
//
//#include<iostream>
//
//using namespace std;
//
//
////Binary Search a String
//
//
//int binarySearch(const int anArray[], int size, int target) {
//
//	cout << "Determines if Array value is equal to target " << endl;
//
//	if (size == 1) {    //Base case if size is only 1 
//
//		if (anArray[0] == target)  //So if the target is found at
//			return 0;			   //index 0, returns 0;
//
//		else {			//Else it'll return -1;
//			return -1;
//		}
//
//	}
//
//
//
//	else {		//Remember that last of index array is null (\0) value 
//
//		int first = 0;     //Instatiating the first index
//		int last = size - 1;  //Instatiting that the size of the 
//		//last value of index is 1 smaller
//		//than actual size of index 
//
//		while (first <= last) {
//
//			//Assuming that last is greater or equal to first
//			//this determines where the midpoint is
//
//			int mid = first + (last - first) / 2;
//
//
//
//			if (anArray[mid] == target)
//				return mid;			//Target found in mid
//
//			else if (target < anArray[mid]) {
//				last = mid - 1;  //Searches in the first half
//
//			}
//
//			else
//				first = mid + 1;  //Searches in the second half
//
//		}
//
//
//		return -1;  //Cycles through above & if target not found
//		//returns -1 here. 
//
//	}
//
//
//
//}
//
//
//
//
//
//int main(void) {
//
//	//Instiatiting the vector.
//
//	int arr = { 2, 4, 6, 8, 10, 12, 14, 16, 20};
//	
//	cout << "Searching for 16" << endl;
//
//
//	int result = binarySearch(arr, size, );
//
//
//	cout << "Searching for 13";
//
//
//
//	return(0);
//}