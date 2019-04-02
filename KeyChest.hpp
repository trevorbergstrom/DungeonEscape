/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the KeyChest class implementation file.
 ** This derived class form the space class represents a space has a chest
 ** containing an inventory of items. This chest contains the key for the door.
 ******************************************************************************/

#ifndef KeyChest_hpp
#define KeyChest_hpp

#include "Space.hpp"
#include "Inventory.hpp"
#include "Key.hpp"

class HealthPotion;

class KeyChest : public Space {
private:
    Inventory* contents;
public:
    KeyChest();
    virtual void setid() {id = '@';}
    virtual void setid(char c) {id = c;}
    virtual void interact(Space*, Character*);
    virtual ~KeyChest();
};
#endif /* KeyChest_hpp */
