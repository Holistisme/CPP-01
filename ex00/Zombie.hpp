#pragma once

#include <csignal>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sstream>

#include "./output.hpp"

#define forever			true

#define MAX_ZOMBIES		42

#define EXIT_MESSAGE	"🧟 Thank you for testing " GREEN "BraiiiiiiinnnzzzZ" RESET "! 🧟\n"

typedef int	index;

#define INTERACTION	2.5
#define COOLDOWN	3

int	main(void);

void		deleteZombiesMemory(void);

bool		confirmAction(void);

bool		equivalentString(const std::string &first, const std::string &second);

std::string	getInputLine(void);
void		erasePreviousLines(const size_t &count);

void		trimSpaces(std::string &string, const bool &isZombieName);

void		handleSigInt(int signal);

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