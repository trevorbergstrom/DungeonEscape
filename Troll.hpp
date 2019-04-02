/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the Troll class header file.
 ** This class is a derived class of the character class. The troll represents
 ** an enemy that the player will take damage if they occupy the same space as.
 ** the troll can move about the board and iteract with blank spaces and walls.
 ******************************************************************************/

#ifndef Troll_hpp
#define Troll_hpp

#include <stdio.h>
#include "Character.hpp"

class Troll : public Character {
public:
    Troll(Space* start);
    virtual void move(Space* next);
    ~Troll() {};
};
#endif /* Troll_hpp */
