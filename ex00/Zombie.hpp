/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-01/ex00/Zombie.hpp                       *
*                    Creation Date: January 13, 2025 01:41 PM                    *
*                    Last Updated: January 15, 2025 05:31 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                           The zombie knowledge base                            *
*********************************************************************************/

#pragma once

#include "./output.hpp"

/********************************************************************************/

#include <csignal>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sstream>

/********************************************************************************/

typedef int	index;

/********************************************************************************/

#define forever			true

#define MAX_ZOMBIES		42

#define INTERACTION		3
#define COOLDOWN		3

#define EXIT_MESSAGE	"🧟 Thank you for testing " GREEN "BraiiiiiiinnnzzzZ" RESET "! 🧟\n"

#define SIGNAL			'\033'

/********************************************************************************/

class	Zombie {
	private:
		std::string	name;
		std::string	color;
		void		announce(void); 
	public:
		Zombie(const std::string &name, const bool &allocated);
		~Zombie(void);

		std::string	getColoredName(void);
		void		setZombieColor(void);
};

extern Zombie	*savedList[MAX_ZOMBIES];
extern size_t	zombiesCount;

/********************************************************************************/

int	main(void);

bool		confirmAction(void);
bool		equivalentString(const std::string &first, const std::string &second);
std::string	getInputLine(void);
void		erasePreviousLines(const size_t &count);
void		trimSpaces(std::string &string, const bool &isZombieName);

void		handleSigInt(int signal);

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

void		deleteZombiesMemory(void);