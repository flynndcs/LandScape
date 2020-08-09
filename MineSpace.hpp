/********************************************************************
 * Author:          Daniel Flynn
 * Date:            December 10 2019
 * Description:     This is the interface for the Mine space derived 
 *                  class.It includes the override of the virtual 
 *                  function from the Space abstract class as well as
 *                  the constructor for this class which calls the Space
 *                  constructor to initialize the position and terrain
 *                  attributes.
 *                  ************************************************/


#ifndef MINESPACE_HPP
#define MINESPACE_HPP

#include "Space.hpp"
#include "LandScapeUtilities.hpp"

class MineSpace : public Space{
    public:
        virtual bool spaceInteraction(Position p);
        MineSpace(Position p, Terrain t) : Space(p, t){}
};

#endif
