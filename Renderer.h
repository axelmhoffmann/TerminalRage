#ifndef RENDERER
#define RENDERER

#include "Point.h"
#include "Game.h"
#include <ncurses.h>

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// Class that handles the rendering of the game state to the screen.
//-----------------------------------
class Renderer {
public:
    Renderer(Game * _game);

    // Prints the game state
    void PrintEntities();

    void PrintPlayers();

    char * ConvertString(string text);

    void PrintLine(int x, int y, string text);
    
    ~Renderer();
    
private:
    Game * game;
    WINDOW * win;
};



#endif