/***********************************************************************
 * Author:          Daniel Flynn
 * Date:            December 10 2019
 * Description:     This is the interface for the LandScape game class.
 *                  It includes the game map, the functions for 
 *                  viewing and modifying the map, and handling 
 *                  character interactions with the map and game.
 *                  ************************************************/

#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP
//class data members:
//turns elapsed / turns total
//2d array of 9 spcaes
//
//class functions:
//create board (loop to create 2D array)
//check game status
//handle terrain interactions - success/fail, diminish energy etc
#include "Space.hpp"
#include "Character.hpp"
#include "LandScapeUtilities.hpp"
class Character;
class LandScape {
    private:
        Space *mapSpaces[9];
    public:
        Space *getMapStart(){return mapSpaces[0];}
        Space *getMapSpaceSingle(Position p);
        void displayIntro();
        void surveySpaces(Character &character);
        void createMap();
        void characterTerrainInteraction(Character &character, 
                Space *s);
        void updateMap(Character &character);
        bool checkGameStatus(Character &character);

        ~LandScape();
};

#endif
