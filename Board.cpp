/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Board class implementation file.
 ** This class represents a board. The board is made up of lines of spaces, like
 ** rows. Each space has a pointer to another space. The board has an exit and a 
 ** entry point for the player.
 ******************************************************************************/

#include "Board.hpp"

/********************************************************************************
 *                            Board class Constructor                           *
 * This is the constructor for the Board class. It will take a string that is   *
 * the file name that contains the details for the spaces to use. It will       *
 * build each line and link them together top to bottom. It will then find all  *
 * the trolls and the start and exit spaces.                                    *
 ********************************************************************************/
Board::Board(string fileName) {
    xlen = 0;
    ylen = 0;
    top = nullptr;
    bottom = nullptr;
    
    std::fstream dataIn(fileName, std::ios::in); // open file
    if(dataIn.fail()) { // if fail
        cout << "Error! No board reccords exist" << endl;
    } else {
        while(!dataIn.eof()) { // loop through file till end
            string fileLine;
            getline(dataIn, fileLine, '\n'); // get each line
            
            Line* l = new Line(fileLine); // call line constructor with line form file
            
            if(top == nullptr) { // link the lines into connected rows
                top = l;
                bottom = l;
            } else {
                bottom->setBleow(l);
                l->setAbove(bottom);
                bottom = l;
                bottom->link();
            }
            xlen = bottom->getLength(); // get the xlength
            ylen++; // add up number of rows
        }
    }
    getTrolls(); // get the trolls
    start = findStart(); // find and assgin start spot
    exit = findExit(); // find and assgin exit spot.
}

/********************************************************************************
 *                            printBoard function                               *
 * This function prints the board line by line to the user.                     *
 ********************************************************************************/
void Board::printBoard() {
    Line* l = top;
    if(l == nullptr) {
        cout << "Empty Board" << endl;
    } else {
        while(l != nullptr) { // loop through each lilne
            l->printLine(); // print the line
            cout << '\n';
            l = l->getBelow(); // get next line
        }
        cout << '\n';
    }
}

/********************************************************************************
 *                              getTrolls function                              *
 * This function gets the trolls from the board and adds them to the vector.    *
 ********************************************************************************/
void Board::getTrolls() {
    Line* l = top;
    vector<Space*> troll;
    while (l != nullptr) { // loop through each line
        troll = l->getTrollLine();
        
        if(!troll.empty()) {
            int i =(int) troll.size();
            
            for(int j = 0; j < i; j++) {
                trollLocations.push_back(troll.at(j));
            }
        }
        l = l->getBelow();
    }
}

/********************************************************************************
 *                              findStart function                              *
 * This function finds the start spot for the player by looping through each    *
 * line on the board to find the start space.                                   *
 ********************************************************************************/
Space* Board::findStart() {
    Line* l = top;
    Space* startingpoint = nullptr;
    
    while (l != nullptr) {// loop through each line
        if(l->getEntryPoint() == nullptr && startingpoint == nullptr) { // if the start hasnt been found yet
            l = l->getBelow();
        } else {
            startingpoint = l->getEntryPoint(); // assgin start
            break;
        }
    }
    startingpoint->setid('x'); // set char id in the start
    return startingpoint;
}

/********************************************************************************
 *                               findExit function                              *
 * This function finds the exit spot for the player by looping through each line*
 * on the board to find the exit space. The exit space pointer will be returned *
 ********************************************************************************/
Space* Board::findExit() {
    Line* l = top;
    Space* exitpoint = nullptr;
    
    while(l != nullptr) { // loop through each line
        if(l->getExitPoint() == nullptr && exitpoint == nullptr) { // if the exit point hasnt been found yet
            l = l->getBelow();
        } else {
            exitpoint = l->getExitPoint(); // assgin exit.
            break;
        }
    }
    return exitpoint;
}

/********************************************************************************
 *                                  Destructor                                  *
 * the destructor for the board class will loop through and call delete on each *
 * line.                                                                        *
 ********************************************************************************/
Board::~Board() {
    Line* dlt = top;
    Line* temp;
    
    while(dlt != nullptr) { // loop through and reassgin pointers till each line is deleted
        temp = dlt->getBelow();
        delete dlt;
        dlt = temp;
    }
}
