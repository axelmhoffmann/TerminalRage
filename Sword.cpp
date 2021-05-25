#include "Sword.h"
#include "SwordCombos.h"
using namespace std;
#include <algorithm>
#include <string>
#include <vector>
#include <ncurses.h>
#include <iostream>

Sword::Sword(Player * _owner) : Weapon(_owner){
    Setup();
}
Sword::Sword(){
    Setup();
}
void Sword::Setup(){
    name = "Sword";
    description = "  A medium range weapon with slow attacks. Landing attacks generate energy.\n  At 10 energy, you can use the Special combo";
    currentEnergy = 0;

    // Set up valid combos and their data.
    validCombos.push_back({'z','x'});
    combos.push_back(new SwordStab());

    validCombos.push_back({'z','z'});
    combos.push_back(new SwordSlash());

    validCombos.push_back({'x','x','x'});
    combos.push_back(new SwordUltimate());
}


void Sword::HandleInput(KeyState * state, double deltaTime) {
    // A reference for the Ultimate combo
    vector<int> ultimateReference = {'x','x','x'};

    // Only interpret the key if a key is pressed this frame
    int ch = state->recentKey;
    if(ch != ERR){
        currentCombo.push_back(state->recentKey);
    }


    int comboIndex = 0;
    for(int i = 0; i < validCombos.size(); i++){
        // See if current combos contains a combo in it
        auto match = search(currentCombo.begin(), currentCombo.end(), validCombos[i].begin(), validCombos[i].end());
        // If it does ....
        if(match != currentCombo.end()){
            comboIndex = i;

            // Special case for Ultimate combo
            if(validCombos[comboIndex] == ultimateReference){
                if(currentEnergy >= 10){
                    currentEnergy = 0;
                    combos[comboIndex]->Perform(owner);
                }
            } else {
            // Perform the combo
            combos[comboIndex]->Perform(owner);
            }
            currentCombo.clear();
        }
    }
}
int Sword::GetEnergy() {
    return currentEnergy;
}


std::string Sword::GetUILine(){
    return "energy: "+ to_string(currentEnergy) + " / 10";
}

void Sword::ChangeEnergy(int deltaEnergy){
    currentEnergy += deltaEnergy;
    if (currentEnergy > 10){
        currentEnergy = 10;
    }
}