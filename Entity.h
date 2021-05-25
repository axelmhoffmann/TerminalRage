#ifndef ENTITY
#define ENTITY

#include "Point.h"
#include "Input.h"
// Resolve circular dependency
class Game;
#include <string>

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// An object existing on the game board. eg. Projectiles or Players.
//-----------------------------------
class Entity {

public:
    // Constructors
    Entity(Point _position);
    Entity(Point _position, std::string _sprite, int colour);

    // Getter Functions
    Point GetPosition();
    int GetColour();
    char* GetSprite();
    Point GetDirection();
    void SetDirection(Point dir);
    std::string GetType();
    int GetSize();

    // Used to gain a reference to the Game object - required for spawning projectiles
    void SetGame(Game * _game);
    Game * GetGame();

    // Runs every game loop
    virtual void Update(double deltaTime);
    // Adds the movement vector to entity position. returns false if unable to
    bool Move(Point movementVector);

    virtual ~Entity();

protected:
    std::string type; // A string set by subclasses - used to identify entity type
    Game * game;
    Point direction; // A unit vector describing the direction the entity is pointing in

private:
    Point position;
    std::string sprite; // The visual representation of the entity
    int colour;


};


#endif