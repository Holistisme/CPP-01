/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-01/ex00/Zombie.hpp                       *
*                    Creation Date: January 10, 2025 12:37 AM                    *
*                    Last Updated: January 11, 2025 05:34 PM                     *
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

#define INTERACTION		2.5
#define COOLDOWN		3

#define EXIT_MESSAGE	"🧟 Thank you for testing " GREEN "BraiiiiiiinnnzzzZ" RESET "! 🧟\n"

/********************************************************************************/

int	main(void);

bool		confirmAction(void);
bool		equivalentString(const std::string &first, const std::string &second);
std::string	getInputLine(void);
void		erasePreviousLines(const size_t &count);
void		trimSpaces(std::string &string, const bool &isZombieName);

void		handleSigInt(int signal);

void		deleteZombiesMemory(void);

/********************************************************************************/

class	Zombie {
	private:
		std::string	name;
		std::string	color;
		bool		canDie;
		void		announce(void); 
	public:
		std::string	getColoredName(void);
		Zombie() : name(""), color(""), canDie(false) {}
		~Zombie();
		Zombie*	newZombie(std::string name);
		void	setZombieColor();
		void	randomChump(std::string name);
};

extern Zombie	*savedList[MAX_ZOMBIES];
extern size_t	zombiesCount;