#ifndef POINT
#define POINT

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// Represents a point or vector in the 2D game space
//-----------------------------------
struct Point {
    int x;
    int y;
    Point();
    Point(int _x, int _y);

    static Point up;
    static Point down;
    static Point left;
    static Point right;

    Point add(Point other);
    Point subtract(Point other);
    Point multiply(int other);
    bool equal(Point other);
};

#endif