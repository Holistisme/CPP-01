/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                    File Name: /CPP-01/ex01/handleSigInt.cpp                    *
*                    Creation Date: January 11, 2025 05:39 PM                    *
*                    Last Updated: January 11, 2025 05:40 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                      SIGINT management to avoid problems                       *
*********************************************************************************/

#include "./Zombie.hpp"

/********************************************************************************/

/**
 * @brief Handles the SIGINT signal (CTRL-C) for a clean program shutdown.
 *
 * This function is set as the handler for SIGINT using std::signal.
 * When CTRL-C is pressed, it cleans up resources and exits the program.
 *
 * @param signal The signal received (expected '!SIGINT' for initialization).
 */
void	handleSigInt(int signal) {
	if (signal == SIGINT) {
		std::cout << ERASE_LINE << BG_RED << "CTRL-C:" << RESET 
			<< RED << " shutdown program!" << RESET << std::endl;
		deleteHordes(NULL);
		exit(EXIT_SUCCESS);
	}
	std::signal(SIGINT, handleSigInt);
}