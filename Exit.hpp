/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the exit class header file.
 ** This derived class form the space class represents a space that is the door
 ** or exit point to the board.
 ******************************************************************************/

#ifndef Exit_hpp
#define Exit_hpp

#include <stdio.h>
#include "Space.hpp"

class Exit : public Space {

public:
    Exit();
    virtual void setid() {id = 'e';}
    virtual void setid(char c) {id = c;}
    virtual void interact(Space*, Character*);
    virtual ~Exit() {};
};
#endif /* Exit_hpp */
