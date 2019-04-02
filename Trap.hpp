/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .hpp file is the Trap class header file.
 ** This derived class form the space class represents a space that if the
 ** player steps into they will take damage.
 ******************************************************************************/

#ifndef Trap_hpp
#define Trap_hpp

#include <stdio.h>
#include "Space.hpp"
#include "Player.hpp"

class Trap : public Space {
public:
    Trap();
    virtual void setid() {id = '$';}
    virtual void setid(char c) {id = c;}
    virtual void interact(Space*, Character*);
    virtual ~Trap() {};
    
};
#endif /* Trap_hpp */
