/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                     File Name: /CPP-01/ex00/newZombie.cpp                      *
*                    Creation Date: January 10, 2025 12:37 AM                    *
*                    Last Updated: January 15, 2025 03:04 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                           Allocated zombie creation                            *
*********************************************************************************/

#include "./Zombie.hpp"

/********************************************************************************/

/**
 * @brief Create a new zombie allocated dynamically.
 * 
 * @param name The name to give to the zombie.
 * @return Zombie* A pointer to the newly created zombie.
 */
Zombie*	newZombie(std::string name) {
	erasePreviousLines(1);

	if (zombiesCount >= MAX_ZOMBIES) {
		std::cout << BG_RED << "ERROR:" << RESET
			<< RED << " it should not be possible to create more than " << RESET
			<< YELLOW << MAX_ZOMBIES << RESET
			<< RED << " zombies!" << RESET << std::endl;
		deleteZombiesMemory();
		exit(EXIT_FAILURE);
	}

	return new Zombie(name, true);
}