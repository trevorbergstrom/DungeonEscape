/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Troll class implementation file.
 ** This class is a derived class of the character class. The troll represents 
 ** an enemy that the player will take damage if they occupy the same space as.
 ** the troll can move about the board and iteract with blank spaces and walls.
 ******************************************************************************/

#include "Troll.hpp"

/********************************************************************************
 *                           Troll class Constructor                            *
 * This is the constructor for the Troll class. It sets the start space of the  *
 * troll.                                                                       *
 ********************************************************************************/
Troll::Troll(Space* start) {
    id = '&';
    isAI = true;
    current = start;
}

/********************************************************************************
 *                                  move function                               *
 * This takes the next space to move into and calls its interact function       *
 * parameterizing it with the current space and the troll.                      *
 ********************************************************************************/
void Troll::move(Space* next) {
    next->interact(current, this);
}
