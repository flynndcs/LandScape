/********************************************************************
 * Author:          Daniel Flynn
 * Date:            December 10 2019
 * Description:     This is the absstract Space class. It includes the 
 *                  position and terrain attributes for each space,
 *                  as well as pointers that link to the other spaces
 *                  on the map. It includes getter and setter functions
 *                  as well as the virtual interaction function
 *                  that is overriden and used by the derived classes.
 *                  *************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

//class data members:
//x coordinate, y coordinate
//pointers to 8 other spaces
//class functions:
//reinitialize
//character interaction
//
#include "LandScapeUtilities.hpp"
class Space{
    private:
        Position position;
        Terrain terrain;
        Space *NWSpacePointer; 
        Space *NSpacePointer;
        Space *NESpacePointer;
        Space *ESpacePointer;
        Space *SESpacePointer;
        Space *SSpacePointer;
        Space *SWSpacePointer;
        Space *WSpacePointer;

    public:
        Space(Position p){ position = p; }
        Space (Position p, Terrain t){
            position = p;
            terrain = t;
        }

        void setPosition(Position p){position = p;}
        void setTerrain(Terrain t){terrain = t; }

        Position getPosition(){return position;}
        Terrain getTerrain(){return terrain;}

        Space *getNWSpacePointer(){return NWSpacePointer;}
        Space *getNSpacePointer(){return NSpacePointer;}
        Space *getNESpacePointer(){return NESpacePointer;}
        Space *getESpacePointer(){return ESpacePointer;}
        Space *getSESpacePointer(){return SESpacePointer;}
        Space *getSSpacePointer(){return SSpacePointer;}
        Space *getSWSpacePointer(){return SWSpacePointer;}
        Space *getWSpacePointer(){return WSpacePointer;}

        void setNWSpacePointer(Space *ptr){NWSpacePointer = ptr;}
        void setNSpacePointer(Space *ptr){NSpacePointer = ptr;}
        void setNESpacePointer(Space *ptr){NESpacePointer = ptr;}
        void setESpacePointer(Space *ptr){ESpacePointer = ptr;}
        void setSESpacePointer(Space *ptr){SESpacePointer = ptr;}
        void setSSpacePointer(Space *ptr){SSpacePointer = ptr;}
        void setSWSpacePointer(Space *ptr){SWSpacePointer = ptr;}
        void setWSpacePointer(Space *ptr){WSpacePointer = ptr;}

        virtual bool spaceInteraction(Position p) = 0;
};

#endif
