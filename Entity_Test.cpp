#include "Point.h"
#include "Entity.h"
using namespace std;
#include <iostream>
#include <cassert>
#include <string>

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// Unit Tests: Entity class
//-----------------------------------
int main(){
    // Testing getter functions
    {
        std::string sprite = "(-[loltest]-)";
        Entity * en = new Entity(Point(1,1), sprite, 1);

        assert(en->GetPosition().equal(Point(1,1)));
        assert(en->GetSprite() == sprite);
        assert(en->GetType() == "entity");
        assert(en->GetColour() == 1);
    }
    // Testing Entity.Move()
    {
        Entity * en = new Entity(Point(0,1));
        Point deltaPos = Point(3,2);
        assert(en->GetPosition().equal(Point(0,1)));
        en->Move(deltaPos);
        assert(en->GetPosition().equal(Point(3,3)));
    }
    cout << "\x1B[32m## Test Passed!! ##\033[0m\t\t" << endl; 
}