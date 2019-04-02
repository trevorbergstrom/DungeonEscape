/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 5/1/17
 ** Description: This .hpp file is the inputValidation class header file.
 ** This class contains functions to validate different types of input.
 ******************************************************************************/

#ifndef inputValid_hpp
#define inputValid_hpp

#include <iostream>

using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::string;

int validInt(); // function to validate chars of a string to check input as an integer
int minimumInt(int); // function that gets a valid int and checks it against a minimum
int minMaxInt(int, int);
void intArray(int*, int);
char validChar(char*, int);

#endif
