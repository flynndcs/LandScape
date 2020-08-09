#include "DungeonSpace.hpp"
#include "LandScapeUtilities.hpp"
#include <cstdlib>
#include <cmath>
#include "Space.hpp"

bool DungeonSpace::spaceInteraction(Position p){
    if (rand() % 5 >= 3){
        return true;
    }
    else {
        return false;
    }
}
