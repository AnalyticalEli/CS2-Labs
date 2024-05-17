//Our Resource gusgus cpp file that's pulling from the gusgus header (h) file

#include "gusgus.h"

double gus::angleMaker(Point argA, Point argB, Point argC) {
    // let's say we'll find angle C, Angle ACB
    // C = acos( a^2 + b^2 - c^2 )(2*a*b)
    double c = argA.distanceToPoint(&argB);  // length from a to b
    double a = argB.distanceToPoint(&argC);  // length from b to c
    double b = argC.distanceToPoint(&argA);  // length from a to c
    return acos((a * a + b * b - c * c) / (2 * a * b)); // angle of C
}