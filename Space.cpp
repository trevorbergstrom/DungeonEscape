/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Space class implementation file.
 ** The space class is abstarct and represents the spaces that the player can 
 ** move in. 
 ******************************************************************************/
#include "Space.hpp"

/********************************************************************************
 *                           Space class Constructor                            *
 * This is the constructor for the Space class. It sets all pointers to null.   *
 ********************************************************************************/
Space::Space() {
    up = nullptr;
    down = nullptr;
    right = nullptr;
    left = nullptr;
    hasTroll = false;
}

/********************************************************************************
 *                            Set troll function                                *
 * This function will set the troll check in the space.                         *
 ********************************************************************************/
void Space::setTroll(bool troll) {
    if (troll) {
        hasTroll = true;
    } else {
        hasTroll = false;
    }
}
