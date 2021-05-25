#include "Player.h"
using namespace std;
#include <iostream>
#include <string>
#include <cassert>
// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// Unit Tests: Player class
// - Testing getter and setter functions
// - Testing simulated input
// - Boundary testing the HP functions
//-----------------------------------
int main(){
    // Testing Getter & Setter functions
    {
        Player * p = new Player(Point(0,1), "[o.o]", 0);

        p->SetName("Jeff");
        assert(p->GetName() == "Jeff");
        // Use nullptr here as no weapon is involved in this test
        p->SetWeapon(nullptr);
        assert(p->GetWeapon() == nullptr);
        // Default HP set in the constructor
        assert(p->GetHP() == 20);
        // Change max n see what happens
        p->SetMaxHP(15);
        assert(p->GetMaxHP() == 15);
        assert(p->GetHP() == 15);
    }
    // Boundary Testing: TakeDamage() and HealDamage()
    {
        Player * p = new Player(Point(2,0), ":-(", 0);
        p->SetMaxHP(10);
        
        // Assert you cannot go over max HP
        p->HealDamage(200);
        assert(p->GetHP() == 10);
        // Take small damage
        p->TakeDamage(2);
        assert(p->GetHP() == 8);
        // Heal small damage
        p->HealDamage(1);
        assert(p->GetHP() == 9);
        // Ensure HP cannot go below 0
        p->TakeDamage(100);
        assert(p->GetHP() == 0);
    }
    // Testing HandleInput
    {
        Player * p = new Player(Point(2,1), "(-.-)Zzz...", 0);
        // Simulate holding down arrow
        KeyState * state = new KeyState();
        state->arrowKeys = Point::down;
        // Use large deltaTime as there is no time passing in test scenario
        p->HandleInput(state, 10);
        // Assert the player moved as a result
        assert(p->GetPosition().equal(Point(2,2)));
    }
    // Testing HandleInput
    {
        Player * p = new Player(Point(2,1), "(-.-)Zzzz;;,,.", 0);
        // Simulate holding right arrow
        KeyState * state = new KeyState();
        state->arrowKeys = Point::right;
        // Use large deltaTime as there is no time passing in test scenario
        p->HandleInput(state, 10);
        // Assert the player moved as a result
        assert(p->GetPosition().equal(Point(3,1)));
    }
    cout << "\x1B[32m## Test Passed!! ##\033[0m\t\t" << endl; 
}
    