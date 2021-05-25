#ifndef INPUT
#define INPUT

#include "Point.h"
#include <ncurses.h>

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// A representation of user input
//-----------------------------------
struct KeyState {
    Point arrowKeys; // Represents the arrow keys pressed, eg down -> y=-1, right -> x=1
    bool zKey;
    bool exitKey;

    char recentKey;
};
#endif