/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the Board class header file.
 ** This class represents a character. It is an abstract class. The character
 ** can move about the board and will inteact with the different types of spaces.
 ** derived classes are the player and troll. 
 ******************************************************************************/

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include "Space.hpp"

class Space;

class Character {
protected:
    Space* current;
    char id;
    bool isAI;
    
public:
    void setCurrent(Space* s) {current = s;}
    Space* getCurrent() {return current;}
    char getid() {return id;}
    bool getAI() {return isAI;}
    virtual void move(Space* next) = 0;
    virtual ~Character(){};
    
};

#endif /* Character_hpp */
