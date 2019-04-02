/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Trap class implementation file.
 ** This derived class form the space class represents a space that if the 
 ** player steps into they will take damage.
 ******************************************************************************/

#include "Trap.hpp"

/********************************************************************************
 *                            Trap class Constructor                            *
 * This is the constructor for the Blank class. It sets the id to a '$' char.   *
 ********************************************************************************/
Trap::Trap() {
    id = '$';
}

/********************************************************************************
 *                              interact function                               *
 * This function let the character interact with the space and move into it. If *
 * the character is a player it will take damage.                               *
 ********************************************************************************/
void Trap::interact(Space* current, Character* me) {
    current->setid();
    me->setCurrent(this); // move character
    if(me->getAI() == false) {
        Player *p = dynamic_cast<Player*>(me); // cast for player functions
        p->takeDam(10); // player takes damage
        cout << "You stepped on a booby trap! you took damage! \nYour new strength is: " << p->getStrength() << endl;
    }
    
    setid(me->getid());
}

