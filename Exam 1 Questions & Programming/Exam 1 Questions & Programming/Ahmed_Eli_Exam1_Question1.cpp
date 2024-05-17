////Eli Ahmed
////Exam 1 Question 1 (CODE SEGMENT)
//
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//
//template<class T>    //The fact that class T is not initalized T = [dataType], means we have FREEDOM of any datatype
//class Node {
//public:
//    T obj;
//    Node* next;
//    Node* prev;
//
//    Node<T>(T arg) { obj = arg; };
//    ~Node<T>(void) { cout << "Node Deallocated!" << endl; };
//};
//
////C-type Function Prototypes (FOR EXACT FUNCTION YOU GAVE US)
//
//template<typename T>
//void printForward(Node<T>* head);
//
//template<typename T>
//void printReverse(Node<T>* head);
//
//template<typename T>
//void deallocateList(Node<T>* head);   //C-type function that I made to deallocate memory in each node to free up space taken by 
//                                      //Linked List.
//
//
//int main(void) {
//
//     //A) Using Original Constructor & Deconstructor + Head Node Juan.
//        
//     Node<string>* head = new Node<string>("Juan");
//
//     head->next = new Node<string>("is");  //Moving the head to nextNode 
//
//     head->next->prev = head;   //Going to the next node to connect is to Juan
//
//     head->next->next = new Node<string>("the");
//
//     head->next->next->prev = head->next;  //Connecting "the" to the previous Juan & this 
//
//     head->next->next->next = new Node<string>("GOAT");  
//
//     head->next->next->next->prev = head->next->next;  //Conneceting the GOAT to the rest of the Linked List
//
//     head->next->next->next->next = nullptr;  //Setting the end equal to a nullptr;
//
//
//
//
//    //B) Printing List Fowards and Backwards 
//
//    cout << "Print the List Forwards: ";
//    printForward(head);
//
//
//    cout << "Printing the List in Reverse: ";
//    printReverse(head);
//
//
//
//    //C) Memory deallocation (Using Deallocation Function) 
//
//    deallocateList(head);
//
//
//
//    return(0);
//
//}
//
//
//
//
//template<typename T>
//void printForward(Node<T>* head) {
//    cout << "\n*** Print Forward ***" << endl;
//    Node<T>* cur = head;
//    if (cur == nullptr) {
//        cout << "List Empty" << endl;
//    }
//    else {
//        do {
//            cout << cur->obj << " ";
//            cur = cur->next;
//        } while (cur != nullptr);
//        cout << endl;
//    }
//    cout << "***  ***  ***\n" << endl;
//}
//
//template<typename T>
//void printReverse(Node<T>* head) {
//    cout << "\n*** Print Reverse ***" << endl;
//    Node<T>* cur = head;
//    if (cur == nullptr) {
//        cout << "List Empty" << endl;
//    }
//    else {
//        //iterate to end;
//        while (cur->next != nullptr) {
//            cur = cur->next;
//        }
//        cout << cur->obj << " ";
//        while (cur->prev != nullptr) {
//            cur = cur->prev;
//            cout << cur->obj << " ";
//        }
//        cout << endl;
//    }
//    cout << "***  ***  ***\n" << endl;
//}
//
//
//
//template<typename T>
//void deallocateList(Node<T>* head) {  //Deallocates memory in nodes, and frees up space.
//
//
//    Node<T>* temp;  //Node is temp (or temporary PlaceHolder)
//
//    while (head != nullptr) {   //While it's not nullptr 
//
//        temp = head;
//
//        head = head->next;
//        
//        delete temp;
//
//
//    }
//
//    head = nullptr;  //Sets head to nullptr after deallocating.
//}
//
