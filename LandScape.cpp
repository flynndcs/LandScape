/**********************************************************************
 * Author:          Daniel Flynn
 * Date:            December 10 2019
 * Description:     This is the implementation for the LandScape game
 *                  class.
 *                  *************************************************/

#include "LandScape.hpp"
#include "LandScapeUtilities.hpp"
#include "Space.hpp"
#include "DesertSpace.hpp"
#include "WaterSpace.hpp"
#include "MineSpace.hpp"
#include "DungeonSpace.hpp"
#include "Menu.hpp"
#include <iostream>
//returns a pointer to the map location indicated in the parameter
Space* LandScape::getMapSpaceSingle(Position p){
    for (int i = 0; i < 9; i++){
        //std::cout << mapSpaces[i]->getPosition() << std::endl;
        if (p == mapSpaces[i]->getPosition()){
            return mapSpaces[i];
        }
    }
}
//Prints a narrative intro to the game
void LandScape::displayIntro(){
    std::cout << "~~~~~~~~~~~~~" << std::endl;
    std::cout << "Where am I?" << std::endl << std::endl;
    std::cout << "A plaque just barely peeking out of the ground " 
        << "reads: `You have 50 steps left. Choose them wisely.`" 
        << std::endl;
    std::cout << "You have three compartments in a backpack." 
        <<std::endl;
    std::cout << "One has the number 30 and a picture of a fish." 
        <<std::endl;
    std::cout << "Another has the number 20 a picture of a rock" 
        << " with a grain of shiny metal within."
        << std::endl;
    std::cout << "The last has the number 15 with a skull next to it."
        << std::endl;
    std::cout << "It appears a cell phone is enclosed in these "
        << "compartments, accesible only when the items have been "
        << "acquired. I have some work to do!" << std::endl;
    std::cout << "~~~~~~~~~~~~" << std::endl;
}
//prints the terrain types for the 9 spaces on the map
void LandScape::surveySpaces(Character &character){
    Menu menu;
    char *terrainStrings[] = {
        "Desert",
        "Water",
        "Mine",
        "Dungeon"
    };
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
    std::cout << "Would you like to view the terrain?" << std::endl;
    int userChoice = 0;
    while (userChoice == 0){
        userChoice = menu.promptSingleResponseInt("Press 1 for yes,"
                " and any other number for no.");
    }
    if (userChoice == 1){
        for (int i = 0; i < 9; i += 3 ){
            std::cout 
                << terrainStrings[this->mapSpaces[i]->getTerrain()] 
                << " | ";
            std::cout 
                << terrainStrings[this->mapSpaces[i + 1]->getTerrain()] 
                << " | ";
            std::cout 
                << terrainStrings[this->mapSpaces[i + 2]->getTerrain()] 
                << " | ";
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Your position is: " 
            << positionStrings[character.getPosition()] 
            << std::endl;
    }
    else {;}

}
//initializes the map as 9 Spaces that are then dynamically allocated
//randomly as either Desert, Water, Mine, or Dungeon derived spaces.
void LandScape::createMap(){
    for (int i = 0; i < 9; i++){
        int randValue = rand() % 4;
        switch (randValue){
            case (0):
                this->mapSpaces[i] = new DesertSpace((Position)i, Desert);
                break;
            case (1):
                this->mapSpaces[i] = new WaterSpace((Position)i, Water);
                break;
            case (2):
                this->mapSpaces[i] = new MineSpace((Position)i, Mine);
                break;
            case (3):
                this->mapSpaces[i] = new DungeonSpace(
                        (Position)i, Dungeon);
                break;
        }
    }
    //set pointers for each space to the other spaces
    for (int i = 0; i < 9; i++){
        this->mapSpaces[i]->setNWSpacePointer(mapSpaces[0]);
        this->mapSpaces[i]->setNSpacePointer(mapSpaces[1]);
        this->mapSpaces[i]->setNESpacePointer(mapSpaces[2]);
        this->mapSpaces[i]->setWSpacePointer(mapSpaces[3]);
        this->mapSpaces[i]->setESpacePointer(mapSpaces[5]);
        this->mapSpaces[i]->setSWSpacePointer(mapSpaces[6]);
        this->mapSpaces[i]->setSSpacePointer(mapSpaces[7]);
        this->mapSpaces[i]->setSESpacePointer(mapSpaces[8]);

    }
}

//This changes the space that the character previously interacted with 
//to another random type
void LandScape::updateMap(Character &character){
    for (int i = 0; i < 9; i++){
            if (mapSpaces[i]->getPosition() 
                    == character.getPosition()){

                Space *spacePtr = nullptr;
                int randValue = rand() % 4;
                switch (randValue){
                case (0):
                    spacePtr = 
                        new DesertSpace(
                                mapSpaces[i]->getPosition(), Desert);
                    break;
                case (1):
                    spacePtr = 
                        new WaterSpace(
                                mapSpaces[i]->getPosition(), Water);
                    break;
                case (2):
                    spacePtr = 
                        new MineSpace(
                                mapSpaces[i]->getPosition(), Mine);
                    break;
                case (3):
                    spacePtr = 
                        new DungeonSpace(
                                mapSpaces[i]->getPosition(), Dungeon);
                    break;
                }
                delete mapSpaces[i];
                mapSpaces[i] = spacePtr;
            }
        }
}

//this checks if the game can continue, or if the game has to end 
//because of items accumulated or energy points lost.
bool LandScape::checkGameStatus(Character &character){
    std::cout << "You have " << character.getEnergyPoints() <<
        " energy points remaining." << std::endl;
    int fishStackSize = character.getFishStackSize();
    int oreStackSize = character.getOreStackSize();
    int skullStackSize = character.getSkullStackSize();
    if (fishStackSize >= 30 || oreStackSize >= 20 ||
            skullStackSize >= 15){
        std::cout << "You have conquered the LandScape!" << std::endl;
        return false;
    }
    else if (character.getEnergyPoints() == 0){
        std::cout << "You have been conquered by the LandScape" 
            << std::endl;
        std::cout << "Try again soon!" << std::endl;
        return false;
    }
    else {
        return true;
    }
}
//this function handles the character interacting with the terrain,
//it calls the space's interaction function which results in the
//player receiving the item or not.
void LandScape::characterTerrainInteraction(Character &character,
        Space *s){
    char *terrainStrings[] = {
        "Desert", 
        "Water",
        "Mine",
        "Dungeon"

    };
    Menu menu;
    char* terrainCurr = terrainStrings[s->getTerrain()];
    std::cout << "The terrain of the current space is: " 
        << terrainCurr 
        << std::endl;
    if (terrainCurr == "Desert"){
        std::cout << "You can only dig in the barren desert, or" 
            << " choose to keep walking. You lose energy either way."
            << std::endl;
    }
    else if (terrainCurr == "Water"){
        std::cout << "You may attempt to catch a fish, or sail across"
            << " the blue expanse."
            <<std::endl;
    }
    else if (terrainCurr == "Mine"){
        std::cout << "You may attempt to mine for precious metal ore "
            << " `ore` continue past the rock outcropping. " 
            << std::endl;
    }
    else {
        std::cout << "You have come across a monster in a dungeon. "
            << "Slay them to earn a skull, or run away in cowardice."
            << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Would you like to interact with this terrain?" 
        << std::endl;
    int userChoice = 0;
    while (userChoice == 0){
    userChoice = menu.promptSingleResponseInt("Press 1 for yes"
            " and any other number for no.");
    }
    if (userChoice == 1){
    //if space interaction function returns true, character stack 
    //is incremented and energy points decremented
    //otherwise energypoints decremented
        if (s->spaceInteraction(character.getPosition())){
            std::cout << std::endl;
            if ((Position)s->getTerrain() == Water){
                std::cout 
                    << "You received a fish, and lost one energy point." 
                    << std::endl;
                character.pushFishStack("fish");
            }
            else if (s->getTerrain() == Desert){
                std::cout 
                    << "You lost one energy point walking through"
                    <<" the desert."
                    << std::endl;}
            else if ((Position)s->getTerrain() == Dungeon){
                std::cout << "You killed an enemy and received " <<
                    "its skull, and lost one energy point." 
                    << std::endl;
                character.pushSkullStack("skull");
            }
            else if ((Position)s->getTerrain() == Mine){
                std::cout 
                    << "You received metal ore and lost one energy point." 
                    << std::endl;
                character.pushOreStack("ore");
            }
            character.setEnergyPoints(character.getEnergyPoints() - 1);
        }
        else{
            std::cout << std::endl;
            std::cout << "You were not able to successfully interact "
                << "with the space. You have lost one energy point."
                << std::endl;
            character.setEnergyPoints(character.getEnergyPoints() - 1);
        }
    }
    else {;}
}
//delete the dynamically allocated spaces
LandScape::~LandScape(){
    for (int i = 0; i < 9; i++){
        delete mapSpaces[i];
    }
}
