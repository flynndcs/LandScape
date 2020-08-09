/********************************************************************
* Author:          Daniel Flynn
* Date:            December 10 2019
* Description:     This is the interface for the Dungeon space derived 
*                  class.It includes the override of the virtual 
*                  function from the Space abstract class as well as
*                  the constructor for this class which calls the Space
*                  constructor to initialize the position and terrain
*                  attributes.
*                  ************************************************/



#ifndef DUNGEONSPACE_HPP
#define DUNGEONSPACE_HPP

#include "Space.hpp"
#include "LandScapeUtilities.hpp"

class DungeonSpace : public Space{
    public:
        virtual bool spaceInteraction(Position p);
        DungeonSpace(Position p, Terrain t) : Space(p, t){}
};

#endif
