/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                    File Name: /CPP-01/ex00/randomChump.cpp                     *
*                    Creation Date: January 10, 2025 12:37 AM                    *
*                    Last Updated: January 15, 2025 03:05 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                           To generate a poor zombie                            *
*********************************************************************************/

#include "./Zombie.hpp"

/********************************************************************************/

/**
 * @brief Creates a zombie without allocation.
 * 
 * @param name The name of this poor zombie has the limited lifespan.
 */
void	randomChump(std::string name) {
	erasePreviousLines(1);

	Zombie	chump(name, false);

	std::cout << "Sorry " << chump.getColoredName() << RESET
		<< ", but your existence ends here!" << std::endl;
	sleep(INTERACTION), erasePreviousLines(1);
}