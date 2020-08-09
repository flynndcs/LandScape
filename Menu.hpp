/********************************************************************
 * Author:          Daniel Flynn
 * Date:            October 10, 2019
 * Description:     This is the interface for the Menu class.
 * *****************************************************************/

#include <string>
#include <vector>

#ifndef MENU_HPP
#define MENU_HPP

class Menu{
    public:
        int promptSingleResponseInt(std::string prompt);
        int promptMultipleChoiceInt(std::vector<std::string> prompts);
        std::string promptString();
};
#endif
