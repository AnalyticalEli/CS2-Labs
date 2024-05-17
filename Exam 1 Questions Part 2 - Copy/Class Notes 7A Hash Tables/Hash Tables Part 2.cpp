////Hash Tables are LIKE arrays for Key Vales 
//
////Hash Tables Part 1
//
//
//#include <iostream>
//#include <cstdlib> 
//#include <ctime>  //For srand time
//#include <vector>
//using namespace std;
//
//
//// hash function (Keep it simple)
//int hashFunction(int ID, int tableSize) {
//	return(ID % tableSize);
//}
//
//
//void simplePrintTable(vector<int>[], int); //pass array and size
//
//
//
//int main(void) {
//	srand(time(0));
//	const int tableSize = 10;
//
//	// A c-type ARRAY of integer lists -- Want the indexing here.
//	vector<int> hashTable[tableSize];  //Array size 10 containing integer vectors.
//
//
//	for (int i = 0; i < 100; i++) {
//		int value = rand();
//		int key = hashFunction(value, tableSize);
//		hashTable[key].push_back(value);
//	}
//
//	//print th
//
//
//	vector<string> names[26];  //Because there are 26 letters
//
//	// put something in the first bucket which is a list.
//	hashTable[0].push_back(555);
//
//	//print the hash table
//	simplePrintTable(hashTable, tableSize);
//
//	cout << "\n*** Part II ***\n" << endl;
//
//	// populate the hash table with lots of collisions
//	for (int i = 0; i < 100; i++) {
//		int value = rand();
//		int key = hashFunction(value, tableSize);
//		hashTable[key].push_back(value);
//	}
//
//	//print the hash table
//	simplePrintTable(hashTable, tableSize);
//
//	return(0);
//}
//
////Implementations
//void simplePrintTable(vector<int> arg[], int size) {
//	// Print the buckets...
//	vector<int>::iterator myItr;
//
//	for (int i = 0; i < size; i++) {
//		cout << "bucket " << i << " ==> ";
//		myItr = arg[i].begin();
//
//		while (myItr != arg[i].end()) {
//			cout << *myItr << ", ";
//			myItr++;
//		}
//		cout << endl;
//	}
//}
//
