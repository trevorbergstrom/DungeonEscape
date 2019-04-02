/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 4/15/17
 ** Description: This .hpp file is the menu class header file.
 ** The menu class displays a menu with a specific number of choices to the user
 ** and returns the choice to the main program using it.
 ******************************************************************************/

#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>
#include <vector>
#include "inputValid.hpp"

using std::string; // using these from the standard library
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Menu {
    
private:
    vector<string> prompts; // vector for menu prompts
    string heading;
public:
    Menu(vector<string>, string); // constructor
    int displayIntChoices(); // function to display choices in an integer list format
    void displayInstructions();
};

#endif

