/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the exit class implementation file.
 ** This derived class form the space class represents a space that is the door
 ** or exit point to the board.
 ******************************************************************************/

#include "Exit.hpp"

/********************************************************************************
 *                            Wall class Constructor                            *
 * This is the constructor for the Blank class. It sets the id to a 'e' char.   *
 ********************************************************************************/
Exit::Exit() {
    id = 'e';
}

/********************************************************************************
 *                              interact function                               *
 * This function let the character interact with the space and move them into   *
 * the next space, clearing the current space of the character's marker.        *
 ********************************************************************************/
void Exit::interact(Space* current, Character* me) {
    current->setid();
    me->setCurrent(this);
    setid(me->getid()); // move player into the space
}

