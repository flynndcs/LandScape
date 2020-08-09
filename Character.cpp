/*******************************************************************
 * Author:          Daniel Flynn
 * Date:            December 10 2019
 * Description:     This is the implementation of the the 
 *                  Character class, including functions to
 *                  choose a space and move to a space.
 *                  *********************************************/

#include "Character.hpp"
#include "Menu.hpp"
#include "Space.hpp"
#include "LandScapeUtilities.hpp"
#include <string>
#include <iostream>

//Constructor = sets position on map 
Character::Character(Position p){
    position = p;
}

//Chooses the space to move to based on map
Space* Character::chooseMoveSpace(LandScape &l){
    Menu menu;
    int userResponse = 0;
    while (userResponse < 1 || userResponse > 9){
        userResponse = menu.promptSingleResponseInt(
            "What space would you like to move to? \n"
            "You may only move "
            "one spot away in the 8 cardinal directions, "
            "and not past the 9 squares.\n"
            "1. Northwest\n"
            "2. North\n"
            "3. Northeast\n"
            "4. West\n"
            "5. Center\n"
            "6. East\n"
            "7. Southwest\n"
            "8. South\n"
            "9. Southeast\n"
        );
    }
    //userResponse returns the map space desired as a pointer to
    //a Space "object" from the Space abstract/base class
    switch (userResponse){
        case 1:
            return l.getMapSpaceSingle(Northwest);
            break;
        case 2:
            return l.getMapSpaceSingle(North);
            break;
        case 3:
            return l.getMapSpaceSingle(Northeast);
            break;
        case 4:
            return l.getMapSpaceSingle(West);
            break;
        case 5:
            return l.getMapSpaceSingle(Center);
            break;
        case 6:
            return l.getMapSpaceSingle(East);
            break;
        case 7: 
            return l.getMapSpaceSingle(Southwest);
            break;
        case 8:
            return l.getMapSpaceSingle(South);
            break;
        case 9:
            return l.getMapSpaceSingle(Southeast);
            break;
        default:
            std::cout << "Value inputted is not a valid position"
                << std::endl;
    }
}

//moves character to space indicated by parameter
void Character::moveSpace(Space* spacePtr){
    //strings to be printed to console to indicate position
    char *positionStrings[] = {
        "Northwest",
        "North",
        "Northeast",
        "West",
        "Center",
        "East",
        "Southwest",
        "South",
        "Southeast"
    };
    //current character position 
    Position p = this->position;
    //desired position controlled by proximity, if character is not
    //touching the space on sides or corners, the move will not occur
    switch (spacePtr->getPosition()){   
        case (Northwest):
            if (p == West || p == Center || p == North){
                this->position = Northwest;
            }
            else {
               std::cout << "Invalid move" << std::endl;
            }

            break;
        case (North):
            if (p != Southwest && p != South && p != Southeast){
                this->position = North;
            }
            else {
               std::cout << "Invalid move" << std::endl;
            }
            break;
        case (Northeast):
            if (p == North || p == Center || p == West){
                this->position = Northeast;
            }
            else {
               std::cout << "Invalid move" << std::endl;
            }
            break;
        case (West):
            if (p != Northeast && p != East && p != Southeast){
                this->position = West;
            }
            else {
               std::cout << "Invalid move" << std::endl;
            }
            break;
        case (Center):
           this->position = Center; 
           break;
        case (East):
           if (p != Northwest && p != West && p != Southwest){
               this->position = East;
           }
           else {
               std::cout << "Invalid move" << std::endl;
           }
           break;
        case (Southwest):
           if (p == West || p == Center || p == South){
               this->position = Southwest;
           }
           else {
               std::cout << "Invalid move" << std::endl;
           }
           break;
        case (South):
           if (p != Northwest && p != North && p != Northeast){
               this->position = South;
           }
           else {
               std::cout << "Invalid move" << std::endl;
           }
           break;

        case (Southeast):
           if (p == Center || p == East || p == South){
               this->position = Southeast;
           }
           else {
               std::cout << "Invalid move" << std::endl;
           }

           break;
   
            
    }
    std::cout << "Position is "
        << positionStrings[this->position] << std::endl;
}
