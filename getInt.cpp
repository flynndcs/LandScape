/******************************************************************
 * Author:          Daniel Flynn/Jonas Groger
 * Date:            October 10, 2019
 * Description:     This is the getInt validation function, which 
 *                  the type of user-entered value is an integer.
 *                  Adapted from 11/11/2014 Stack Overflow post.
 *                  **********************************************/

#include <iostream>
#include <string>
#include <sstream>
int getInt(){
    // runs infinitely until return
        std::cout 
            << "Enter a whole number." 
            << std::endl;
        std::string line;
        int convertedInt;

        while (std::getline(std::cin, line)){
            std::stringstream ss(line);
            if (ss >> convertedInt){
                if (ss.eof()){
                    ss.str("");
                    break;
                }
            }
            std::cout << "Invalid integer" << std::endl;
        }
        return convertedInt;
}
