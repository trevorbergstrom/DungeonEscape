/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Chest class implementation file.
 ** This derived class form the space class represents a space has a chest
 ** containing an inventory of items.
 ******************************************************************************/

#include "Chest.hpp"

/********************************************************************************
 *                            Wall class Constructor                            *
 * This is the constructor for the Blank class. It sets the id to a '@' char.   *
 * it loads the chest with a two health potions.                                *
 ********************************************************************************/
Chest::Chest() {
    id = '@';
    contents = new Inventory(2);
    Item* pot = new HealthPotion();
    Item* pot2 = new HealthPotion();
    contents->addItem(pot);
    contents->addItem(pot2);
}

/********************************************************************************
 *                              interact function                               *
 * This function let the character interact with the space but not move into it *
 * If the character is a player they will be able to transfer items into their  *
 * inventory.                                                                   *
 ********************************************************************************/
void Chest::interact(Space* current, Character* t) {
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
Chest::~Chest() {
    delete contents;
}
