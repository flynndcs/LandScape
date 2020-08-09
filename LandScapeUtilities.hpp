/******************************************************************
 * Author:          Daniel Flynn
 * Date:            December 10 2019
 * Description:     This defines two enums which help with positions
 *                  and terrain throughout gameplay.
 *                  *************************************************/

#ifndef LANDSCAPEUTILITIES_HPP
#define LANDSCAPEUTILITIES_HPP

enum Position {
    Northwest, North, Northeast,
    West, Center, East,
    Southwest, South, Southeast
};

enum Terrain {Desert, Water, Mine, Dungeon};

#endif
