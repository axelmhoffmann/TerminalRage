#include <iostream>
#include <string>
#include "Point.h"
using namespace std;
#include "Entity.h"
#include "Player.h"
#include "Renderer.h"
#include <ncurses.h>
#include <algorithm>

int timer = 0;


// Set up NCURSES things
Renderer::Renderer(Game * _game){
    /*
    init_color(8, 1000, 400, 100);
    init_color(10, 0, 100, 100);
    init_color(11, 100, 100, 0);

    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    */

    game = _game;

    initscr();
    start_color();
    cbreak();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    win = newwin(20,60,1,1);
    nodelay(stdscr,true);

    curs_set(0);
    refresh();
    box(win,0,0);
}

void Renderer::PrintEntities(){
    // Clear screen
    werase(win);
    box(win,0,0);
    // Print each entity to screen
    for (Entity * en : game->entities){
        //attron(COLOR_PAIR(en->GetColour()));

        char * sprite = en->GetSprite();
        int newSize = en->GetSize();
        bool chopped = false;
        // If entity is close to the edge, cut off the edge so we dont get weird text wrapping
        if(en->GetPosition().x + en->GetSize() >= 60)
        {
            newSize -= en->GetPosition().x + en->GetSize() - 59;
            if(newSize <= 0){
                continue;
            }
            sprite = new char[newSize];
            copy_n(en->GetSprite(), newSize, sprite);
            chopped = true;

        }
        mvwprintw(win,en->GetPosition().y,en->GetPosition().x, sprite);
        //attroff(COLOR_PAIR(en->GetColour()));

        if(chopped)
            delete[] sprite;
    }
    // Refresh screen
    wrefresh(win);
  

    mvaddstr(24,2,"Press 'e' to exit at any time");
}

void Renderer::PrintPlayers(){

    
    char * output;
    string line;
    // Player name
    line = game->player->GetName()+ ": ";
    PrintLine(3,65, line);
    // Player HP
    line = "HP: "+ to_string(game->player->GetHP()) + " / 20";
    PrintLine(4,65, line);
    // Player weapon resource line (energy, mana)
    if(game->player->GetWeapon() != nullptr)
        PrintLine(5, 65, game->player->GetWeapon()->GetUILine());

    // Enemy HP
    mvaddstr(7,65,"                         ");
    line = "Enemy HP: "+ to_string(game->opponent->GetHP()) + " / 20";
    PrintLine(7, 65, line);
}

Renderer::~Renderer(){
    endwin();
}
void Renderer::PrintLine(int x, int y, string text){
    mvaddstr(x, y, "                 ");
    char * output = ConvertString(text);
    mvaddstr(x, y, output);
    delete output;
}
char * Renderer::ConvertString(string text){
    char * output = new char[text.size()];
    copy(text.begin(), text.end(), output);

    return output;
}