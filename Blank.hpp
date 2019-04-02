/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Blank class implementation file.
 ** This derived class form the space class represents a blank space that
 ** can be stepped into.
 ******************************************************************************/

#ifndef Blank_hpp
#define Blank_hpp

#include <stdio.h>
#include "Space.hpp"

class Blank : public Space {
public:
    Blank();
    virtual void setid() {id = ' ';}
    virtual void setid(char c) {id = c;}
    virtual void interact(Space*, Character*);
    virtual ~Blank(){};
};
#endif /* Blank_hpp */
