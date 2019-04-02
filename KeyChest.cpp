/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the KeyChest class implementation file.
 ** This derived class form the space class represents a space has a chest
 ** containing an inventory of items. This chest contains the key for the door.
 ******************************************************************************/

#include "KeyChest.hpp"

/********************************************************************************
 *                          KeyChest class Constructor                          *
 * This is the constructor for the Blank class. It sets the id to a '@' char.   *
 * it loads the chest with they key for the exit.                               *
 ********************************************************************************/
KeyChest::KeyChest() {
    id = '@';
    contents = new Inventory(1);
    Item* pot = new Key();
    contents->addItem(pot);
    
}

/********************************************************************************
 *                              interact function                               *
 * This function let the character interact with the space but not move into it *
 * If the character is a player they will be able to transfer items into their  *
 * inventory.                                                                   *
 ********************************************************************************/
void KeyChest::interact(Space* current, Character* t) {
    t->setCurrent(current);
    if(t->getAI() ==false) {
        Player *p = dynamic_cast<Player*>(t);
        p->getBag()->transfer(contents);
    }
}

/********************************************************************************
 *                                  Destructor                                  *
 * This will delete the contents of the chest.                                  *
 ********************************************************************************/
KeyChest::~KeyChest() {
    delete contents;
}
