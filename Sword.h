#ifndef SWORD
#define SWORD

#include "Point.h"
#include "Player.h"
#include "Input.h"
#include "Combo.h"
#include "Projectile.h"
#include "Weapon.h"
#include <vector>

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// Sword is a type of Weapon the player can choose
// - The projectiles created by the sword generate energy
// - At 10 energy, the player can perform a special attack with 'zzzx'
//-----------------------------------
class Sword : public Weapon {
public: 
    Sword(Player * _owner);
    Sword();
    void Setup();

    std::string GetUILine();


    void HandleInput(KeyState * state, double deltaTime) override;
    int GetEnergy();
    void ChangeEnergy(int deltaEnergy);

private:
    int currentEnergy;
};

#endif