/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                    File Name: /CPP-01/ex01/zombieHorde.cpp                     *
*                    Creation Date: January 13, 2025 02:38 PM                    *
*                    Last Updated: January 21, 2025 08:13 AM                     *
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
	Zombie *horde = new Zombie[N];
	deleteHordes(&horde); // In order to be able to delete it from anywhere in the event of a problem.
	for (int n = 0 ; n < N ; n++)
		horde[n].setName(name);
	return (horde);
}

/**
 * @brief deletes (or initializes the save of) the horde.
 * 
 * @param context if specified, backup, otherwise, forces deletion.
 */
void	deleteHordes(Zombie **context) {
	static Zombie	*zombieMemory = NULL;

	if (zombieMemory) {
		delete[] zombieMemory;
		zombieMemory = NULL;
	}
	else if (context)
		zombieMemory = *context;
}