/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the line class implementation file.
 ** This class represents a row of spaces on the board. It is made of different
 ** types of spaces. The spaces are linked together with 4 pointers to adjacent
 ** spaces.
 ******************************************************************************/

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>
#include "Space.hpp"
#include <vector>
#include "iostream"
#include "Wall.hpp"
#include "Blank.hpp"
#include "Chest.hpp"
#include "Trap.hpp"
#include "Exit.hpp"
#include "KeyChest.hpp"

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Line {
private:
    Line* above;
    Line* below;
    Space* start;
    Space* end;
    int length;
    Space* entry;
    Space* exit;
    vector<Space*> trolls;
    
public:
    Line(string);
    void printLine();
    void link();
    
    Space* getStart() {return start;}
    Space* getEnd() {return end;}
    void setStart(Space* s) {start = s;}
    void setEnd(Space* s) {end = s;}
    
    Line* getAbove() {return above;}
    Line* getBelow() {return below;}
    void setAbove(Line* l) {above = l;}
    void setBleow(Line* l) {below = l;}
    
    vector<Space*> getTrolls() {return trolls;}
    int getLength() {return length;}
    Space* getEntryPoint() {return entry;}
    Space* getExitPoint() {return exit;}
    
    vector<Space*> getTrollLine() {return trolls;}
    
    ~Line();
    
    
};
#endif /* Line_hpp */
