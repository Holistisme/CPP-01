/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                    File Name: /CPP-01/ex00/randomChump.cpp                     *
*                    Creation Date: January 10, 2025 12:37 AM                    *
*                    Last Updated: January 11, 2025 05:12 PM                     *
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
void	Zombie::randomChump(std::string name) {
	erasePreviousLines(1);

	Zombie	chump;
	chump.name = name;
	chump.setZombieColor();
	chump.announce();
	chump.canDie = true;

	std::cout << "Sorry " << chump.getColoredName() << RESET
		<< ", but your existence ends here!" << std::endl;
	sleep(INTERACTION), erasePreviousLines(1);
}