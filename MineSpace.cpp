#include "MineSpace.hpp"
#include "LandScapeUtilities.hpp"
#include <cstdlib>
#include <cmath>
#include "Space.hpp"

bool MineSpace::spaceInteraction(Position p){
    if (rand() % 2 == 1){
        return true;
    }
    else {
        return false;
    }
}
