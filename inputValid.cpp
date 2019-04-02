/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 5/1/17
 ** Description: This .cpp file is the inputValidation class implementation file.
 ** This class contains functions to validate different types of input.
 ******************************************************************************/

#include "inputValid.hpp"
#include <sstream>

/********************************************************************************
 *                             validInt function                                *
 * This function gets a entry from the user and checks its characters to ensure *
 * that the number entered is a valid integer. This function also checks for a  *
 * negative number.                                                             *
 ********************************************************************************/
int validInt() {
    
    bool flagg = false;
    int returnVal = 0;
    
    while (flagg == false) {
        string entry;
        getline(cin, entry); //get input from  user
        int j = 0;
        if(entry[0] == '-') { // bump up index if its a negative number
            j = 1;
        }
        bool flag = false; // flag for a good value
        for(int i = 0 + j; i < entry.length(); i++) { // loop through the entry string
            if(entry[i] <= 57 && entry[i] >= 48) { // compare chars to ASCII values
                flag = true; // good char
            } else {
                flag = false; // bad char
                break; // break from loop when bad char is found
            }
        }
        if (flag == true) { // if there we only good chars in entry
            returnVal = std::stoi(entry); // convert entry to int
            flagg = true; // flag to stop while loop
        } else {
            cout << "Non a valid input" << endl; // print and error message and stay in while loop
        }
    }
    return returnVal; // return the integer
}

/********************************************************************************
 *                             minimumInt function                              *
 * This function checks if a number is greater than a parameterized minimum     *
 * value. It calls the validInt() function to validate characters.              *
 ********************************************************************************/
int minimumInt(int min) {
    bool flag = false; // flag to stop while loop
    int goodInt = -1;
    while(flag == false) {
        int entry = validInt(); // call function to validate the chars in the int
        if (entry >= min) { // check if greater than min
            goodInt = entry; // assgin to return value
            flag = true; // flagh to break out of loop
        } else {
            cout << "That input was too low. The min is: " << min << endl; // print error message
        }
    }
    return goodInt; // return int
}

/********************************************************************************
 *                              minMaxInt function                              *
 * This function checks if a number is greater than a parameterized minimum and *
 * maximum value. It calls the validInt() function to validate characters.      *
 ********************************************************************************/
int minMaxInt(int min, int max) {
    bool flag = false;
    int goodI = -1;
    while(flag == false){
        int entry = validInt(); // call function to validate characters
        if (entry > max){ // check if greater than max
            cout << "Your input was too high. The max is: " << max << endl;
        } else if (entry < min) { // check if greater than minimum
            cout << "That input was too low. The min is: " << min << endl;
        } else {
            goodI = entry; // if good set to reyurn value
            flag = true; // stop while loop
        }
    }
    return goodI; // return value
}

/********************************************************************************
 *                              intArray function                               *
 * This function gets an array of integers seperated by commas from the user,   *
 * verifies the chars and returns an integer array pointer. Parameter is the    *
 * number of elements in the array.                                             *
 ********************************************************************************/

void intArray(int *myArray, int n) {
    bool flag = false;
    while (flag == false) {
        string entry;
        cout << "Please seperate your integers with ',' (comma characters) no spaces" << endl;
        getline(cin, entry); //get entry from the user
        
        bool flagg = false;
        for(int i = 0; i < entry.length(); i++) { // loop through user's entry and check for good chars
            if((entry[i] <= 57 && entry[i] >= 48) || entry[i] == ',' || entry[i] == '-') { // check ASCII values, negatives and commas
                flagg = true; // good char
            } else {
                flagg = false; // bad char
                break;
            }
        }
        if (flagg == true) { // if there were only good chars entered
            
            for(int i = 0; i < n; i++) { // loop for number of elements in array
                string number;
                std::stringstream ss(entry); // create new stringstrem
                getline(ss, number, ','); // parse string and seperate at commas
                int eraser = (int) number.length(); // create value for chars to erase from string
                number = number.substr(0, eraser); // remove chars from string
                myArray[i] = std::stoi(number); // pass int value of integer to array
                entry = entry.erase(0,eraser+1); // erase from entry string
            }
            flag = true;
            break;
        } else {
            cout << "That was not a valid input" << endl;
        }
    }
}

char validChar(char* goodChars, int n) {
    bool flag = false;
    char c = ' ';
    while(!flag) {
        cout << "Enter your input: " << endl;
        string entry;
        getline(cin, entry);
        bool charFlag = false;
        
        if(entry.size() != 1) {
            cout << "Invalid input. Please try again." << endl;
        } else {
            c = entry.at(0);
            
            for(int i = 0; i < n; i++) {
                if( c == goodChars[i]) {
                    charFlag = true;
                    break;
                }
            }
        }
        if(charFlag) {
            flag = true;
        }
    }
    return c;
}
