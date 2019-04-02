/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the Wall class header file.
 ** This derived class form the space class represents a space that blocks
 ** movement.
 ******************************************************************************/

#ifndef Wall_hpp
#define Wall_hpp

#include <stdio.h>
#include "Space.hpp"

class Wall : public Space {
public:
    Wall();
    virtual void setid() {id = '#';}
    virtual void setid(char c) {id = c;}
    virtual void interact(Space*, Character*);
    virtual ~Wall(){};
    
};
#endif /* Wall_hpp */
