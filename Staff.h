#ifndef STAFF
#define STAFF

#include "Point.h"
#include "Player.h"
#include "Input.h"
#include "Combo.h"
#include "Projectile.h"
#include "Weapon.h"
#include <vector>

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// Staff is a type of Weapon the player can choose
// - It has a resource (mana) that is expended by using combos
// - Certain attacks replenish mana
//-----------------------------------
class Staff : public Weapon {
public: 
    Staff(Player * _owner);
    Staff();
    void Setup();

    void HandleInput(KeyState * state, double deltaTime) override;

    std::string GetUILine();


    // Used to interact with private mana variable
    int GetMana();
    void ChangeMana(int deltaMana);

private:
    int currentMana;
    int maxMana;
    std::vector<int> manaCosts;
};

#endif