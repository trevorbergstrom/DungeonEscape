/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the Board class header file.
 ** This class represents a board. The board is made up of lines of spaces, like
 ** rows. Each space has a pointer to another space. The board has an exit and a
 ** entry point for the player.
 ******************************************************************************/

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <fstream>
#include "Line.hpp"
#include "Troll.hpp"

class Board {
private:
    int xlen, ylen;
    Line* top;
    Line* bottom;
    Space* start;
    Space* exit;
    vector<Space*> trollLocations;
    
public:
    Board(string);
    void printBoard();
    Space* findStart();
    Space* findExit();
    void getTrolls();
    vector<Space*> getTrollies() {return trollLocations;}
    Space* getStart() {return start;}
    Space* getExit() {return exit;}
    
    ~Board();
    
    
};
#endif /* Board_hpp */
