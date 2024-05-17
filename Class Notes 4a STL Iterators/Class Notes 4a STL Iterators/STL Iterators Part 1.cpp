//// Vector Example with Iterators
//
//#include <vector>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    vector<int> myVector;
//
//    // Populate the vector:  insert elements from -3 to 9     
//    for (int i = -3; i <= 9; i++) {  
//        myVector.push_back(i);
//    }
//
//    /* print number of elements by processing the distance between beginning and end
//     * - NOTE: uses operator - for iterators  */
//    cout << "number of elements/Distance in this case: " << myVector.end() - myVector.begin() << endl;
//
//    /* print all elements
//     * - NOTE: uses operator < instead of operator !=  */
//    vector<int>::iterator pos;     //this is a ptr. Iterators are like ptrs but they are a data type. pos = position. 
//
//    for (pos = myVector.begin(); pos < myVector.end(); pos++) {    //While it's not at the end, it keeps going. Like temp.next();
//        cout << *pos << ' ';  // dereference iterators just like pointers
//    }
//    cout << endl;
//
//    //We can't include end myVector.end() because it ends with a nullptr.
//
//    /* print all elements
//     * - NOTE: uses operator [] instead of the dereferencing operator (*) */
//    for (int i = 0; i < myVector.size(); i++) {
//        cout << myVector[i] << ' ';    //We aren't dereferencing, we're using [] instead. This gives us the value, instead of address.
//    }
//    cout << endl;
//
//    /* print every second element
//     * - NOTE: uses operator +=  iterator arithmetic */
//    for (pos = myVector.begin(); pos < myVector.end() - 1; pos += 2) {   //Indexing by skipping every other position.
//        cout << *pos << ' ';
//    }
//    cout << endl;
//}