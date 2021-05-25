#include "StaffCombos.h"
#include "Projectile.h"
#include <iostream>
#include <algorithm>
#include <ncurses.h>
#include <vector>
using namespace std;

///////////////////////
// BlazeWall methods //
///////////////////////
vector<string> rightSprites = {
    ".'*|>",
    "',^|>",
    "*.-|>"
};
vector<string> leftSprites = {
    "<|*.'",
    "<|.*-",
    "<|-*."
};
vector<string> upSprites = {
    "*.*-,',",
    "-------",
    "^^^^^^^"
};
vector<string> downSprites = {
    "vvvvvvv",
    "-------",
    ".'*.'*,"
};
void BlazeWall::Perform(Player * player){
    Game * game = player->GetGame();
    // Choose the spawn position and sprites based on player direction
    // THis is really bad but ugh
    Point pos = player->GetPosition();
    vector<string> * sprites;
    if (player->GetDirection().equal( Point::left )){
        pos = pos.add(Point(-3,1));
        sprites = &leftSprites;
    }
    else if (player->GetDirection().equal( Point::up )){
        pos = pos.add(Point(-1,-1));
        sprites = &upSprites;
    }
    else if (player->GetDirection().equal( Point::down )){
        pos = pos.add(Point(-1,3));
        sprites = &downSprites;
    }
    else {
        pos = pos.add(Point(3,1));
        sprites = &rightSprites;
    }


    int wallHeight = 3;
    // Create the projectiles of the wall
    for(int i = 0; i < wallHeight; i++){

        Projectile * proj = new Projectile(pos, (*sprites)[i], 1);
        proj->SetLifeTime(3);
        proj->SetMaxMoveTimer(0.15);
        proj->SetDamage(4);
        proj->SetDirection(player->GetDirection());
        proj->SetOwner(player);
        game->SpawnEntity(proj);

        // Move up 1 tile for the next projectile
        pos = pos.add(Point::up);

    }
}
string BlazeWall::GetDescription(){
    return "Creates a wide wave of fire. Costs 15 mana";
}

///////////////////////
// HealPulse methods //
///////////////////////
// The directions the heal pulse projectiles are shot in
vector<Point> directions = {
    Point(1,0),
    Point(-1,0),
    Point(0,1),
    Point(0,-1),
    Point(1,1),
    Point(1,-1),
    Point(-1,-1),
    Point(-1,1)
};
void HealPulse::Perform(Player * player){
    Game * game = player->GetGame();
    Point pos = player->GetPosition().add(Point::right);
    player->HealDamage(2);
    for (int i = 0; i < 8; i++)
    {
        Point dir = directions[i];
        Projectile * proj = new Projectile(pos.add(dir), "*", 1);
        proj->SetLifeTime(1);
        proj->SetMaxMoveTimer(0.4);
        if(i > 3)
            proj->SetMaxMoveTimer(0.6);
        proj->SetDamage(1);
        proj->SetDirection(dir);
        proj->SetOwner(player);
        game->SpawnEntity(proj);
    }
}
string HealPulse::GetDescription(){
    return "Conjures a burst of healing power. Costs 20 mana";
}

//////////////////////
// StaffHit methods //
//////////////////////
const std::string staffSprite = "---o*.";
void StaffHit::Perform(Player * player){
    Game * game = player->GetGame();
    // Spawn a projectile to the right of the player
    Point pos2 = player->GetPosition().add(Point::right.multiply(3));
    Projectile * proj = new Projectile(pos2, staffSprite, 1);
    // Set its values
    proj->SetLifeTime(0.5);
    proj->SetMaxMoveTimer(0.2);
    proj->SetDamage(2);
    proj->SetOwner(player);

    game->SpawnEntity(proj);
}
string StaffHit::GetDescription(){
    return "A short ranged thrust with the staff. Generates 7 mana, even without hitting the enemy";
}