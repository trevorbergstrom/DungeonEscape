/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Player class implementation file.
 ** This class is a derived class of the character class. The player represents 
 ** the character that the user can control. The player has an inventory of 
 ** item that they can use at anytime.
 ******************************************************************************/

#include "Player.hpp"

/********************************************************************************
 *                           Player class Constructor                           *
 * This is the constructor for the Player class. It will take a space for the   *
 * player to start on and set up its inventory and starting strength.           *
 ********************************************************************************/
Player::Player(Space* start) {
    id = 'x';
    current = start;
    isAI = false;
    maxBag = 3;
    strength = 30;
    weapon = false;
    armor = false;
    bag = new Inventory(maxBag);
}

/********************************************************************************
 *                                  move function                               *
 * This takes the next space to move into and calls its interact function       *
 * parameterizing it with the current space and the player.                     *
 ********************************************************************************/
void Player::move(Space* next) {
    next->interact(current, this);
}

/********************************************************************************
 *                                openBag function                              *
 * This function lets the player open their inventory and use items. If its is  *
 * consumable it will be deleted. This function will call the inventory display *
 * function to get the item to use.                                             *
 ********************************************************************************/
void Player::openBag() {
    cout << "Select an item to use, or use 0 to exit" << endl;
    Item* i = bag->display();
    
    if(i != nullptr) { // if the player selectd an item
        i->use(this); // use function call
        if(i->isConsumable()) { // if it is a consumeable
            bag->removeItem(i); // remove after using.
            delete i; 
        }
    }
}

/********************************************************************************
 *                                addItem function                              *
 * This function allows the player to add an item to their inventory.           *
 ********************************************************************************/
void Player::addItem(Item* i) {
    bag->addItem(i); // call inventory add function
}

/********************************************************************************
 *                                  Destructor                                  *
 * t\The destructor will delete the inventory.                                  *
 ********************************************************************************/
Player::~Player() {
    delete bag;
}
