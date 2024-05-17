//#include<iostream>
//
//using namespace std;
//
//int main(void) {
//    int n;
//    char temp;
//
//    //// exploring the limitations of arrays
//    //const int size = 5; // arrays can't change size at runtime.  WTF. LAME!
//    //int arr[size]; // indices of 0, 1, 2 and array size 3;
//
//
//    //arr[0] = 1;
//    //arr[1] = 7;
//    //arr[2] = 13;
//    //arr[3] = -2;
//    //arr[4] = 168;
//
//    //for (int n = 0; n < size; n++) {
//    //    cout << "arr[" << n << "] = " << arr[n] << " stored at " << int(&arr[n]) << endl;
//
//    //}
//    //arr[1] = '\0';  // sets the value to zero, not ideal in an int array;
//    //for (int i = 1; i < size - 1; i++) {
//    //    arr[i] = arr[i + 1];
//    //}
//    //arr[size - 1] = 0;
//
//
//    //cout << "\n*************************************\n";
//    //for (int n = 0; n < size; n++) {
//    //    cout << "arr[" << n << "] = " << arr[n] << " stored at " << int(&arr[n]) << endl;
//
//    //}
//
//
//
//    //This all sucks. We do not have dynamic mememory allocation which happens at runtime
//    //not compile time.
//
//    //Everything above was done during compile time.
// 
// 
//	 //So how do we make it run at run time? (Next Part)
//
//
//     
//    int x = 5;  //Stuck with it
//
//    //but what if this is your BBEG (Big Bad Evil Guy),and you kill him in game (he's still there)
//
//    int* y = new int(10);
//
//    cout << y << endl;   //Gives 
//
//    cout << *y << endl;   //
//
//
//    delete y;  //No issues with deleting y. I couldn't delete at x earlier.
//               //this just dellocates, meaning the y* (y pointer) is still there but now it points
//              //to something we can't access.
//
//
//
//    y = nullptr;   //Whenever you delete a pointer like above, set it equal to nullptr, so other programmers
//                   //don't accidently access it. 
//
//
//    //We are stuck with the pointer, but they take up like 4 bytes so they're better than regular arrays
//
//
//    y = &x;
//
//
//    cout << y << endl;
//
//    cout << *y << endl;
//
//
//
//    int size = 5;   //Declaring size of array below
//
//
//    cout << "Please enter an array size "
//
//    int* arr = new int[5];
//
//
//
//    for (int i = 0; i < 5; i++) {
//
//        arr[i] = i;
//
//    }
//
//
//    for (int n = 0; n < size; n++) {
//        cout << "arr[" << n << "] = " << arr[n] << " stored at " << int(&arr[n]) << endl;
//
//    }
//
//
//    return (0);
//}