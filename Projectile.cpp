#include "Projectile.h"
#include <iostream>
#include "Game.h"
#include <string>

#include <algorithm>
#include <ncurses.h>

// Constructor
Projectile::Projectile(Point _position, std::string _sprite, int _colour) : Entity(_position, _sprite, _colour){
    size = _sprite.size();
    Setup();
}

void Projectile::Setup(){
    type = "projectile";
    lifeTime = 10;
    direction = Point(1,0);

    // Special value used for initialisation during first projectile update
    moveTimer = -1;
    damage = 1;
}
// Used for bonus effects when hitting something. Overridden in subclasses
void Projectile::OnHitPlayer(Player * p){
    
}
void Projectile::Update(double deltaTime) {
    // Used for initialisation, when a combo sets the move timer of a projectile using SetMaxMoveTimer
    if(moveTimer == -1){
        moveTimer = maxMoveTimer;
        // Call OnMove when the projectile first spawns too
        OnMove();
    }

    lifeTime -= deltaTime;
    moveTimer -= deltaTime;

    if(moveTimer <= 0){
        Move(direction);
        moveTimer = maxMoveTimer;
        OnMove();
    }

    CheckCollisions();
}

void Projectile::CheckCollisions(){
    // The projectile is owned by one of the fighters.
    // other is the opposite fighter
    Player * other;

    if(owner->GetType() == "player"){
        other = GetGame()->opponent;
    }

    if(owner->GetType() == "autoplayer"){
        other = GetGame()->player;
    }

    // All projectiles are horizontal, so if the y positions aren't equal, no collision can happen
    if (other->GetPosition().y != this->GetPosition().y){
        return;
    }

    // If the position of the right entity is <= than the right bound of the left object, there is a collision
    if(this->GetPosition().x < other->GetPosition().x && this->GetPosition().x + this->GetSize() >= other->GetPosition().x){
        OnHitPlayer(other);
        other->TakeDamage(damage);
        // Projectiles can only hurt once
        damage = 0;
    }
}

void Projectile::OnMove(){

}

void Projectile::SetMaxMoveTimer(double max){
    maxMoveTimer = max;
}
void Projectile::SetDamage(int dmg){
    damage = dmg;
}
void Projectile::SetLifeTime(double _time){
    lifeTime = _time;
}
double Projectile::GetLifeTime(){
    return lifeTime;
}

Player * Projectile::GetOwner(){
    return owner;
}

void Projectile::SetOwner(Player * _owner){
    owner = _owner;
}

Projectile::~Projectile() {

}