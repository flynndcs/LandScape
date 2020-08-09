/********************************************************************
 * Author:          Daniel Flynn
 * Date:            December 10 2019
 * Description:     This is the interface for the Desert space derived 
 *                  class.It includes the override of the virtual 
 *                  function from the Space abstract class as well as
 *                  the constructor for this class which calls the Space
 *                  constructor to initialize the position and terrain
 *                  attributes.
 *                  ************************************************/

#ifndef DESERTSPACE_HPP
#define DESERTSPACE_HPP

#include "Space.hpp"
#include "LandScapeUtilities.hpp"

class DesertSpace : public Space{
    public:
        virtual bool spaceInteraction(Position p){return false;}
        DesertSpace(Position p, Terrain t) : Space(p, t){}
};

#endif
