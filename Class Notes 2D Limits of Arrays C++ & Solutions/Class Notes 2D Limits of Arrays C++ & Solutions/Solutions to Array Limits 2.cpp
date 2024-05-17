//Running at run time by user Inputs, using Array Pointers!


//#include<iostream>
//
//using namespace std;
//
//int main(void) {
//    int n;
//    char temp;
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
//    //this just dellocates, meaning the y* (y pointer) is still there but now it points
//   //to something we can't access.
//
//
//
//    y = nullptr;   //Whenever you delete a pointer like above, set it equal to nullptr, so other programmers
//    //don't accidently access it. 
//
//
////We are stuck with the pointer, but they take up like 4 bytes so they're better than regular arrays
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
//    cout << "Please enter an array size " << endl;
//    cin >> size;    //This is dynamic memory allocation. Getting memory and info at runtime from user.
//
//
//    int* arr = new int[5];
//
//
//
//    for (int i = 0; i < 5; i++) {     //Tells it to make the array of size 5 at run time, not compile time
//                                      //Meaning you can run it multiple times.
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
//
//    //int* z = &arr[size - 2];    //Nee
//
//
//    delete arr;
//
//    arr = nullptr;
//
//    arr = &x;   //Dereferencing x (gettting the value instead of address)
//
//    cout << *arr << endl;
//
//
//    return (0);
//}