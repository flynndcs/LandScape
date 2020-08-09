/********************************************************************
 * Author:          Daniel Flynn
 * Date:            December 10 2019
 * Description:     This is the interface for the Water space derived 
 *                  class.It includes the override of the virtual 
 *                  function from the Space abstract class as well as
 *                  the constructor for this class which calls the Space
 *                  constructor to initialize the position and terrain
 *                  attributes.
 *                  ************************************************/



#ifndef WATERSPACE_HPP
#define WATERSPACE_HPP

#include "Space.hpp"
#include "LandScapeUtilities.hpp"


class WaterSpace : public Space{
    public:
        virtual bool spaceInteraction(Position p);
        WaterSpace(Position p, Terrain t) : Space(p, t){}
};

#endif
