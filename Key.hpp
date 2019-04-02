/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the Key class header file.
 ** This class is a derived class of the item class. It represents a item that
 ** the player needs to unlock the exit. It simply displays the keycode string.
 ******************************************************************************/

#ifndef Key_hpp
#define Key_hpp

#include <stdio.h>
#include "Item.hpp"

class Key : public Item {
private:
    string lockCode;
public:
    Key();
    virtual void use(Character*);
};
#endif /* Key_hpp */
