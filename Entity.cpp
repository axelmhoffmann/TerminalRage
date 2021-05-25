#include "Entity.h"
#include "Game.h"
#include <string>
#include <algorithm>

using namespace std;

// Constructors
Entity::Entity(Point _position){
    position = _position;
    type = "entity";
}
Entity::Entity(Point _position, string _sprite, int _colour){
    position = _position;
    sprite = _sprite;
    colour = _colour;
    type = "entity";
}

void Entity::SetGame(Game * _game){
    game = _game;
}

// Called every frame, overridden by subclasses
void Entity::Update(double deltaTime){
    
}

// Moves the entity by the movementvector input
bool Entity::Move(Point movementVector){
    position = position.add(movementVector);
    return true;
}

Entity::~Entity(){
    
}

// Getter functions
Game * Entity::GetGame(){
    return game;
}
Point Entity::GetPosition(){
    return position;
}

int Entity::GetColour(){
    return colour;
}
char* Entity::GetSprite(){
    char * output = new char[sprite.size()];
    copy(sprite.begin(), sprite.end(), output);
    return output;
}
std::string Entity::GetType(){
    return type;
}
Point Entity::GetDirection(){
    return direction;
}
void Entity::SetDirection(Point dir){
    direction = dir;
}
// The size of the entity is determined by its sprite length
int Entity::GetSize(){
    return sprite.size();
}