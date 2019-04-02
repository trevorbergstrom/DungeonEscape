/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the Space class header file.
 ** The space class is abstarct and represents the spaces that the player can
 ** move in.
 ******************************************************************************/

#ifndef Space_hpp
#define Space_hpp

#include <stdio.h>
#include "Character.hpp"
#include <iostream>

using std::cout;
using std::endl;

class Character;

class Space{
protected:
    Space* up; // pointers to adjacent spaces
    Space* down;
    Space* right;
    Space* left;
    char id; // id to print the spaces
    bool hasTroll; // check if there is a troll in space
    
public:
    Space();
    void setUp(Space* u) {up = u;} // functions to set pointers to adjacent spaces
    void setDown(Space* d) {down = d;}
    void setRight(Space* r) {right = r;}
    void setLeft(Space* l) {left = l;}
    virtual void setid() = 0; // function to set id of the spaces
    virtual void setid(char) = 0; // function to accept a custom character to set id
    
    Space* getUp() {return up;} // functions to get the adjacent spaces
    Space* getDown() {return down;}
    Space* getRight() {return right;}
    Space* getLeft() {return left;}
    char getid() {return id;} // fucntion to get the id
    void setTroll(bool);
    bool getTroll() {return hasTroll;}
    
    virtual void interact(Space*, Character*) = 0; // function to interact with the character
    virtual ~Space() {}; // destructor
};
#endif /* Space_hpp */
