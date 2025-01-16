/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                 File Name: /CPP-01/ex01/utilities/getLines.cpp                 *
*                    Creation Date: January 11, 2025 05:39 PM                    *
*                    Last Updated: January 15, 2025 05:33 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                        Functions for manipulating lines                        *
*********************************************************************************/

#include "./../Zombie.hpp"

/********************************************************************************/

/**
 * @brief Recover a line from standard input and handle EOF or errors gracefully.
 * 
 * This function ensures proper handling of EOF (CTRL-D) and returns a clean string input.
 * 
 * @return std::string: The line read.
 */
std::string	getInputLine(void) {
	std::string	input;
	std::getline(std::cin, input);

	if (std::cin.eof()) {
		std::cout << RED << "\nShutdown: " << RESET << EXIT_MESSAGE << std::endl;
		deleteHordes(NULL);
		exit(EXIT_SUCCESS);
	}
	else if (std::cin.fail()) {
		std::cout << RED << "ERROR: " << RESET
			<< "An error occurred while reading input." << std::endl;
		std::cin.clear(), input = "";
	}
	return (input);
}