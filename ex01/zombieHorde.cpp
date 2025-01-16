/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                    File Name: /CPP-01/ex01/zombieHorde.cpp                     *
*                    Creation Date: January 13, 2025 02:38 PM                    *
*                    Last Updated: January 15, 2025 10:22 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                                Horde management                                *
*********************************************************************************/

#include "./Zombie.hpp"

/********************************************************************************/

/**
 * @brief create a horde of zombies that follow each other.
 * 
 * @param N the number of zombies in the horde.
 * @param name the name shares zombies.
 * @return Zombie* the first zombie of the horde
 */
Zombie* zombieHorde(int N, std::string name) {
	Zombie	*firstZombie = NULL;
	Zombie	*currentZombie = NULL;
	
	for (int index = 0 ; index < N ; index++) {
		if (!index) {
			firstZombie = newZombie(name);
			currentZombie = firstZombie;
		}
		else {
			currentZombie->addFollower(newZombie(name));
			currentZombie = currentZombie->getFollower();
		}
		currentZombie->addFollower(NULL);
	}
	return (firstZombie);
}

/**
 * @brief deletes (or initializes the save of) the horde.
 * 
 * @param context if specified, backup, otherwise, forces deletion.
 */
void	deleteHordes(zombieMemory *context) {
	static zombieMemory	*zombieMemory = NULL;

	if (zombieMemory) {
		for (size_t index = 0 ; zombieMemory->leaders[index] and index < MAX_HORDES ; index++) {
			Zombie	*currentZombie = zombieMemory->leaders[index];
			while (currentZombie) {
				Zombie	*nextZombie = currentZombie->getFollower();
				delete currentZombie;
				currentZombie = nextZombie;
			}
		}
		delete zombieMemory;
	}
	zombieMemory = context;
}