/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the Player class header file.
 ** This class is a derived class of the character class. The player represents
 ** the character that the user can control. The player has an inventory of
 ** item that they can use at anytime.
 ******************************************************************************/

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Character.hpp"
#include "Inventory.hpp"

class Inventory;
class Item;

class Player : public Character {
private:
    Inventory* bag;
    int strength, maxBag;
    bool weapon, armor;
    
public:
    Player(Space*);
    virtual void move(Space* next);
    void takeDam(int dam) {strength -= dam;}
    void heal(int gains) {strength += gains;}
    int getStrength() {return strength;}
    void openBag();
    void addItem(Item*);
    Inventory* getBag() {return bag;}
    ~Player();
};
#endif /* Player_hpp */
