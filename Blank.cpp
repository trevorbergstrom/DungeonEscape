/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Blank class implementation file.
 ** This derived class form the space class represents a blank space that
 ** can be stepped into.
 ******************************************************************************/

#include "Blank.hpp"

/********************************************************************************
 *                           Blank class Constructor                            *
 * This is the constructor for the Blank class. It sets the id to a space char. *
 ********************************************************************************/
Blank::Blank() {
    id = ' ';
}

/********************************************************************************
 *                              interact function                               *
 * This function let the character interact with the space and move them into   *
 * the next space, clearing the current space of the character's marker.        *
 ********************************************************************************/
void Blank::interact(Space* current, Character* t) {
    current->setid();
    t->setCurrent(this);
    this->setid(t->getid());
}

