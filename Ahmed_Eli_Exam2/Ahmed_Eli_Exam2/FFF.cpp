////Eli Ahmed 
////Exam 2 One Assigment to Rule Them ALL (Books) 
//
////To Be Slightly Conceited and Give Myself A Challenge I Did the BST 2 ways (One is commeneted out BELOW THE ONE I USED) 
////It works with the same harded coded section above & outputs the same thing just done differently. (Essentially if you think the 9 objects above isn't pretty, and want to op for 4)
//
////I also gave you the option of testing different criteria when using the addNode function by giving you an extra comparator 
////that sorts by RANK (all you need to do is replace the comparators in addNode to use) 
//
//
//#include<iostream>
//#include<string>
//#include<map>  //For map key values
//#include<queue>
//#include<stack>  //We might need this for the queue
//#include<list>  //For list that stores M
//
//using namespace std;
//
//class Book {   //Three Books: Fav Blood Meridian Cormac McCarthy,  2 second: The House of Leaves Mark 
//    //The Passanger Cormac McCarthy.  
//
//private:
//
//    string bookName, authorName;
//    string genre;
//    int rank;
//    string webLink;
//
//
//public:
//
//    //General Constructor (Prototype)  Initiliazing base values 
//
//    Book(string argB = "", string argN = "", string argG = "", int argR = 0, string argW = "");  //Setting all values = to a base case so
//    //if nothing is entered it will print out what we have here.
//
//
//
////Accessor Methods (Get and Set)
//
//    void setBookName(string argB);
//    void setAuthorName(string argN);
//    void setGenre(string argG);
//    void setRank(int argR);
//    void setLink(string argW);
//
//    string getBookName(void);
//    string getAuthorName(void);
//    string getGenre(void);
//    int getRank(void);
//    string getLink(void);
//
//    void display();
//
//    //Two differnt displays 
//
//    void displayGenre();
//    void displayBookName();
//};
//
//class Node {
//private:
//    Node* left;
//    Node* right;
//    Book valueB;
//
//public:
//
//    //Node Constructor Prototype
//    Node(Book arg);   //Only including arg, because the other two are being set to nullptr. (Node* data type)
//
//    //Node Accessor Methods
//    void setLeft(Node* arg);
//    Node* getLeft(void);
//    void setRight(Node* arg);
//    Node* getRight(void);
//    void setValue(Book arg);  //Get and set methods for the Book value above in private Node
//    Book getValue(void);
//
//    //Utility Methods
//    void report(void);
//
//    void deleteHangingNode(void);
//};
//
//class BinarySearchTree { // this is our forked version of linked list.
//private:
//    Node* root;
//public:
//
//    BinarySearchTree(Book arg);
//    Node* getRoot(void);
//    void setRoot(Node* arg);
//    void deleteTree(void);
//    void print(void);
//    void addNode(Book arg);   //Add nodes after the first 3 for the Book Class in Main
//};
//
//
////C-type Comparators Protoype (Using this to Sort)
//
////bool compareRanking(Book arg1, Book arg2);   //Comparing by Rank. (1-9) 
//bool compareBookName(Book arg1, Book arg2);  //This is comparing the values within the Name! (ASCII) 
//
//
////Will leave both here so you can see the flexibility & extensibility of my code.
//
//int main(void) {
//
//    //Since we're being asked to create a list of the keys used in map, I'm creating the Book Objects so we can sort within the list itself. (Sorting by Genre (BECAUSE I HAD LIKE 4 under the same author))
//
//
//    //Instantiated 4 Book Objects with 4 different genres. (Fortunately my favourite books span different genres)   
//
//    Book book1 = { "House of Leaves", "Mark Z. Danielewski", "Horror", 2, "https://www.goodreads.com/book/show/24800.House_of_Leaves" };   //Think you'd like this 
//    Book book2 = { "Blood Meridian", "Coramc McCarthy ", "Western/Anti-Western", 1, "https://www.goodreads.com/book/show/394535.Blood_Meridian_or_the_Evening_Redness_in_the_West" };
//    Book book3 = { "The Passanger", "Cormac McCarthy", "Fiction", 3, "https://www.goodreads.com/book/show/60581087-the-passenger" };   //Think you'd like this 
//    Book book4 = { "When Breath Becomes Air", "Paul Kalanithi", "Memoir", 4, "https://www.goodreads.com/book/show/25899336-when-breath-becomes-air" };   //Have one Value be at smaller than B
//    Book book5 = { "The Feynman Lectures on Physics", "Richard P. Feynman", "Non-Fiction", 5, "https://www.goodreads.com/book/show/5546.The_Feynman_Lectures_on_Physics" };   //Not needed in rest to sort.
//    Book book6 = { "Missing 411: The Devil's in the Details", "David Paulides", "True Crime", 6, "https://www.goodreads.com/book/show/22397234-missing-411" };
//    Book book7 = { "Dune", "Frank Herbert", "Science Fiction", 7, "https://www.goodreads.com/book/show/44767458-dune" };
//    Book book8 = { "Book of Five Rings", "Miyamoto Mushashi", "Philosophy", 8, "https://www.goodreads.com/book/show/867247.A_Book_of_Five_Rings" };
//    Book book9 = { "Art of War", "Sun Tzu", "Philosophy & Strategy", 9, "https://www.goodreads.com/book/show/10534.The_Art_of_War" };
//
//    //Criteria: A Map (at least 4 key value pairs), a binary search tree, and a Queue 
//
//    //We're using Genre as the MAP Key, and it's sorting by ASCII Values of Genres. (Ptr of the Book Class) & Dynamic Memory Allocation 
//
//    //Would be SUPER long if I input the book Info traditionally. So created objects above and using NEW + pushback to dynamically insert the books. (Also allows you change comparison)
//    map<string, list<Book*>> bookMap;  //String because that is the data type of the genres
//
//    bookMap[book1.getGenre()].push_back(new Book(book1));   //I love accessor Methods :)  Book 1  
//    bookMap[book2.getGenre()].push_back(new Book(book2));  //Book 2   
//    bookMap[book3.getGenre()].push_back(new Book(book3));  //Book 3
//    bookMap[book4.getGenre()].push_back(new Book(book4));  //Book 4  
//    bookMap[book5.getGenre()].push_back(new Book(book5));  //Book 5
//    bookMap[book6.getGenre()].push_back(new Book(book6));  //Book 6
//    bookMap[book7.getGenre()].push_back(new Book(book7));  //Book 7
//    bookMap[book8.getGenre()].push_back(new Book(book8));  //Book 8
//    bookMap[book9.getGenre()].push_back(new Book(book9));  //Book 9
//
//
//    //Using an iterator to print the key 
//
//    map<string, list<Book*>>::iterator itrMap;
//
//    //Startring the itrMap inside the for loop because of extensibility
//    //Must reset it to the beginning every single time!
//
//    cout << "Map Key-Value Pairs:" << endl;  //Putting it inside the loop is a waste of memory and inefficient.
//
//    for (auto itrMap = bookMap.begin(); itrMap != bookMap.end(); itrMap++) {  //Iterators through all of Map
//
//        cout << "\nGenre (Key): " << itrMap->first;   //First refers to the keys, where second refers to the (BOOK) Values
//        //Key generator Above (Genre) 
//
//        for (auto bookElemeti : itrMap->second) {   //Iterates through the entire thing (THIS IS DISPLAY INDIVIDUAL OBJECTS OF MAP WHICH IS THE BIGGEST BENEFIT OF MY METHOD, FLEXIBILITY) 
//
//            bookElemeti->displayBookName();  //Value (Book Name) 
//
//            //Efficient Memory Deallocation (INSIDE ELEMENT ITERATOR) 
//            delete bookElemeti;
//
//            bookElemeti = nullptr;  //As we hypothetically "shouldn't" know the size (GOOD PRACTISE) 
//        }
//    }
//    
//    //Only used two autos in entire code, to make it unvexing (not a headache) for you to sift through.
//
//    //Hard Coded Binary Search Tree (HardCode 3, then you're allowed to use Add Node Class) 
//    //SORTING BY BOOK NAME! (SO Hard Coding starts by using ASCII values)
//
//    Node* head = new Node(book1);  //Book 1 is House Of Leaves
//    Node* curr = head;
//
//
//    //Now other two books based off the ASCII values of the last (Less or Greater) 
//    curr->setLeft(new Node(book2));     //Book 2 ("Blood")  Comes After "House"   H > B So Left
//    curr->setRight(new Node(book3));    //Book 3 ("The Passanger) Comes After "House"   B < T
//
//    //Setting the new current to the getleft (NOW on Blood Meridian)
//    curr = curr->getLeft();
//
//    //Setting the current equal to head
//    curr = head;
//
//   // curr->report();  //Makes bottom sort correctly & Manually Reporting the hardcoded values. (Hardcoding the report function!)
//
//    //First 3 Above Are HardCoded, Now We Can Use our addNode Function Below.
//    //If you want to start it after book 3 (NOT GOOD IDEA NOT VERY EFFICIENT). As IT WILL BE NEARLY EXACTLY THE SAME as regular Node Structure
//
//    BinarySearchTree bookTree(curr->getValue()); //Creating a binary Search tree Object that we'll use AFTER hard coding FIRST 3
//                                                //Gets the current value of our head. (WHICH IS NOW BOOK 2 "Blood Merididan", Rank 1)) 
//                                                //This is not an accident Jefe, want to make my BST VERY EFFICIENT!  
//                                                //Once you do getRight OR getLeft you are LOCKED IN that section of the binary tree so be careful and think it through.
//
//    bookTree.setRoot(curr);
//
//    //Rest of the non-hard coded Nodes. 
//    bookTree.addNode(book4);
//    bookTree.addNode(book5);
//    bookTree.addNode(book6);
//    bookTree.addNode(book7);
//    bookTree.addNode(book8);
//    bookTree.addNode(book9);
//
//
//    //bookTree.setRoot(curr);
//
//   //Above code with BinarySearchTree takes in the value
//
//   //If I wasn't doing the BinarySearchTree bookTree(curr->getValue()) above I'd do....
//   // BinarySearchTree bookTree(book2) (Contingency
//
//
//    bookTree.print();  //Prints the tree as it is. Display Method is IN PRINT METHOD! 
//                       //Since not specificed, displayed all of the "elements" of each book, with respect to BookName Alphabetical Order.
//
//    bookTree.deleteTree();  //Memory Deallocation for Tree.
//
//
//
//    //2nd Method Mentioned Above at the Top!
//   //ORIGINALLY DID THE NON-HARD CODED PART THIS WAY, BUT REALIZED DURING THE QUEUE IT'S MUCH EASIER TO JUST INSTANTIATE THEM ALL AS OBJECTS ABOVE (PLUS MAP KEY IDENTIFICATION) 
//
//   //Book tempBook = book4;    //Once inititalized with Book object here 
//   //bookTree.addNode(tempBook);
//
//   //tempBook = { "The Feynman Lectures on Physics", "Richard P. Feynman", "Memoir & Other", 5, "https://www.goodreads.com/book/show/5546.The_Feynman_Lectures_on_Physics" };   //Not needed in rest to sort.
//   //bookTree.addNode(tempBook);
//
//   //tempBook = { "Missing 411: The Devil's in the Details", "David Paulides", "Memoir & Other", 6, "https://www.goodreads.com/book/show/22397234-missing-411" };
//   //bookTree.addNode(tempBook);
//
//   //tempBook = { "Dune", "Frank Herbert", "Memoir & Other", 7, "https://www.goodreads.com/book/show/44767458-dune" };
//   //bookTree.addNode(tempBook);
//
//   //tempBook = { "Book of Five Rings", "Miyamoto Mushashi", "Memoir & Other", 8, "https://www.goodreads.com/book/show/867247.A_Book_of_Five_Rings" };
//   //bookTree.addNode(tempBook);
//
//   //tempBook = { "Art of War", "Sun Tzu", "Memoir & Other", 9, "https://www.goodreads.com/book/show/10534.The_Art_of_War" };   //9 nodes! (Put Art Of war instead of The Art of War, to Show Left Sorting Works!) 
//   //bookTree.addNode(tempBook);
//
//
//    //Queue: Want to have the link appear within the stack (OPTIONAL BUT WANT TO SHOW OFF)
//
//    queue<Book> favouriteBooks;  //Now the rank I input comes into Fruititon! (Must put the object cannot use Ptrs)
//
//    favouriteBooks.push(book1);
//    favouriteBooks.push(book2);
//    favouriteBooks.push(book3);
//    favouriteBooks.push(book4);
//    favouriteBooks.push(book5);
//    favouriteBooks.push(book6);
//    favouriteBooks.push(book7);
//    favouriteBooks.push(book8);
//    favouriteBooks.push(book9);
//
//    while (!favouriteBooks.empty()) {
//
//        Book currentBook = favouriteBooks.front();
//
//        favouriteBooks.pop(); //Pops 
//
//        cout << "\nLink for " << currentBook.getBookName() << " is: " << currentBook.getLink() << endl;
//    }
//
//
//    cout << "\n\nEnjoy your weekend Jefe and happy reading! :)" << endl;
//
//
//    return 0;
//}
//
//
//
////*************Book Constructor Implementation**************** 
//
//Book::Book(string argB, string argN, string argG, int argR, string argW) {
//
//    setBookName(argB);    //Indirect access of first name
//    setAuthorName(argN);	   //Indirect access of last name
//    setGenre(argG);	   //Indirect access of gender
//    setRank(argR);		   //Indirect access of Rank
//    setLink(argW);      //Indirect access of webLink
//
//}
//
//
////Accessor Methods Book
//void Book::setBookName(string argB) {   //Set methods for Book name
//
//    bookName = argB;
//
//}
//void Book::setAuthorName(string argN) {  //Set methods for Author name
//
//    authorName = argN;
//
//}
//void Book::setGenre(string argG) {   //Set methods for genre
//
//    genre = argG;
//
//}
//void Book::setRank(int argR) {   //Set methods for rank
//
//    rank = argR;
//
//}
//void Book::setLink(string argW) {
//
//    webLink = argW;
//}
//string Book::getBookName(void) {   //Get methods for Book name
//
//    return bookName;
//
//}
//string Book::getAuthorName(void) {  //Get methods for Author name
//
//    return authorName;
//
//}
//string Book::getGenre(void) {  //Get methods for genre
//
//    return genre;
//
//}
//int Book::getRank(void) {  //Get methods for ranking
//
//    return rank;
//
//}
//string Book::getLink(void) {
//
//    return webLink;
//}
//
//
////Utility Implemenation
//
//void Book::displayGenre() {
//
//    cout << "The Genre is: " << getGenre() << endl;
//}
//
//void Book::displayBookName() {
//
//    //cout << "The Genre is: " << getGenre() << endl;
//
//    cout << "\nThe Book Name: " << getBookName() << endl;
//}
//
//void Book::display() {   //To get rid of large cursor press insert
////
//    //Keep only tbis as it's what's categorizing the books 
//   // cout << "The "
//
//    cout << "\nThe Book Name: " << getBookName() << endl;
//    cout << "The Author's Name is: " << getAuthorName() << endl;
//    cout << "The Genre is: " << getGenre() << endl;
//    cout << "Personal (Objective/Perfect) Ranking: " << getRank() << endl;
//    cout << "The Web Link is: " << getLink() << endl << endl;
//
//}
//
//
////*************Node Constructor Implementation**************** 
//
//
//Node::Node(Book arg) {
//
//    setLeft(nullptr);   //As the data type is a Node* (Ensuring it's empty)
//    setRight(nullptr);  //As the data type is a Node*  (Ensuring it's empty) 
//    setValue(arg);   //This is to set the value for the addNode Book "ARG" for the Binary Search Tree
//
//}
//
//
////*************Node Accessor & Utility Method Implementation**************** 
//
//void Node::setLeft(Node* arg) {
//    left = arg;
//}
//Node* Node::getLeft(void) {
//    return left;
//}
//void Node::setRight(Node* arg) {
//    right = arg;
//}
//Node* Node::getRight(void) {
//    return right;
//}
//void Node::setValue(Book arg) {  //Get and set methods for the Book value above in private Node
//    valueB = arg;
//
//}
//Book Node::getValue(void) {
//
//    return valueB;
//
//}
//
//void Node::report() { // recursive print job, may need to edit for your task
//    //getValue().display(); //This is VERY IMPORTANT (DISPLAYS THE VALUES CONTAINED IN MAIN FOR BST) 
//
//    if (left) left->report();
//   
//    getValue().display(); //This is VERY IMPORTANT (DISPLAYS THE VALUES CONTAINED IN MAIN FOR BST) 
//    // This will depend on your choice of Class and how you set stuff up.
//    if (right) right->report();
//};
//
//
//void Node::deleteHangingNode(void) {
//
//    if (this == nullptr) { // If Node is nullptr
//        return;
//    }
//    else {
//        Node* forward = this; // Goes to last node
//        Node* previous = forward; // goes to second to last node
//        while (previous != nullptr) { // Checks to see if the whole tree is deleted
//            if (forward == nullptr) { // resets both foward and previous to root after deleting a node
//                forward = this;
//                previous = forward;
//            }
//            if (forward->getLeft() == nullptr && forward->getRight() == nullptr) { // checks to see if forward is at the last node
//                //  deletes and sets the the one you deleted to nullptr to take care of dangling pointers
//                if (previous->getLeft() == forward) {
//                    delete forward;
//                    forward = nullptr;
//                    previous->setLeft(nullptr);
//                }
//                else if (previous->getRight() == forward) {
//                    delete forward;
//                    forward = nullptr;
//                    previous->setRight(nullptr);
//                }
//                else {
//                    delete forward;
//                    forward = nullptr;
//                    previous = nullptr;
//                }
//            }
//            else if (forward->getLeft() != nullptr) { // iterates both forward and previous to intended last path.
//                previous = forward;
//                forward = forward->getLeft();
//            }
//            else { // iterates both forward and previous to intended last path.
//                previous = forward;
//                forward = forward->getRight();
//            }
//        }
//    }
//}
//
//
////*************Binary Search Tree (BST) Constructor Implementation**************** 
//
//BinarySearchTree::BinarySearchTree(Book arg) {  //Initiliazes root as a new node (This will be useful later) 
//
//    root = new Node(arg);
//    root->setValue(arg);
//}
//
//
////*************Binary Search Tree (BST) Accessor & Utility Method Implementation**************** 
//
//Node* BinarySearchTree::getRoot(void) {
//    return(root);
//}
//void BinarySearchTree::setRoot(Node* arg) {
//    root = arg;
//}
//
//void BinarySearchTree::deleteTree(void) {
//    getRoot()->deleteHangingNode(); // function call to deleting all nodes below (and including) the root
//
//    root = nullptr;  //This is because of my root call in the Binary Search Tree.
//} 
//
//void BinarySearchTree::print(void) {
//    cout << "\n\nOur Binary Search Tree, in order, is:  " << endl;
//
//    //Extra check to make sure that the tree isn't EMPTY
//
//    if (root != nullptr) {  //If root is not empty
//        root->report();  //Report it
//    }
//    else {
//        cout << "Empty Tree!" << endl;
//    }
//}
//
//
////Comparator Implementation (2 methods Depending on WHAT you want to accomplish) 
//
////I can compare Ranked values (best to last) 
////bool compareRanking(Book arg1, Book arg2) {  // incoming person Arg1, and the Node to compare is arg2
////    bool answer = (arg1.getRank() < arg2.getRank());
////
////    return answer;
////
////}
//
//
////This creates a comparator that we'll be using in the addNode.
////Specifically being compared by BOOK NAME.
//bool compareBookName(Book arg1, Book arg2) {  //This is comparing the values within the Name! (ASCII) 
//
//    bool answer = (arg1.getBookName() < arg2.getBookName());
//    return answer;
//}
//
//
////Using the comparator above, we create an addNode Function.
//void BinarySearchTree::addNode(Book arg) {
//    Node* temp;
//    Node* curr;
//    if (root == nullptr) { // this deals with an empty tree
//        root = new Node(arg);
//    }
//    else { // if not empty,
//        temp = root;
//        curr = root;
//
//        // we follow the path to where it should go.
//        while (curr != nullptr) {
//            temp = curr; // when it's done, temp is the last complete Node.
//            if (compareBookName(arg, curr->getValue())) // Can EITHER USE RANK OR NAME OF BOOK TO SORT
//                //if (arg < curr->getValue())
//                curr = curr->getLeft();  // go left if incoming value is less.
//            else curr = curr->getRight();
//        } // current is the location of where the new value goes.
//
//        // finally set the Node up.
//        // temp is the last good Node, so we need to add from there.
//        if (compareBookName(arg, temp->getValue()))
//            //if (arg < temp->getValue())
//            temp->setLeft(new Node(arg));
//        else
//            temp->setRight(new Node(arg));
//    }
//}
