// Queue Examples (ONLY USE WHEN THE LINE IS GOING FORWARD)

//WILL NOT WORK GOING BACKWARD

#include <vector>
#include<queue>  //This is our line push allower
#include<stack>
#include<string>   
#include <iostream>
using namespace std;

int main(){

    //Doing Juan is not bad with queue
    queue<string> myQ;   //You have to declare data type of the queue<data_type>

    myQ.push("Juan");


    myQ.push("is");

    myQ.push("not");

    myQ.push("bad");

    

    while (!myQ.empty()) { //While the queue above is not empty (Juan is not bad) 

        cout << myQ.front() << endl;  //Spit out the first string
        
        myQ.pop();  //And deleted this string in front.

    }

    cout << endl;

    queue<string*> myQQ;    //Setting value of queue myQQ 

    myQQ.push(new string("juan"));

    myQQ.push(new string("is"));

    myQQ.push(new string("the"));

    myQQ.push(new string ("POS"));  

    


    int i = 0;
    cout << myQQ.size() << endl;


   // myQQ = temp;

    queue<string*> temp;

    while(!myQQ.empty()){   //While myQQ is not empty 

    //while (myQQ.front() + i != myQQ.empty()) {

        cout << *(myQQ.front()) << endl;
        temp.push(new string(*(myQQ.front())));
        delete myQQ.front();    //Memory Deallocation

        myQQ.pop();             //Memory Deallocation

    }


    //cout << *temp 


    //FIFO first in first out 

    myQQ = temp;

    cout << endl << endl;
     while(!myQQ.empty()){   //While myQQ is not empty. Verifying myQQ = temp worked.

        cout << (myQQ.front()) << endl;
        //cout << (temp.push(temp.front());
        //delete myQQ.front();    //Memory Deallocation

        //myQQ.pop();             //Memory Deallocation

    } 

     //MYQQ = temp points to the same whole queue



     //Stack LIFO. Last in Last out

     stack<string> myStack;

     myStack.push("juan");

     myStack.push("is");

     myStack.push("the");

     myStack.push("goat");


     while (!myStack.empty()) {   //While myStack isn't empty 

         cout << myStack.top() << " "; 

         myStack.pop();    //Pop's each one IF NOT empty.


     }   //Homework challange figure out what to do to print this in the same order in correct order
         //just using STACK!!