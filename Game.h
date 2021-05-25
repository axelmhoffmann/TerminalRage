#ifndef GAME
#define GAME

#include "Point.h"
#include "Entity.h"
#include "Player.h"
#include <vector>

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// Holds game state and all entities
//-----------------------------------
class Game {
public:
    Game();

    // Add an entity to the game
    void SpawnEntity(Entity* en);
    // A list of all entities that exist. Mainly used by the renderer to draw things
    std::vector<Entity*> entities;
    int GetEntityCount();
    // Calls the Update function on all entities and checks if any of them died
    void UpdateEntities(double deltaTime);

    // The player
    Player * player;
    // The opponent of the user
    Player * opponent;
    // is nullptr until someone wins
    Player * winner;

    ~Game();
private:
    int currentEntityCount;
};



#endif