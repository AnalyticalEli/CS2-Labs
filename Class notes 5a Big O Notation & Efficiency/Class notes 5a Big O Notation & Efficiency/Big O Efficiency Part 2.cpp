//Big O Efficiency Part 1  (Correct with Jefe CODE) 

//O(1)  Constant aka Immediately (Best)
//O(n)  Linear order/Search (Longer time than O(1))
//O(n^2) Quadratic Time (Nested for loop slower than both O(1) & O(n))
//O! Least efficient of all Notation

//We typically dictate O notation By WORSE CASE SCENARIO

//For example say in your code you have O(n) & O(!) 
//O notation would take worse case, which is O(!) 


#include<iostream>
#include<string>  //For string and any getline.
#include<cstdlib>  //For srand time
#include<ctime>    //For srand time

using namespace std;

// Function to print an array
int shellSort(int arr[], int n);
void printArray(int arr[], int size);


void main(void) {
    srand(time(NULL));
    const int n = 1000;
    int arr[n], arr2[n];
    bool swapped;
    int counter = 0; // this is a counter for comparisons in our sorting algorithm.
    int shellCount;

    for (int i = 0; i < n; i++) {
        arr[i] = 1 + rand() % 250;
        arr2[i] = arr[i];
    } // this is not part of the sorting algorithm, don't count shit here.

    //printArray(arr, n); // this is the unsorted print
    cout << endl << endl;

    shellCount = shellSort(arr2, n);
    //printArray(arr, n); // this is the unsorted print

    // sorting algorithm begins here.
    for (int i = 0; i < n - 1; i++) { // bubble sort
        counter++; // counter = counter + 1;
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            counter++; // this is for the j loop
            counter++; // this is for the if statement
            if (arr[j] > arr[j + 1]) {

                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        counter++; // this is for the comparison that failed in j loop, when j = n-i-1
        // If no two elements were swapped by inner loop, then break
        counter++; // this is for the if statement below
        if (swapped == false)
            break;
    }
    counter++; // this is for the comparison that failed in i loop, when i = n-1

    cout << "For an array of size " << n << ", the bubble sort took " << counter << " comparisons." << endl;
    cout << "For an array of size " << n << ", the shell sort took " << shellCount << " comparisons." << endl;
    //printArray(arr, n); // this is the sorted print

    cout << endl << endl;
    return;
}

int shellSort(int arr[], int n) {
    int counter = 0;
    int temp, j;
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        counter++;
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted 
        for (int i = gap; i < n; i += 1) {
            counter++;
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            temp = arr[i];

            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                counter++; // this is for j>= gap
                counter++; // this is for arr[j-gap] > temp;
                arr[j] = arr[j - gap];
            }
            counter++; // this is for at least one of the for comparisons failing
            counter++; // this is for both failing in the inner for loop
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
        counter++; // this is for the middle for loop
    }
    counter++; // this is for the outer for loop
    return counter;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
}

