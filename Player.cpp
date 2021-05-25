using namespace std;
#include "Player.h"
#include "Projectile.h"
#include "Game.h"
#include "Weapon.h"

#include "Staff.h"

#include <iostream>
// Constructors
Player::Player(Point _position, std::string _sprite, int _colour) : Entity(_position, _sprite, _colour){
    moveTimer = 0.2;
    maxMoveTimer = 0.2;
    type = "player";
    maxHP = 20;
    HP = maxHP;
    weapon = nullptr;
}

// Variable getters and setters
void Player::SetName(std::string _name){
    name = _name;
}
void Player::SetWeapon(Weapon * _weapon){
    weapon = _weapon;
}
Weapon * Player::GetWeapon(){
    return weapon;
}
std::string Player::GetName(){
    return name;
}
int Player::GetHP(){
    return HP;
}
int Player::GetMaxHP(){
    return HP;
}
void Player::SetMaxHP(int max){
    maxHP = max;
    // If for some reason this happens during game (should only happen during setup)
    // Limit the player's HP to the max, if it was reduced
    if(HP > maxHP){
        HP = maxHP;
    }
}
// Called every frame
void Player::HandleInput(KeyState * state, double deltaTime){
    if(!state->arrowKeys.equal(Point(0,0)))
        direction = state->arrowKeys;
    // The player can move when moveTimer <= 0
    moveTimer -= deltaTime;
    if(moveTimer <= 0 && !state->arrowKeys.equal(Point(0,0))){
        // Move based on key state
        Move(state->arrowKeys);
        moveTimer = maxMoveTimer / 2;

        // If moving vertically, move slower
        if(state->arrowKeys.y != 0){
            moveTimer = maxMoveTimer;
        }
    }

    // Handle input for the weapon too
    if(weapon != nullptr)
        weapon->HandleInput(state, deltaTime);
}

void Player::Update(double deltaTime){
    // Player currently does nothing passively, but stuff could be added here in future
}

// Ensure HP doesn't go below 0 for visual reasons
// 0/10 HP makes sense, -2/10 HP looks weird 
void Player::TakeDamage(int damage){
    HP -= damage;
    if(HP < 0){
        HP = 0;
    }
}

// Ensure HP doesn't go above max
void Player::HealDamage(int heal){
    HP += heal;
    if(HP > maxHP){
        HP = maxHP;
    }
}