/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Key class implementation file.
 ** This class is a derived class of the item class. It represents a item that
 ** the player needs to unlock the exit. It simply displays the keycode string. 
 ******************************************************************************/

#include "Key.hpp"

/********************************************************************************
 *                            Key class Constructor                             *
 * This is the constructor for the Key class. It sets the code to display and   *
 * description to display to the user.                                          *
 ********************************************************************************/
Key::Key() {
    lockCode = "7565";
    description = "This is the dungeon lock combination...";
    consumable = false;
}

/********************************************************************************
 *                                 use function                                 *
 * This function will allow the player to view the dungeon key code.            *
 ********************************************************************************/
void Key::use(Character* t) {
    cout << "The lock combination is " << lockCode << endl;
}
