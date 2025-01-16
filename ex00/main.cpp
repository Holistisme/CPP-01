/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-01/ex00/main.cpp                        *
*                    Creation Date: January 10, 2025 12:36 AM                    *
*                    Last Updated: January 15, 2025 05:30 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                                Test the zombies                                *
*********************************************************************************/

#include "./Zombie.hpp"

/********************************************************************************/

static inline void	displayChoices(void);
static inline void	makeChoice(std::string &input);

/********************************************************************************/

Zombie	*savedList[MAX_ZOMBIES]	= { NULL };
size_t	zombiesCount			= 0;

/********************************************************************************/

/**
 * @brief The test program.
 *
 * @return int: Exits the program gracefully when requested.
 */
int	main(void) {
	try {
		handleSigInt(!SIGINT);
		std::srand(0);

		std::cout << std::endl <<"🧟 " << GREEN <<  "BraiiiiiiinnnzzzZ" << RESET << " 🧟\n" << std::endl;
		while (forever) {
			displayChoices();
			std::string	input;
			trimSpaces(input = getInputLine(), false);
			erasePreviousLines(4);
			makeChoice(input);
		}
	}
	catch (const std::bad_alloc& e) {
		std::cout << BG_RED << "ERROR:" << RESET
			" Memory allocation failed: "
			<< RED << e.what() << RESET << std::endl;
		deleteZombiesMemory();
		exit(EXIT_FAILURE);
	}
	catch (const std::exception& e) {
		std::cout << BG_RED << "ERROR:" << RESET
			" Unhandled exception: "
			<< RED << e.what() << RESET << std::endl;
		deleteZombiesMemory();
		exit(EXIT_FAILURE);
	}
	catch (...) {
		std::cout << BG_RED << "ERROR:" << RESET
			" Unknown exception occurred." << std::endl;
		deleteZombiesMemory();
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief Displays possible choices to the user.
 */
static inline void	displayChoices(void) {
	std::cout << BG_BLACK << "Choose an action to perform:" << RESET << std::endl
		<< "🕇 - To create a zombie on the stack " << YELLOW << "(without memory allocation)" << RESET
			<< ':' << BLUE << " chump" << RESET << std::endl
		<< "🕆 - To create a zombie on the heap " << GREEN << "(with memory allocation)" << RESET
			<< ':' << BLUE " new" << RESET << std::endl
		<< "🗴 - To end the program: " << RED << "exit" << RESET << std::endl;
}

/**
 * @brief Redirects the user's choice to the appropriate action.
 *
 * @param input: The order of the user.
 */
static inline void	makeChoice(std::string &input) {
	Zombie		*currentZombie = NULL;
	std::string	zombieName;

	if (equivalentString(input, "NEW")) {
		std::cout << "🕱 - A name for your new" << GREEN << " allocated " << RESET << "zombie?" << std::endl;
		trimSpaces(zombieName = getInputLine(), true);
		if (zombieName.find(SIGNAL) != std::string::npos) {
			std::cout << ERROR << "Zombies refuse to carry signals!" << RESET << std::endl;
			sleep(COOLDOWN), erasePreviousLines(2);
			return;
		}
		currentZombie = newZombie(zombieName);
		std::cout << "Well done " << currentZombie->getColoredName() << RESET
			<< ", you have been able to get out of your allocation function!" << std::endl;
		sleep(INTERACTION), erasePreviousLines(1);
	}
	else if (equivalentString(input, "CHUMP")) {
		std::cout << "🕱 - A name for your new" << YELLOW << " unallocated " << RESET << "zombie?" << std::endl;
		trimSpaces(zombieName = getInputLine(), true);
		if (zombieName.find(SIGNAL) != std::string::npos) {
			std::cout << ERROR << "Zombies refuse to carry signals!" << RESET << std::endl;
			sleep(COOLDOWN), erasePreviousLines(2);
			return;
		}
		randomChump(zombieName);
	}
	if (equivalentString(input, "EXIT") or zombiesCount == MAX_ZOMBIES) {
		erasePreviousLines(2);
		if (zombiesCount == MAX_ZOMBIES)
			std::cout << BG_GREEN << "🧟 There are too many zombies! They start to eat the program! 🧟\n" << std::endl;
		else
			std::cout << EXIT_MESSAGE << std::endl;
		deleteZombiesMemory();
		exit(EXIT_SUCCESS);
	}
}