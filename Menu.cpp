/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 4/15/17
 ** Description: This .cpp file is the menu class implementation file.
 ** The menu class displays a menu with a specific number of choices to the user
 ** and returns the choice to the main program using it.
 *******************************************************************************/

#include "Menu.hpp"
#include <iostream>

/********************************************************************************
 *                            Menu class Constructor                            *
 * This is the constructor for the menu class. It is parameterized with the     *
 * prompts to give the user.                                                    *
 ********************************************************************************/
Menu::Menu(vector <string> userPrompts, string head) {
    prompts = userPrompts;
    heading = head;
}

/********************************************************************************
 *                        displayIntChoices Function                            *
 * This function displays the chioces to user and takes their choice and return *
 * that choice to main function                                                 *
 ********************************************************************************/
int Menu::displayIntChoices() {
	printf("%s\n", heading.c_str());
    int promptCount = 0;
    for (int i = 0; i < prompts.size(); i++) { // loop through the vector containing the prompts to the user
    	printf("%d. %s\n", i+1, prompts.at(i).c_str());
        promptCount++;
    }
    return minMaxInt(1, promptCount); // call the function to validate the input with a min and max value
}

/********************************************************************************
 *                        displayInstructions Function                          *
 * This function displays the game instructions.                                *
 ********************************************************************************/
void Menu::displayInstructions() {
	printf("You have been imprisoned in the castle dungeons...\n");
    printf("You will be executed in the morning.\nBut you have found a secret passage to the castle sewers....\nYou must escape by dawn or the gaurds will discover your escape and recapture you!");
    printf("This is the map of the sewers.\nYour location is marked with an 'x'.\n");
    printf("Walls are marked with a '*', treasure chests are marked with a '@', and traps with a '$'\n");
    printf("Dungeon trolls are lurking in the sewers marked with a '&'. Avoid if you can.\n");
    printf("You start with 30 strength points. Search treasure chests to find health potions and the dungeon key combination.\n");
    printf("Find the key combination in a treasure chest and use it to unlock the door and escape.\nBeware of traps along the way.\n");
    printf("Move with 'w', 'a', 's', and 'd'.\nOpen your inveontory by pressing 'i' at anytime and select the item to equip with the coresopnding number.\n");
    printf("You can press 'q' at anytime to quit the game. Press 'h' at any time to display the instructions.\n");
    printf("You only have 100 turns until daylight when you will b e discovered. Do not dilly-dally!\n");
    printf("REMEMBER YOU NEED TO FIND THE DUNGEON KEY COMBINATION IN A TREASURE CHEST!\n");
    printf("God luck and goodspeed!\n");
}

