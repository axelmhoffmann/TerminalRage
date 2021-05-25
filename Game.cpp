#include "Point.h"
#include "Game.h"
#include "Entity.h"
#include "Projectile.h"
#include <ncurses.h>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

Game::Game(){
    currentEntityCount = 0;
    winner = nullptr;
}

// Adds an entity to the entities vector
void Game::SpawnEntity(Entity* en){
    entities.push_back(en);
    en->SetGame(this);
    currentEntityCount++;
}

// Update all entities
void Game::UpdateEntities(double deltaTime){
    // Loop through all entities
    for(int i = 0; i < entities.size(); i++){
        Entity * en = entities[i];    

        // Update the entity
        en->Update(deltaTime);

        // If it's a projectile, check lifetime
        if(en->GetType() == "projectile"){
            Projectile * proj = (Projectile *)en;
            // If it is past its lifetime, kill it
            if(proj->GetLifeTime() <= 0){
                entities.erase(entities.begin() + i);

                delete en;
            }
        }

        // If its a player, check HP
        if(en->GetType() == "player"){
            Player * p = (Player *)en;
            // If it is past its lifetime, kill it
            if(p->GetHP() == 0){
                winner = opponent;
            }
        }
        // If its the enemy, check HP
        if(en->GetType() == "autoplayer"){
            Player * p = (Player *)en;
            // If it is past its lifetime, kill it
            if(p->GetHP() == 0){
                winner = player;
            }
        }
    }
}

int Game::GetEntityCount(){
    return currentEntityCount;
}

Game::~Game(){
    for (Entity* en : entities)
    {
        delete en;
    } 
}