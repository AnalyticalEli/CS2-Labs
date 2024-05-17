#pragma once

//Each cpp file in resource files needs a corresponding header file
//in Header Files OF THE SAME NAME (gusgus Here) 

#include<iostream> 
#include<cmath>
using namespace std;

namespace gus {
    struct Point {
    private:
        int x;
        int y;
    public:
        Point(int x = 0, int y = 0) { this->x = x; this->y = y; } // this is not the helpful one.
        /*Point(int argX = 0, int argY = 0) {
            x = argX;
            y = argY;
        }*/

        Point& setX(int a) {
            x = a;
            return *this;
        }

        Point& setY(int b) {
            y = b;
            return *this;
        }

        void print() {
            cout << "x = " << x << " y = " << y << endl;
        }

        void displayPoints(Point* arg) {
            cout << "(" << this->x << "," << this->y << ")" << endl;
            cout << "(" << arg->x << "," << arg->y << ")" << endl;
            cout << "Distance between points: " << this->distanceToPoint(arg) << " units " << endl;
        }

        double distanceToPoint(Point* arg) {
            return (sqrt(pow(this->x - arg->x, 2) + pow(this->y - arg->y, 2)));
        }
    };
    double angleMaker(Point argA, Point argB, Point argC);
    // function A;
};