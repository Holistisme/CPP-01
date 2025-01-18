/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-01/ex01/Zombie.hpp                       *
*                    Creation Date: January 10, 2025 12:37 AM                    *
*                    Last Updated: January 16, 2025 11:42 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                           The zombie knowledge base                            *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include "./output.hpp"

#include <csignal>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include <sstream>

/********************************************************************************/

typedef int	index;

/********************************************************************************/

#define forever			true

#define MAX_ZOMBIES		42
#define MAX_HORDES		42

#define INTERACTION		2
#define COOLDOWN		3

#define EXIT_MESSAGE	"🧟 Thank you for testing " GREEN "More Brainz!" RESET "! 🧟\n"

#define SIGNAL			'\033'

/********************************************************************************/

class	Zombie {
	private:
		std::string	name;
		Zombie		*nextZombie;
		void		announce(void); 
	public:
		Zombie(const std::string &firstName);
		~Zombie();

		std::string	getName(void);
		void		addFollower(Zombie *follower);
		Zombie		*getFollower(void);
		void		saySomething(const index &i);
};

typedef struct	zombieMemory {
	Zombie		*leaders[MAX_HORDES];
	size_t		count;
}				zombieMemory;

/********************************************************************************/

int	main(void);

bool		confirmAction(void);
bool		equivalentString(const std::string &first, const std::string &second);
std::string	getInputLine(void);
void		trimSpaces(std::string &string, const bool &isZombieName);

void		handleSigInt(int signal);

Zombie*		newZombie(std::string name);
Zombie* 	zombieHorde(int N, std::string name);
void		deleteHordes(zombieMemory *context);