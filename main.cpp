#include "Game.h"
#include "Renderer.h"
#include "Point.h"
#include "Input.h"
#include "Player.h"
#include "Projectile.h"
#include "Menu.h"
#include "Weapon.h"
#include "Staff.h"
#include "Sword.h"
#include "AutoPlayer.h"
#include <vector>
#include <ncurses.h>
#include <chrono>

using namespace std;
#include <iostream>
Game * game;

KeyState * UpdateKeyState(KeyState * state);
void SetUpGameConstants();

int main(){
    SetUpGameConstants();
    
    // Clear the Console
    system("clear");

    // Set up a list of weapon options
    vector<Weapon *> weapons;
    weapons.push_back(new Sword());
    weapons.push_back(new Staff());

    // Start menu
    Menu * menu = new Menu(weapons);
    menu->MenuStart();

    // Player has complete menu, take their choice and save it
    Weapon * selectedWeapon = menu->GetWeapon();

    game = new Game();
    Renderer * renderer = new Renderer(game);

    // Set up player
    Point position = Point(3,5);
    Player * player = new Player(position, "(@)   ", 2);
    selectedWeapon->SetOwner(player);
    player->SetWeapon(selectedWeapon);
    player->SetName(menu->GetName());
    Entity * en = (Entity *)player;
    game->SpawnEntity(en);
    game->player = player;

    // Set up Autoplayer
    position = Point(40, 10);
    AutoPlayer * autop = new AutoPlayer(position, "(#)", 2);
    autop->SetTarget(player);
    game->SpawnEntity(autop);
    game->opponent = autop;

    KeyState * state = new KeyState();

    double deltaTime;
    // Game Loop
    while(!state->exitKey && game->winner == nullptr){
        // Start stopwatch for deltaTime
        auto begin = std::chrono::high_resolution_clock::now();

        // Update input, then update player
        state = UpdateKeyState(state);
        player->HandleInput(state, deltaTime);
        
        // Update all entities and print to screen
        game->UpdateEntities(deltaTime);
        renderer->PrintEntities();
        renderer->PrintPlayers();

        // Calculate delta time using the stopwatch
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - begin;
        deltaTime = elapsed.count();
    }
    delete renderer;

    // If the game ended by a winner
    if(game->winner != nullptr){
        cout << endl << endl << "    " << game->winner->GetName() << " wins!!!" << endl << endl;
    }

    for (Weapon * wep : weapons)
    {
        delete wep;
    } 

    delete game;
}


void SetUpGameConstants(){
    Point::up = Point(0,-1);
    Point::down = Point(0,1);
    Point::left = Point(-1,0);
    Point::right = Point(1,0);
}

KeyState * UpdateKeyState(KeyState * state){
    state->arrowKeys = Point(0,0);
    int c = getch();
    state->zKey = false;
    if(c == KEY_UP)
        state->arrowKeys = Point::up;
    if(c == KEY_DOWN)
        state->arrowKeys = Point::down;
    if(c == KEY_LEFT)
        state->arrowKeys = Point::left;
    if(c == KEY_RIGHT){
        state->arrowKeys = Point::right;
    }
    if(c == 'z'){
        state->zKey = true;
    }
    if(c == 'e'){
        state->exitKey = true;
    }
    state->recentKey = c;
    return state;
}