/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the Chest class header file.
 ** This derived class form the space class represents a space has a chest
 ** containing an inventory of items.
 ******************************************************************************/

#ifndef Chest_hpp
#define Chest_hpp

#include <stdio.h>
#include "Space.hpp"
#include "Inventory.hpp"
#include "HealthPotion.hpp"

class HealthPotion;

class Chest : public Space {
private:
    Inventory* contents;
public:
    Chest();
    virtual void setid() {id = '@';}
    virtual void setid(char c) {id = c;}
    virtual void interact(Space*, Character*);
    virtual ~Chest();
};
#endif /* Chest_hpp */
