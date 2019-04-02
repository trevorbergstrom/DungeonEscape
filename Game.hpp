/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the Game class header file.
 ** The game class plays the dungeon escape maze game. This class contains the
 ** functions to play all the steps of the game.
 ******************************************************************************/

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Board.hpp"
#include "Character.hpp"
#include "Troll.hpp"
#include "Player.hpp"
#include "inputValid.hpp"

const int maxTurns = 25;

class Game {
private:
    Board* gameBoard;
    Player* me;
    vector<Troll*> trollies;
    int turnCount;
    string doorCode;
    bool playerQuit;
    
public:
    Game();
    void instructions();
    void play();
    void movePlayer();
    void moveTroll();
    void setTrollies(vector<Space*>);
    bool isGameOver();
    ~Game();
};
#endif /* Game_hpp */
