#include "Menu.h"
using namespace std;

// Generated using https://www.coolgenerator.com/ascii-text-generator
const vector<string> logo =  {
               " ___  ___  ___  __ __  _  _ _  ___  _     ___  ___  ___   ___ ",
               "|_ _|| __>| . \\|  \\  \\| || \\ || . || |   | . \\| . |/  _> | __>",
               " | | | _> |   /|     || ||   ||   || |_  |   /|   || <_/\\| _>",
               " |_| |___>|_\\_\\|_|_|_||_||_\\_||_|_||___| |_\\_\\|_|_|`____/|___>"};

// Control info tips
const string controlTips = " CONTROLS:\n  - Use the arrow keys to move around\n  - Use combinations of 'z' and 'x' keys to attack";

Menu::Menu(vector<Weapon *> weapons){
    this->weapons = weapons;
}

void Menu::MenuStart(){
    // Add some spacing
    cout << endl << endl;
    // Print the title
    PrintLogo();
    // Get user name input
    name = InputName();
    // Get the user's chosen weapon
    weapon = InputWeapon();
    // Print control info
    PrintControls();
    // Check the player is ready
    CheckReady();
}

string Menu::InputName(){
    while(1){
        // Get Name Input
        cout << endl << " Input name:  ";
        string input;
        cin >> input;

        bool valid = true;
        // Check if input is alphanumeric
        if(!IsAlphanumeric(input)){
            valid = false;
            cout << "  Invalid input. Ensure name is alphanumeric" << endl;
        }
        // Check input is small enough
        if(input.size() > 10){
            valid = false;
            cout << "  Invalid input. Ensure name is less than 10 characters" << endl;
        }

        // Check input is small enough
        if(input.size() < 2){
            valid = false;
            cout << "  Invalid input. Ensure name is at least 2 characters" << endl;
        }
        
        if(valid){
            return input;
        }
    }
}

void Menu::PrintControls(){
    cout << endl << endl;
    // Print controlTips
    cout << controlTips << endl;

    // Print the name of the weapon selected
    cout << endl << "        [ " << weapon->GetName() << " Info ]" << endl;
    // Print the dynamically generated info of the weapon
    cout << weapon->GetInfo() << endl;
}

Weapon * Menu::InputWeapon(){
    cout << endl;
    // Print all weapons and their corresponding numbers
    for(int i = 0; i < weapons.size(); i++){
        cout << " " << i + 1 << " : " << weapons[i]->GetName() << endl;
    }

    while(1){
        cout << endl << " Input weapon number (1 - " << weapons.size() << "):  ";
        // Get user selection
        string rawInput;
        int input = 0;
        cin >> rawInput;
        bool valid = true;

        // Check that every character in the input is a digit
        for (int i = 0; i < rawInput.size(); i++)
        {
            if(!isdigit(rawInput[i])){
                valid = false;
            }
        }
        if(!valid){
            cout << "  Input must be an integer. Try again" << endl;
            continue;
        }

        input = stoi(rawInput);

        // Make sure the selection is within the possible range
        if(input < 1){
            cout << "  Input must be > 0. Try again" << endl;
            continue;
        }
        if(input > weapons.size()){
            cout << "  Input must be < " << weapons.size() << ". Try again" << endl;
            continue;
        }

        // Success
        cout << " SELECTED " << weapons[input - 1]->GetName() <<endl;
        return weapons[input - 1];
        

    }
}

void Menu::CheckReady(){
    while(1){
        // Keep trying until user inputs R
        char input;
        cout << endl << endl << " Ready? Enter 'r' to start:  ";
        cin >> input;
        if(input == 'r' || input == 'R'){
            cout << endl << endl << "___________________________________________________" << endl;
            return;
        }
    }
}

string Menu::GetName(){
    return name;
}
Weapon * Menu::GetWeapon(){
    return weapon;
}

bool Menu::IsAlphanumeric(string input){
    // Loop through all characters and test using isalnum()
    for(int i = 0; i < input.size(); i++){
        if(!isalnum(input[i]))
            return false;
    }
    return true;
}

void Menu::PrintLogo(){
    for(int i = 0; i < logo.size(); i++)
        cout << logo[i] << endl;
}   
                                                                     