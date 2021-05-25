#include "Menu.h"
#include "Weapon.h"
#include "Staff.h"
#include "Sword.h"
#include <vector>
#include <iostream>
using namespace std;
#include <cassert>

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// IO testing: Menu class
//-----------------------------------
int main(){
    // Add the list of weapons - used by the menu class to dynamically generate info and choices
    vector<Weapon *> weapons;
    weapons.push_back(new Sword());
    weapons.push_back(new Staff());
    Menu * menu = new Menu(weapons);
    // Start the menu
    menu->MenuStart();
    // Once the menu has been simulated, check that the input worked
    Weapon * selectedWeapon = menu->GetWeapon();
    assert(selectedWeapon->GetName() == "Sword");
    assert(menu->GetName() == "Player123");
}