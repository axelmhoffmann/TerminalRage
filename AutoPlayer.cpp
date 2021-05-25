#include "AutoPlayer.h"
#include <cmath>
using namespace std;

AutoPlayer::AutoPlayer(Point _position, std::string _sprite, int _colour) : Player(_position, _sprite, _colour){
    moveTimer = 1;
    maxMoveTimer = 0.3;
    type = "autoplayer";
    weapon = nullptr;
    castDelay = 2;
    name = "The Enemy";
}

// Called every frame. Here we simulate keyboard input based on the game state
void AutoPlayer::Update(double deltaTime){
    
    castDelay -= deltaTime;
    state = new KeyState();
    
    Point moveDirection = Point(0,0);
    Point shootAttack = Point(0,0);
    // Choose whether we should move horizontally or vertically based on target position
    int xDiff = targetPlayer->GetPosition().x - GetPosition().x;
    int yDiff = targetPlayer->GetPosition().y - GetPosition().y;
    // Don't do some bad calculations if the players are sharing the same position
    if(xDiff == 0 && yDiff == 0){
        return;
    }
    if(abs(yDiff) < abs(xDiff)){
        // This calculation ensures moving only 1 unit up or down
        moveDirection = Point(0,yDiff / abs(yDiff));
    } 
    if(abs(xDiff) < abs(yDiff)){
        // This calculation ensures moving only 1 unit up or down
        moveDirection = Point(xDiff / abs(xDiff),0);
    }


    // If lined up with the player, use an attack
    if(yDiff == 0){
        shootAttack = Point(xDiff / abs(xDiff),0);
        // Adjust spacing with the player
        if(abs(xDiff) > 15)
            moveDirection = Point(xDiff / abs(xDiff),0);
        // If too far for melee, move closer
        if(abs(xDiff) > 10 && abs(xDiff) <= 15)
            moveDirection = Point(xDiff / abs(xDiff),0);
        // If too close, back off
        if(abs(xDiff) < 10)
            moveDirection = Point(-xDiff / abs(xDiff),0);
    }
    if(xDiff == 0){
        shootAttack = Point(0,yDiff / abs(yDiff));
    }

    state->arrowKeys = moveDirection;

    // The autoplayer moves slightly slower than others
    HandleInput(state, deltaTime / 4);
        
    // Use attack
    if(!shootAttack.equal(Point(0,0)) && castDelay <= 0){
        direction = shootAttack;
        Combo * attack;
        if(abs(xDiff) < 15)
            attack = new SwordStab();
        else
            attack = new BlazeWall();
        attack->Perform(this);
        castDelay = 3;
    }

}

void AutoPlayer::SetTarget(Player * player){
    targetPlayer = player;
}