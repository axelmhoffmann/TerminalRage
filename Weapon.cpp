#include "Weapon.h"
#include <string>
#include <algorithm>
using namespace std;

Weapon::Weapon(){
    
}

Weapon::Weapon(Player * _owner){
    owner = _owner;
}

void Weapon::SetOwner(Player * _owner){
    owner = _owner;
}
string Weapon::GetName(){
    return name;
}
string Weapon::GetInfo(){
    string output = description;
    
    // For each combo, output the key combination and then its description
    for(int i = 0; i < combos.size(); i++){
        // Probably convoluted? Copies a char vector into a string
        char * comboInputs = new char[validCombos[i].size()];
        copy(validCombos[i].begin(), validCombos[i].end(), comboInputs);
        string comboString = comboInputs;

        output += "\n '" + comboString + "' - " + combos[i]->GetDescription();
    }
    
    return output;
}