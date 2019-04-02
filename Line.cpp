/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the line class implementation file.
 ** This class represents a row of spaces on the board. It is made of different
 ** types of spaces. The spaces are linked together with 4 pointers to adjacent
 ** spaces.
 ******************************************************************************/

#include "Line.hpp"

/********************************************************************************
 *                            Line class Constructor                            *
 * This is the constructor for the Line class. It takes a string as a row from  *
 * the board and creates coresponding space types. It will link them together   *
 * side to side.                                                                *
 ********************************************************************************/
Line::Line(string fileLine) {
    above = nullptr; // set pointer to null
    below = nullptr;
    start = nullptr;
    end = nullptr;
    entry = nullptr;
    exit = nullptr;
    
    char c = ' ';
    length = 0;
    Space* s = nullptr;
    int lineLength = (int) fileLine.length();
    while(length != lineLength) { // loop through each character in the line
        c = fileLine.at(length);
        
        if(c == '*') {
            s = new Wall(); // create new wall
        } else if(c == '@') {
            s = new Chest(); // create new chest
        } else if(c == '$') {
            s = new Trap(); // create new trap
        } else if (c == 'e') {
            s = new Exit(); // create new exit
            exit = s; // assgin exit pointer
        } else if(c == 'k') {
            s = new KeyChest(); // create new key chest
        } else {
            s = new Blank(); // create new blank space
            if(c == 't') { // if there should be a troll
                trolls.push_back(s); // push to trolls vector
            }
            if(c == 's') { // if it is a start space
                entry = s; //assgin pointer
            }
        }
        if(start == nullptr) { // link all the spaces together
            start = s;
            end = s;
        } else {
            end->setRight(s);
            s->setLeft(end);
            end = s;
        }
        length++; // add to length for loop
    }
}

/********************************************************************************
 *                              printLine function                              *
 * This function will print the id of each space in the line for the user to see*
 ********************************************************************************/
void Line::printLine() {
    Space* s = start;
    for(int i = 0; i < length; i++) { // loop through line and print id of each space
        cout << s->getid();
        s = s->getRight();
    }
}

/********************************************************************************
 *                                  link function                               *
 * This function will link a line to the line above it. It will linek the up    *
 * and down pointer of each space.                                              *
 ********************************************************************************/
void Line::link() {
    if(above != nullptr) { // if the line is not the top line
        Space* c = start;
        Space* a = above->start;
        
        while(c != nullptr) { // loop thorugh each space
            c->setUp(a); // set up and down pointers
            a->setDown(c);
            
            c = c->getRight(); // move traversing pointers
            a = a->getRight();
        }
    }
}

/********************************************************************************
 *                                  destructor                                  *
 * This destructor will loop through each space in the line and delete all the  *
 * spaces in it.                                                                *
 ********************************************************************************/
Line::~Line() {
    Space* dlt = start;
    Space* temp;
    for(int i = 0; i < length; i++) { // loop through
        temp = dlt->getRight(); // assgin pointers
        delete dlt; //delete line
        dlt = temp;
    }
}
