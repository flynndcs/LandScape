/*******************************************************************
 * Name:            Daniel Flynn
 * Date:            October 10, 2019
 * Description:     This is the implementation for the Menu class.
 * *******************************************************************/


#include <string>
#include "Menu.hpp"
#include <iostream>
#include <vector>
#include "getInt.hpp"
/*******************************************************************
 * Description:         This function takes a string to be displayed
 *                      the user as a prompt, and then returns the 
 *                      validated input from the user as an integer.
 *                      *******************************************/

int Menu::promptSingleResponseInt(std::string prompt){
    int response = 0;

    std::cout << prompt << std::endl;

    response = getInt();

    return response;
}
/********************************************************************
 * Description:         This function takes a vector of strings
 *                      to be displayed to the user as prompts, and 
 *                      returns the validated input from the user 
 *                      as an integer.
 *                      *********************************************/

int Menu::promptMultipleChoiceInt(std::vector<std::string> prompts){
    int response = 0; 
    
    std::cout << "Choose one of the following:" << std::endl;
    
    for (int i = 0; i < prompts.size(); i++){
        std::cout << prompts[i] << std::endl;
    }

    response = getInt();

    return response;
}

/*********************************************************************
 * Description:         This function takes user input and returns a 
 *                      string.
 *                      ******************************************/

std::string Menu::promptString(){
    std::string response;
    std::getline(std::cin, response);
    return response;
}

