/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the HealthPotion class header file.
 ** This class is a derived class of the item class. It represents a item that
 ** the player can use to regain strength points.
 ******************************************************************************/

#ifndef HealthPotion_hpp
#define HealthPotion_hpp

#include <stdio.h>
#include "Item.hpp"
#include "Character.hpp"

class HealthPotion : public Item {
private:
    int gains;
public:
    HealthPotion();
    virtual void use(Character*);
};
#endif /* HealthPotion_hpp */
