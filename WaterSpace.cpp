#include "WaterSpace.hpp"
#include "LandScapeUtilities.hpp"
#include <cstdlib>
#include <cmath>
#include "Space.hpp"

bool WaterSpace::spaceInteraction(Position p){
    if (rand() % 3 == 1 ){
        return true;
    }
    else {
        return false;
    }
}
