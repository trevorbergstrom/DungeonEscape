/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the Inventory class header file.
 ** This class represents a list of items that the player or a chest can have.
 ** the player can choose to use items in the inventory, and swap between a
 ** chest an their inventory. Items can be removed and added. The items are
 ** stored in a vector.
 ******************************************************************************/

#ifndef Inventory_hpp
#define Inventory_hpp

#include <stdio.h>
#include "Item.hpp"
#include "inputValid.hpp"
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Item;

class Inventory {
private:
    vector<Item*> *list;
    int currentSize;
    int totalWeight;
    int maxSize;
public:
    Inventory(int);
    bool addItem(Item*);
    void removeItem(Item*);
    void transfer(Inventory*);
    Item* display();
    ~Inventory();
};
#endif /* Inventory_hpp */
