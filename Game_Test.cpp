#include "Game.h"
#include <iostream>
using namespace std;
#include <cassert>
#include <string>
// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// This file tests:
// - The functions of the Game class
// - The implementation of Entities into the Game class
//-----------------------------------
int main(){
    // Testing spawning two entities in
    {
        Game * game = new Game();
        assert(game->GetEntityCount() == 0);

        std::string sprite = ".['~'].";
        Entity * en1 = new Entity(Point(0,1), ".['~'].", 1);
        game->SpawnEntity(en1);

        assert(game->GetEntityCount() == 1);
        assert(game->entities[0]->GetSprite() == sprite);

        Entity * en2 = new Entity(Point(1,0), ".(._.).", 1);
        game->SpawnEntity(en2);

        assert(game->GetEntityCount() == 2);
        assert(game->entities[1]->GetPosition().equal(Point(1,0)));
    }
    // This doesn't really do much in this narrow testing context, but just ensures something doesn't crash :)
    {
        Game * game = new Game();
        Entity * en = new Entity(Point(0,1), ".{o_o}.", 1);
        game->SpawnEntity(en);

        game->UpdateEntities(1);
    }
    cout << "\x1B[32m## Test Passed!! ##\033[0m\t\t" << endl; 

}