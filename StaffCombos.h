#ifndef STAFFCOMBOS
#define STAFFCOMBOS

#include "Combo.h"
#include "Player.h"
#include "Point.h"

class BlazeWall : public Combo{
    void Perform (Player * player) override;
    string GetDescription() override;
};

class HealPulse : public Combo{
    void Perform (Player * player) override;
    string GetDescription() override;
};

class StaffHit : public Combo{
    void Perform (Player * player) override;
    string GetDescription() override;
};

#endif