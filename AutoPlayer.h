#ifndef AUTOPLAYER
#define AUTOPLAYER

#include "Point.h"
#include "Game.h"
#include "Player.h"
#include "Entity.h"
#include "Weapon.h"
#include "Combo.h"
#include "StaffCombos.h"
#include "SwordCombos.h"
#include "Input.h"
#include <string>


// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// The enemy player. Controlled by a basic AI that simulates keyboard input
//-----------------------------------
class AutoPlayer : public Player {

public:
    AutoPlayer(Point _position, std::string _sprite, int _colour);

    // Called each game loop
    void Update(double deltaTime) override;

    // Used to get a reference of the User's player
    void SetTarget(Player * player);
private:
    Player * targetPlayer;
    double castDelay;
};

#endif