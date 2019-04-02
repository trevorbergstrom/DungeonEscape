/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Inventory class implementation file.
 ** This class represents a list of items that the player or a chest can have. 
 ** the player can choose to use items in the inventory, and swap between a
 ** chest an their inventory. Items can be removed and added. The items are 
 ** stored in a vector.
 ******************************************************************************/

#include "Inventory.hpp"

/********************************************************************************
 *                          Inventory class Constructor                         *
 * This is the constructor for the Inventory class. It will set up the vector   *
 * to store the items by the parameterized size.                                *
 ********************************************************************************/
Inventory::Inventory(int size) {
    totalWeight = 0;
    currentSize = 0;
    maxSize = size;
    list = new vector<Item*>;
}

/********************************************************************************
 *                               addItem function                               *
 * This function will add an item to the inventory.                             *
 ********************************************************************************/
bool Inventory::addItem(Item* i) {
    if(currentSize >= maxSize) { // if player attempts to add to a full inventory
        cout << "Your inventory is full!" << endl;
        return false; // return a false
    } else {
        list->push_back(i); // push back to vector
        currentSize++; // current size increases
        return true; //return a true
    }
}

/********************************************************************************
 *                            removeItem function                               *
 * This function removes an item form the inventory vector.                     *
 ********************************************************************************/
void Inventory::removeItem(Item* i) {
    vector<Item*> *swap = new vector<Item*>; // create new vector
    for(int j = 0; j < currentSize; j++) { // loop through old vector
        if(i != list->at(j)) { // if it isnt the item to remove
            swap->push_back(list->at(j)); // add to new vector
        }
    }
    delete list; // delete old vector
    list = swap; // reassgin pointers
    currentSize--; // subtract current size
}

/********************************************************************************
 *                               display function                               *
 * This function shows the user the items in the inventory and allows them to   *
 * select a item to use. This item will be returned from the function.          *
 ********************************************************************************/
Item* Inventory::display() {
    for(int i = 0; i < currentSize; i++) {
        cout << i + 1 << ") " << list->at(i)->getDesc() << endl; // display inventory
    }
    cout << "0) Exit" << endl; // display choice to exit
    
    int choice = minMaxInt(0, currentSize); // get choice from user
    
    if(choice == 0) {
        return nullptr; //return nullptr if user doesnt want to use an item
    } else {
        return list->at(choice - 1); // return the item selected
    }
}

/********************************************************************************
 *                              transfer function                               *
 * This function allows the user to select an item from one inventory and       *
 * transfers it to another inventory.                                           *
 ********************************************************************************/
void Inventory::transfer(Inventory* chestCont) {
    Item* move = chestCont->display(); // display and get the item to transfer
    chestCont->removeItem(move); // remove the item from old inventory
    addItem(move); // move to inventory
}

/********************************************************************************
 *                                  Destructor                                  *
 * The destructor will loop through the vector and delete each item.            *
 ********************************************************************************/
Inventory::~Inventory() {
    for(int i = 0; i < list->size(); i++) {
        delete list->at(i); // delete each item in vector
    }
    delete list; // delete vector. 
}
