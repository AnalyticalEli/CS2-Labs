//THIS IS NOT PART OF NAMESPACES (GUSGUS & JEFE)
//ONLY DEMONSTRATES THIS KEYWORD.

//#include<iostream> 
//#include<cmath>
//using namespace std;
//
//struct Point {
//private:
//    int x;
//    int y;
//public:
//    Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
//    /*Point(int argX = 0, int argY = 0) {
//        x = argX;
//        y = argY;
//    }*/
//
//    Point& setX(int a) {
//        x = a;
//        return *this;
//    }
//
//    Point& setY(int b) {
//        y = b;
//        return *this;
//    }
//
//    void print() {
//        cout << "x = " << x << " y = " << y << endl;
//    }
//
//    void displayPoints(Point* arg) {
//        cout << "(" << this->x << "," << this->y << ")" << endl;
//        cout << "(" << arg->x << "," << arg->y << ")" << endl;
//        cout << "Distance between points: " << this->distanceToPoint(arg) << " units " << endl;
//    }
//
//    double distanceToPoint(Point* arg) {  //Using this here allows us to use x, as function of y. (Abstraction of Abstraction)
//        return (sqrt(pow(this->x - arg->x, 2) + pow(this->y - arg->y, 2)));
//    }
//};
//
//
//class Asteroid { //Modeling the asterois
//private:
//    int size;
//    string color;
//    Point position;
//    static int count;  // static variables are shared by ALL instances of this object
//public:
//    Asteroid(int argSize = 0, string argColor = "transparent") {
//        count++; //increment static count var
//        size = argSize;
//        color = argColor;
//    }
//    ~Asteroid() { //destructor
//        count--;
//    }
//    void print(void) { //this is a method
//        cout << "asteroid count: " << count << " size: " << size << " and color " << color << endl;
//    }
//
//    friend void printAsteroidCount(void); // NOT A MEMBER FUNCTION
//    // friend functions set up remote access without using get Commands. (WITHOUT USING GET METHODS, CAN COUNT INDIVIDUAL WITHOUT RESETTING ONCE COUNTED) 
//
//};
//
////initializng the static variable OUTSIDE the class.  This way it's accessible by all objects of the class.
//int Asteroid::count = 0;   //Must scope (::) the static. 
//
////regular c-type function
//void printAsteroidCount(void) {
//    cout << "Number of asteroids: " << Asteroid::count << endl;
//}
//
//
//int main()
//{
//    Point obj1(5, 5);
//    Point obj2 = obj1;
//
//    // Chained function calls.  All calls modify the same object 
//    // as the same object is returned by reference 
//    obj1.setX(10).setY(20);  // f(g(x)) compound functions
//
//    obj1.print();
//
//    obj2.displayPoints(&obj1);
//
//    //spawning asteroids
//    Asteroid* xPtr = new Asteroid(10, "red"); //constructor call
//    Asteroid* yPtr = new Asteroid(20, "green");
//    Asteroid* zPtr = new Asteroid(30, "blue");
//
//    //want the asteroid count independent of an object
//    printAsteroidCount();
//
//    delete xPtr; //destructor call -- NOT DELETING THE VARIABLE - you are deallocating the memory to which it points
//    delete yPtr;
//    delete zPtr;
//
//    printAsteroidCount();
//
//    xPtr = new Asteroid(5, "purple"); //constructor call
//    printAsteroidCount();
//
//    return 0;
//}
//
