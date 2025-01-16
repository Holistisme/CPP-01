/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-01/ex00/Zombie.cpp                       *
*                    Creation Date: January 10, 2025 12:37 AM                    *
*                    Last Updated: January 15, 2025 05:31 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                        The source of all deadly action                         *
*********************************************************************************/

#include "./Zombie.hpp"

/********************************************************************************/

/**
 * @brief Construct a new Zombie object.
 * 
 * @param firstName the name to give to the zombie.
 * @param allocated if the zombie is allocated, allows you to track its memory.
 */
Zombie::Zombie(const std::string &firstName, const bool &allocated) {
	if (allocated)
		savedList[zombiesCount++] = this;
	name = firstName;
	setZombieColor();
	announce();
}

/**
 * @brief Destroy the Zombie object.
 * 
 */
Zombie::~Zombie(void) {
	static const std::string	gasps[] = {"Huhhhh...", "Urrrrgh...", "Whaaaat?!", "Braaaaahh..."};

	std::cout << getColoredName() << RESET << ": " << gasps[rand() % 4] << std::endl;
	sleep(INTERACTION / 2), erasePreviousLines(1);
}

/********************************************************************************/

/**
 * @brief Assesses the name and color for display.
 * 
 * @return std::string The sum of the colorful name.
 */
std::string	Zombie::getColoredName(void) {
	return ((!color.empty() ? color : BRIGHT_GREEN)
		+ (!name.empty() ? name : "An unknown zombie"));
}

/********************************************************************************/

/**
 * @brief The zombie interactively announces itself.
 * 
 */
void	Zombie::announce(void) {
	std::cout << getColoredName() << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
	sleep(INTERACTION), erasePreviousLines(1);
}

/**
 * @brief Asks the user if they want to assign a color to the zombie.
 * 
 */
void	Zombie::setZombieColor() {
	static const std::string	availableColors[]	= { "black", "red", "green", "yellow", "blue", "magenta", "cyan", "white" };
	static const std::string	colorCodes[]		= { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

	std::cout << "🖌 - You can give a color to " << getColoredName() << RESET
		<< "! Specify one if you want, or leave the field empty!" << std::endl;

	while (forever) {
		std::string	input;
		trimSpaces(input = getInputLine(), false);

		for (index i = 0 ; i < 8 ; i++) {
			if (equivalentString(input, availableColors[i])) {
				color = colorCodes[i];
				erasePreviousLines(1);
				return;
			}
		}

		if (input.empty()) {
			color = "";
			erasePreviousLines(1);
			return;
		}
		else {
			index	randomI = rand() % 8;

			std::cout << '"' << YELLOW << input << RESET <<  '"' << RED << " is not a valid input" << RESET
				<< "! Try something like: " << colorCodes[randomI] << availableColors[randomI] << RESET << '!' << std::endl;
			sleep(COOLDOWN), erasePreviousLines(1);
		}
	}
}

/**
 * @brief Deletes all registered zombie allocations.
 * 
 */
void	deleteZombiesMemory() {
	for (size_t index = 0 ; index < zombiesCount ; index++) {
		delete savedList[index];
		savedList[index] = NULL;
	}
}