#ifndef WEAPON
#define WEAPON

class Player;
#include "Point.h"
#include "Input.h"
#include "Combo.h"
#include "Projectile.h"
#include <vector>

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// Weapon is a class representing the weapon used by a player
//-----------------------------------
class Weapon {
    public: 
    Weapon();
    Weapon(Player * _owner);
    virtual void HandleInput(KeyState * state, double deltaTime) = 0;

    std::string GetName();
    void SetOwner(Player * _owner);
    virtual std::string GetUILine() = 0;

    std::string GetInfo();

    protected:
    Player * owner;

    std::string name;
    std::string description;
    // An array of all the valid input combinations
    std::vector<std::vector<int>> validCombos;
    // The associated combo that will be executed
    std::vector<Combo*> combos;

    // The current input stream from the player (eg. "zx^><z")
    std::vector<int> currentCombo;
};

#endif