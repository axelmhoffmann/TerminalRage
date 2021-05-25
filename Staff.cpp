#include "Staff.h"
#include "StaffCombos.h"
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
#include <ncurses.h>
#include <iostream>

Staff::Staff(Player * _owner) : Weapon(_owner){
    Setup();
}
Staff::Staff(){
    Setup();
}
void Staff::Setup(){
    name = "Magic Staff";
    currentMana = 20;
    maxMana = 20;
    description = "  Cast long range, powerful spells using mana.\n  Generate mana by using melee range attacks";

    // Set up valid combos and their data.
    validCombos.push_back({'z','z','z'});
    combos.push_back(new BlazeWall());
    manaCosts.push_back(-15);

    validCombos.push_back({'x','z','x'});
    combos.push_back(new HealPulse());
    manaCosts.push_back(-20);

    validCombos.push_back({'x','x'});
    combos.push_back(new StaffHit());
    manaCosts.push_back(7);
}

void Staff::HandleInput(KeyState * state, double deltaTime) {
    // Only interpret the key if a key was pressed (ERR means no key pressed)
    int ch = state->recentKey;
    if(ch != ERR){
        currentCombo.push_back(state->recentKey);
    }
    else{
        return;
    }

    int comboIndex = 0;
    for(int i = 0; i < validCombos.size(); i++){
        // See if current combos contains a combo in it
        auto match = search(currentCombo.begin(), currentCombo.end(), validCombos[i].begin(), validCombos[i].end());
        // If it does ....
        if(match != currentCombo.end()){
            comboIndex = i;
            // If you have more mana than the cost of the combo, perform the combo
            if(currentMana >= -manaCosts[comboIndex]){
                combos[comboIndex]->Perform(owner);

                // Don't go over the maximum mana if restoring mana
                if(manaCosts[comboIndex] + currentMana > maxMana)
                    currentMana = maxMana;
                else
                    ChangeMana(manaCosts[comboIndex]);
            }
            currentCombo.clear();
        }
    }
}

std::string Staff::GetUILine(){
    return "mana: "+ to_string(currentMana) + " / " + to_string(maxMana);
}

void Staff::ChangeMana(int deltaMana){
    currentMana += deltaMana;
    // This case should never happen due to the mana requirement check in HandleInput
    // But assure you cannot have negative mana anyway
    if(currentMana < 0)
        currentMana = 0;
}
int Staff::GetMana() {
    return currentMana;
}