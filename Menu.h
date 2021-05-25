#ifndef MENU
#define MENU

#include "Point.h"
#include "Entity.h"
#include "Weapon.h"
#include <cctype>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// Created on program start
// Handles name input, etc using stdio
//-----------------------------------
class Menu{
public:
    Menu(vector<Weapon *> weapons);
    void MenuStart();

    // Used for printing info to the console
    void PrintLogo();
    void PrintControls();

    // Get user input
    string InputName();
    Weapon * InputWeapon();
    void CheckReady();

    // Getters used for taking input from this class and bringing it into the Game state
    Weapon * GetWeapon();
    string GetName();


private:
    bool IsAlphanumeric(string input);
    string name;
    Weapon * weapon;
    vector<Weapon *> weapons;
};


#endif