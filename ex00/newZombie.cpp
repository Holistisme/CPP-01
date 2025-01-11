/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                     File Name: /CPP-01/ex00/newZombie.cpp                      *
*                    Creation Date: January 10, 2025 12:37 AM                    *
*                    Last Updated: January 11, 2025 11:52 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                           Allocated zombie creation                            *
*********************************************************************************/

#include "./Zombie.hpp"

/********************************************************************************/

// void* operator new(std::size_t size) {
// 	(void)size;
// 	std::cout << "HERE" << std::endl;
//     throw std::bad_alloc(); // Simule toujours un échec d'allocation
// 	// std::cout << "HERE" << std::endl;
// }

/**
 * @brief Create a new zombie allocated dynamically.
 * 
 * @param name The name to give to the zombie.
 * @return Zombie* A pointer to the newly created zombie.
 */
Zombie*	Zombie::newZombie(std::string name) {
	if (zombiesCount >= MAX_ZOMBIES) {
		std::cerr << BG_RED << "ERROR:" << RESET
			<< RED << " it is not possible to create more than " << RESET
			<< YELLOW << MAX_ZOMBIES << RESET
			<< " zombies!" << std::endl;
		return NULL;
	}

	Zombie *newAllocatedZombie = savedList[zombiesCount] = new Zombie;

	newAllocatedZombie = savedList[zombiesCount++];
	erasePreviousLines(1);
	newAllocatedZombie->name = name;
	newAllocatedZombie->setZombieColor();
	newAllocatedZombie->announce();
	newAllocatedZombie->canDie = true;
	return savedList[zombiesCount];
}