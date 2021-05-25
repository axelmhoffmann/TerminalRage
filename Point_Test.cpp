#include "Point.h"
using namespace std;
#include <iostream>
#include <cassert>
// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// Unit Tests: Point class
//-----------------------------------
int main(){
    
    // Testing Point.add()
    {
        Point* a = new Point(2,1);
        Point* b = new Point(3,3);
        Point c = a->add(*b);
        assert(c.x == 5 && c.y == 4);
    }
    {
        Point* a = new Point(2,1);
        Point* b = new Point(-3,-3);
        Point c = a->add(*b);
        assert(c.x == -1 && c.y == -2);
    }
    // Testing Point.subtract()
    {
        Point* a = new Point(2,1);
        Point* b = new Point(3,3);
        Point c = a->subtract(*b);
        assert(c.x == -1 && c.y == -2);
    }
    {
        Point* a = new Point(5,5);
        Point* b = new Point(4,2);
        Point c = a->subtract(*b);
        assert(c.x == 1 && c.y == 3);
    }
    // Testing Point.multiply()
    {
        Point* a = new Point(2,3);
        Point c = a->multiply(2);
        assert(c.x == 4 && c.y == 6);
    }
    // Testing equality and inequality
    {
        Point* a = new Point(2,1);
        Point* b = new Point(2,1);
        bool c = a->equal(*b);
        assert(c);
    }
    {
        Point* a = new Point(2,1);
        Point* b = new Point(3,3);
        bool c = a->equal(*b);
        assert(!c);
    }
    cout << "\x1B[32m## Test Passed!! ##\033[0m\t\t" << endl; 
}