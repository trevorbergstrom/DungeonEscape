/******************************************************************************
 ** Author: Trevor Bergstrom
 ** Date: 6/12/17
 ** Description: This .cpp file is the HealthPotion class implementation file.
 ** This class is a derived class of the item class. It represents a item that
 ** the player can use to regain strength points.
 ******************************************************************************/

#include "HealthPotion.hpp"

/********************************************************************************
 *                        HealthPotion class Constructor                        *
 * This is the constructor for the HealthPotion class.                          *
 ********************************************************************************/
HealthPotion::HealthPotion() {
    gains = 10;
    description = "Health Potion";
    consumable = true;
}

/********************************************************************************
 *                                  use function                                *
 * This function will allow the player to consume the health potion and regain  *
 * some strength.                                                               *
 ********************************************************************************/
void HealthPotion::use(Character* me) {
    if(me->getAI() == false) {
        Player *p = dynamic_cast<Player*>(me);
        cout << "Drinking health potion..." << endl;
        p->heal(gains);
    cout << "You gained " << gains << " strength points!\nYour new strength is " << p->getStrength() << endl;
    }
}
