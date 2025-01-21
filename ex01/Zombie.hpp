/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-01/ex01/Zombie.hpp                       *
*                    Creation Date: January 10, 2025 12:37 AM                    *
*                    Last Updated: January 21, 2025 08:13 AM                     *
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
		void		announce(void); 
	public:
		~Zombie();

		void		setName(const std::string &firstName);
		std::string	getName(void);
		void		saySomething(const index &i);
};

/********************************************************************************/

int	main(void);

bool		confirmAction(void);
bool		equivalentString(const std::string &first, const std::string &second);
std::string	getInputLine(void);
void		trimSpaces(std::string &string, const bool &isZombieName);

void		handleSigInt(int signal);

Zombie* 	zombieHorde(int N, std::string name);
void		deleteHordes(Zombie **context);