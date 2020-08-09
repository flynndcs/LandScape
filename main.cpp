
/****************************************************************
 * Author:          Daniel Flynn
 * Date:            December 10 2019
 * Description:
 * LandScape, Exploration/Adventure RPG
 *
 * player dropped onto random location
 * can stay or move
 * act on following spaces: empty, water, ore, enemy dungeon (cannot escape dungeon)
 * view other spaces
 * check inventory, check remaining energy points
 * if successful get fish, ore, or skull and lose one energy point
 * if unsuccessful lose one energy point
 * moving always costs an energy point
 * game ends if user gets 30 fish, 20 ore or 15 skulls
 * inventory - 3 stacks of items
 * each space has 8 pointers, some of which are null except center
 * map is a 3x3 grid - and spaces regenerate/reinitialize after being moved from 
 * map is stored in a array for traversal, member of Game class
 *
 * 
 ********************************************************************/
#include "LandScape.hpp"
#include "Character.hpp"
#include "Menu.hpp"
#include "LandScapeUtilities.hpp"
#include <cstdlib>
#include <ctime>
int main(){
    //random seed for various random actions, init objects
    srand(time(NULL));
    LandScape game;
    Character character(Center);
    bool gameInProgress = true;

    //start game procedures
    game.displayIntro();
    game.createMap();
    game.surveySpaces(character);
    //each turn's repeated procedures
    while (gameInProgress){
        game.characterTerrainInteraction(character, 
                game.getMapSpaceSingle(character.getPosition()));
        game.updateMap(character);
        character.moveSpace(character.chooseMoveSpace(game));
        game.surveySpaces(character);
        gameInProgress = game.checkGameStatus(character);
    }
    //prompt user to play again or exit
    Menu menu;
    int userChoice = 0;
    while (userChoice < 1 || userChoice > 2){
        userChoice = menu.promptSingleResponseInt("1. Play Again"
                "2. Exit");
    }
    if (userChoice == 1){
        main();
    }
    else {
        exit(0);
    }
    return 0;
}
