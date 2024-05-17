#include<iostream>

using namespace std;

int main(void) {
    int n;
    char temp;

    // exploring the limitations of arrays
    const int size = 5; // arrays can't change size at runtime.  WTF. LAME!
    int arr[size]; // indices of 0, 1, 2 and array size 3;
    
    arr[0] = 1;
    arr[1] = 7;
    arr[2] = 13;
    arr[3] = -2;
    arr[4] = 168;

    for (int n = 0; n < size; n++) {
        cout << "arr[" << n << "] = " << arr[n] << " stored at " << int(&arr[n]) << endl;

    }
    arr[1] = '\0';  // sets the value to zero, not ideal in an int array;
    for (int i = 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = 0;


    cout << "\n*************************************\n";
    for (int n = 0; n < size; n++) {
        cout << "arr[" << n << "] = " << arr[n] << " stored at " << int(&arr[n]) << endl;

    }


    return 0;
}