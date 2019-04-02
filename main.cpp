/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the implementation file for the dungeon 
 ** escape game.
 ******************************************************************************/

#include <iostream>
#include "Game.hpp"
#include "Menu.hpp"

void playGame() {
	Game* g = new Game; // create new game
    printf("here\n");
    g->play(); // play game
    delete g;
}

int main() {
    vector<string> prompts = {"View Instructions", "Start Game", "Exit Program"}; // create prompts for menu
    Menu m(prompts, "Dungeon Esacpe!"); // create menu
    
    bool flag = false;
    while(!flag) { // display menu until user wants to quit
    	
        switch (m.displayIntChoices()) {
            case 1:
                m.displayInstructions(); // display instructions
                break;
            case 2:
            	playGame();
                break;
            case 3:
                cout << "Bye Bye!" << endl; // quit game
                flag = true;
                break;
        }
    }
}
