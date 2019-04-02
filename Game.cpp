/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the Game class implementation file. 
 ** The game class plays the dungeon escape maze game. This class contains the 
 ** functions to play all the steps of the game.
 ******************************************************************************/

#include "Game.hpp"

/********************************************************************************
 *                            Game class Constructor                            *
 * This is the constructor for the Game class. It initializes all the data      *
 * for a game. It will create the board form a text file.                       *
 ********************************************************************************/
Game::Game() {
    gameBoard = new Board("test2.txt"); // new board
    me = new Player(gameBoard->getStart()); //  new player
    setTrollies(gameBoard->getTrollies()); // trolls
    turnCount = 300; // number of turns
    doorCode = "7565"; // lock code
    playerQuit = false; 
}

/********************************************************************************
 *                            setTrollies function                              *
 * This function will take a vector of spaces where trolls should be and use    *
 * the spaces to create new trolls on the board in this location. The trolls are*
 * stored in a vector.                                                          *
 ********************************************************************************/
void Game::setTrollies(vector<Space*> trolls) {
    int i = (int) trolls.size();
    
    for(int j = 0; j < i; j++) { // loop though trolls
        trollies.push_back(new Troll(trolls.at(j))); // create new trolls and store in vector
    }
}

/********************************************************************************
 *                            movePlayer Function                               *
 * This function will move the player using user input. The user also has the   *
 * ability to view their inventory, view instructions, or quit the game.        *
 ********************************************************************************/
void Game::movePlayer() {
	printf("Please enter your next move\n");
    printf("Current Health: %d\n", me->getStrength());
    char goodinput[] = {'w','a','s','d','i','q','h'}; // array to validate input
    char c = validChar(goodinput, 7);
    Space* currentSp = me->getCurrent(); // get current space
    
    switch (c) { // switch for different input
        case 'w':
            currentSp->getUp()->interact(currentSp, me); // get the coresponding next space
            break;
        case 'd':
            currentSp->getRight()->interact(currentSp, me);
            break;
        case 's':
            currentSp->getDown()->interact(currentSp, me);
            break;
        case 'a':
            currentSp->getLeft()->interact(currentSp, me);
            break;
        case 'i':
            me->openBag(); // view inventory
            break;
        case 'q':
            playerQuit = true; // quit game
            break;
        case 'h':
            instructions(); // view instructions
            break;
    }
    if(me->getCurrent()->getTroll() == true) { // if there is a troll on the space
        me->takeDam(10); // take damage
        printf("You encountered a troll! Your strength is %d\n",me->getStrength());
    }
}

/********************************************************************************
 *                            moveTroll function                                *
 * This function will move the trolls in the trollies vector. It will pick a    *
 * random number and move the troll in a coresponding directions and interact   *
 * with that next space.                                                        *
 ********************************************************************************/
void Game::moveTroll() {
    int i = (int) trollies.size();
    
    for(int j = 0; j < i; j++ ) { // loop through troll vector
        Troll* t = trollies.at(j); // troll to mobe
        int dir = rand() % 4 + 1; // get and random number
        Space* current = t->getCurrent();
        current->setTroll(false); // remove troll check
        
        switch (dir) {
            case 1:
                current->getUp()->interact(current, t); // move to coresponding direction
                break;
            case 2:
                current->getRight()->interact(current, t);
                break;
            case 3:
                current->getDown()->interact(current, t);
                break;
            case 4:
                current->getLeft()->interact(current, t);
                break;
        }
        t->getCurrent()->setTroll(true); // set the troll check
    }
}

/********************************************************************************
 *                            isGameOver function                               *
 * This function will check different cases to see if the game is over so the   *
 * play function knows to stop the game.                                        *
 ********************************************************************************/
bool Game::isGameOver() {
    if(me->getStrength() <= 0){ // if the player's strength is 0 or less
        printf("You have died. Nice try. Game Over.\n");
        return true; //game over
    } else if(me->getCurrent() == gameBoard->getExit()) { // if the player is at the exit
        printf("You the dungeon exit, but it has a combination lock on it! Enter the combination: \n");
        string guess;
        getline(cin, guess); // ask for the combination
        if(guess == doorCode) { // if the guess is correct
        	printf("That was correct! You have escaped the dungeon!\n");
            return true; //game over
        } else {
        	printf("That was wrong, find the door code!\n");
            return false; // game not over
        }
    } else if(playerQuit == true) { // if player wants to quit
    	printf("You quit the game! You still lose though.\n");
        return true; // game over
    } else {
        return false; // game not over if no conditions are met
    }
}

/********************************************************************************
 *                            play function                                     *
 * This function follows steps to play the game. It loops for the allocated     *
 * number of turns.                                                             *
 ********************************************************************************/
void Game::play() {
    int i;
    for(i = 0; i < turnCount; i++) { // loop for number of turns
        gameBoard->printBoard(); // print board
        printf("You have %d turns left before morning!\n", turnCount - i);
        movePlayer(); // move player
        moveTroll(); // move trolls
        if(isGameOver()) { // check game over
            break;
        }
    }
    if(i >= turnCount) { // if you have run out of turns
    	printf("You have run out of time! Nice try. You Loose.\n");
    }
}

/********************************************************************************
 *                            instructions Function                             *
 * This function displays the isntructions of the game.                         *
 ********************************************************************************/
void Game::instructions() {
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

/********************************************************************************
 *                            Game class destructor                             *
 ********************************************************************************/
Game::~Game() {
    delete me; // delete player
    delete gameBoard; // delete board
    
    for(int i = 0; i < trollies.size(); i++) { // delete all the trolls
        delete trollies.at(i);
    }
}
