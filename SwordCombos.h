#ifndef SWORDCOMBOS
#define SWORDCOMBOS

#include "Combo.h"
#include "Player.h"
#include "Projectile.h"
#include "Point.h"
using namespace std;
#include <string>

class SwordStab : public Combo{
    void Perform (Player * player) override;
    string GetDescription() override;
};

class SwordSlash : public Combo{
    void Perform (Player * player) override;
    string GetDescription() override;
};

class SwordUltimate : public Combo{
    void Perform (Player * player) override;
    string GetDescription() override;
};

// Sword Projectiles grant energy to the owner in the OnHitPlayer function
class SwordProjectile : public Projectile{
    public:
    SwordProjectile(Point _position, std::string _sprite, int _colour, int _energy);

    // Called when the projectile hitbox interacts with the player hitbox
    void OnHitPlayer(Player * p) override;

    private:
    // The energy given to the user when hit 
    int energy;
};

// The ultimate swing creates mini beam projectiles as it slashes
class UltimateSwordProjectile : public Projectile{
    public:
    UltimateSwordProjectile(Point _position, std::string _sprite, int _colour);

    void OnMove() override;

};

#endif