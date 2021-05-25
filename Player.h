#ifndef PLAYER
#define PLAYER

#include "Point.h"
#include "Entity.h"
#include "Weapon.h"
#include "Combo.h"
#include "Input.h"
#include <string>


// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// A type of entity controlled by the user
//-----------------------------------
class Player : public Entity {

public:
    Player(Point _position, std::string _sprite, int _colour);

    // State interaction
    void SetName(std::string name);
    std::string GetName();
    int GetHP();
    int GetMaxHP();
    void SetMaxHP(int max);
    Weapon * GetWeapon();
    void SetWeapon(Weapon * _weapon);

    // Called each game loop
    void HandleInput(KeyState * state, double deltaTime);
    virtual void Update(double deltaTime);

    // Changing player HP
    void TakeDamage(int damage);
    void HealDamage(int heal);

protected:
    int maxHP;
    int HP;
    std::string name;
    double moveTimer;
    double maxMoveTimer;
    Weapon * weapon;
    // A reference to the keyboard input
    KeyState * state;

};

#endif