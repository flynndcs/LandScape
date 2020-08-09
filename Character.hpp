/*******************************************************************
 * Author:          Daniel Flynn
 * Date:            December 10 2019
 * Description:     This is the interface for the CHaracter class.
 * ****************************************************************/

//class data members: 
//x position, y position
//inventory:
//fish shtack
//ore stack
//skull stack
//energy points
//functions:
//interact with terrain - return success or fail
//move in 8 cardinal directions - check for array bounds
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "LandScapeUtilities.hpp"
#include <stack>
#include <string>
#include "LandScape.hpp"
#include "Space.hpp"
//forward declare LandScape to be used in this class
class LandScape;
class Character{
    private:
        //position, containers for items, energy points for step limit
        Position position;
        std::stack<std::string> fishStack;
        std::stack<std::string> oreStack;
        std::stack<std::string> skullStack;
        int energyPoints = 50;

    public:
        //getters and setters
        Position getPosition(){return position;}
        void setPosition(Position p){position = p;}

        int getFishStackSize(){return fishStack.size();}
        void pushFishStack(std::string f){fishStack.push(f);}

        int getOreStackSize(){return oreStack.size();}
        void pushOreStack(std::string o){oreStack.push(o);}

        int getSkullStackSize(){return skullStack.size();}
        void pushSkullStack(std::string s){skullStack.push(s);}

        int getEnergyPoints(){return energyPoints;}
        void setEnergyPoints(int p){energyPoints = p;}

        //movement and space functions
        Space* chooseMoveSpace(LandScape &l);
        void moveSpace(Space* spacePtr);
        Character(Position p);
};

#endif
