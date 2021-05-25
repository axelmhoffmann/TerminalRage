#ifndef COMBO
#define COMBO

class Player;
#include "Point.h"
#include <string>
#include "Input.h"
using namespace std;

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// A special move usable by a weapon
//-----------------------------------
class Combo {
    public: 
    virtual void Perform(Player * player) = 0;
    virtual string GetDescription() = 0;
};

#endif