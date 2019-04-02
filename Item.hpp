/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Item class implementation file.
 ** This class is a abstact class that represents an item the player can use
 ** to complete the game. Its derived classes are HealthPotion and key.
 ******************************************************************************/

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <iostream>
#include "Player.hpp"

using std::string;

class Item {
protected:
    string description;
    bool consumable;
public:
    Item() {};
    bool isConsumable() {return consumable;}
    std::string getDesc() {return description;}
    virtual void use(Character*) = 0;
    virtual ~Item() {};
};
#endif /* Item_hpp */
