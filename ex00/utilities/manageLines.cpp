/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-01/ex00/utilities/manageLines.cpp               *
*                    Creation Date: January 10, 2025 03:57 PM                    *
*                    Last Updated: January 11, 2025 10:47 AM                     *
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
		deleteZombiesMemory();
		exit(EXIT_SUCCESS);
	}
	else if (std::cin.fail()) {
		std::cerr << RED << "ERROR: " << RESET
			<< "An error occurred while reading input." << std::endl;
		sleep(COOLDOWN), erasePreviousLines(1), std::cin.clear(), input = "";
	}
	else
		erasePreviousLines(1);
	return (input);
}

/**
 * @brief Erase the previous `count` lines from the terminal.
 * 
 * This function uses the ANSI escape sequence defined in `ERASE_PREVIOUS_LINE` 
 * to clear the specified number of lines from the terminal output.
 * 
 * @param count The number of lines to erase.
 */
void	erasePreviousLines(const size_t &count) {
	std::string	eraseInstructions = "";

	for (size_t index = 0 ; index < count ; index++)
		eraseInstructions += ERASE_PREVIOUS_LINE;

	std::cout << eraseInstructions << std::flush << MOVE_CURSOR_UP << std::endl;
}