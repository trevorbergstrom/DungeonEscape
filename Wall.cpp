/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Wall class implementation file.
 ** This derived class form the space class represents a space that blocks 
 ** movement.
 ******************************************************************************/

#include "Wall.hpp"

/********************************************************************************
 *                            Wall class Constructor                            *
 * This is the constructor for the Blank class. It sets the id to a '*' char.   *
 ********************************************************************************/
Wall::Wall() {
    id = '*';
}

/********************************************************************************
 *                              interact function                               *
 * This function will not let the character move into this space. It will dispay*
 * a error message to the player.                                               *
 ********************************************************************************/
void Wall::interact(Space* current, Character* c) {
    c->setCurrent(current); // set current space as previous current
    if(!c->getAI()) { // if is a player
        cout << "The way is blocked!" << endl;
    }
}
