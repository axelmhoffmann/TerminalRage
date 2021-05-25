#include "Point.h"

Point Point::up = Point(0,-1);
Point Point::down = Point(0,1);
Point Point::left = Point(-1,0);
Point Point::right = Point(1,0);

Point::Point(){
    x = 0;
    y = 0;
}
Point::Point(int _x, int _y){
    x = _x;
    y = _y;
}

Point Point::add(Point other){
    return Point(other.x + x, other.y + y);
}

Point Point::subtract(Point other){
    return Point(x - other.x, y- other.y);
}

Point Point::multiply(int other){
    return Point(x * other, y * other);
}

bool Point::equal(Point other){
    return other.x == x && other.y == y;
}
