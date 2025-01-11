#include "./Zombie.hpp"

Zombie::~Zombie() {
	if (canDie) {
		std::string	gasps[] = {"Huhhhh...", "Urrrrgh...", "Whaaaat?!", "Braaaaahh..."};
		std::cout << getColoredName() << RESET << ": " << gasps[rand() % 4] << std::endl;
		sleep(INTERACTION / 2), erasePreviousLines(1);
	}
}

void	Zombie::announce(void) {
	std::cout << getColoredName() << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
	sleep(INTERACTION), erasePreviousLines(1);
}

std::string	Zombie::getColoredName(void) {
	std::string	coloredName = "";

	coloredName = !color.empty() ? color : BRIGHT_GREEN;
	coloredName += !name.empty() ? name : "An unknown zombie";
	return coloredName;
}

void	Zombie::setZombieColor() {
	std::string	availableColors[]	= { "black", "red", "green", "yellow", "blue", "magenta", "cyan", "white" };
	std::string	colorCodes[]		= { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

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

			std::cerr << '"' << YELLOW << input << RESET <<  '"' << RED << " is not a valid input" << RESET
				<< "! Try something like: " << colorCodes[randomI] << availableColors[randomI] << RESET << '!' << std::endl;
			sleep(COOLDOWN), erasePreviousLines(1);
		}
	}
}

void	deleteZombiesMemory() {
	for (size_t index = 0 ; index < zombiesCount ; index++)
		delete savedList[index];
}