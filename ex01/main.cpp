/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-01/ex00/main.cpp                        *
*                    Creation Date: January 10, 2025 12:36 AM                    *
*                    Last Updated: January 15, 2025 10:23 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                                Test the zombies                                *
*********************************************************************************/

#include "./Zombie.hpp"

/********************************************************************************/

static inline int			setHordeSize();
static inline std::string	setHordeName();
static inline void			everybodySaysSomething(Zombie *leader);

/********************************************************************************/

/**
 * @brief The test program.
 *
 * @return int: Exits the program gracefully when requested.
 */
int	main(void) {
	try {
		zombieMemory	*programMemory = new zombieMemory;
		programMemory->count = 0;
		for (index i = 0 ; i < MAX_HORDES ; i++)
			programMemory->leaders[i] = NULL;
		deleteHordes(programMemory); // In order to save the structure from everywhere.

		handleSigInt(!SIGINT);
		std::srand(0);

		std::cout << std::endl <<"🧟 " << GREEN <<  "Moar brainz!" << RESET << " 🧟\n" << std::endl;
		while (forever) {
			std::string	newName = setHordeName();
			if (newName.find(SIGNAL) != std::string::npos) {
				std::cout << ERROR << "Zombies refuse to carry signals!\n" << RESET << std::endl;
				continue;
			}
			std::cout << std::endl;

			int	hordeMembers = setHordeSize();
			if (!hordeMembers)
				continue;
			std::cout << std::endl;

			if (hordeMembers) {
				programMemory->leaders[programMemory->count] = zombieHorde(hordeMembers, newName);
				everybodySaysSomething(programMemory->leaders[programMemory->count++]);
			}

			std::cout << BG_BRIGHT_YELLOW << "\n⛐  - It's time to choose if you want to escape the hordes!" << RESET << std::endl;
			if (confirmAction() or programMemory->count == MAX_HORDES) {
				if (programMemory->count == MAX_HORDES)
					std::cout << ERASE_PREVIOUS_LINE << "It's not up to you, there are too many hordes, get out!" << std::endl;
				std::cout << std::endl;
				deleteHordes(NULL);
				std::cout << '\n' << EXIT_MESSAGE << std::endl;
				exit(EXIT_SUCCESS);
			}
			else
				std::cout << std::endl;
		}
	}
	catch (const std::bad_alloc& e) {
		std::cout << BG_RED << "ERROR:" << RESET
			" Memory allocation failed: "
			<< RED << e.what() << RESET << std::endl;
		deleteHordes(NULL);
		exit(EXIT_FAILURE);
	}
	catch (const std::exception& e) {
		std::cout << BG_RED << "ERROR:" << RESET
			" Unhandled exception: "
			<< RED << e.what() << RESET << std::endl;
		deleteHordes(NULL);
		exit(EXIT_FAILURE);
	}
	catch (...) {
		std::cout << BG_RED << "ERROR:" << RESET
			" Unknown exception occurred." << std::endl;
		deleteHordes(NULL);
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief forces all zombies to speak once.
 * 
 * @param leader the first zombie of the horde.
 */
static inline void	everybodySaysSomething(Zombie *leader) {
	Zombie	*current = leader;
	index	number = 1;

	std::cout << std::endl;
	while (current) {
		current->saySomething(number++);
		current = current->getFollower();
	}
}

/**
 * @brief Set the new horde size.
 * 
 * @return int the size of the new horde.
 */
static inline int	setHordeSize() {
	std::cout << BG_GREEN << "🧟🧟🧟 - How many zombies do you want in this horde (up to 42)?" << RESET << std::endl;

	std::string	input = getInputLine();
	char		*conversionReturn;

	int	hordeSize = strtol(input.c_str(), &conversionReturn, 10);
	if (*conversionReturn)
		std::cout << ERROR << "The number of zombies is invalid, even if they don't have many neurons anymore, they still know how to recognize numbers!\n" << RESET << std::endl;
	else if (hordeSize > MAX_ZOMBIES)
		std::cout << ERROR << "The number of zombies is too high, they started to eat each other!\n" << RESET << std::endl;
	else if (hordeSize <= 0)
		std::cout << ERROR << "The good thing about not having the IQ to put a positive number is that no zombie will take the risk of losing intellectual capacity by eating you!\n" << RESET << std::endl;
	else
		return (hordeSize);
	return (0);
}

/**
 * @brief Set the new horde name.
 * 
 * @return std::string the name of the horde after user input.
 */
static inline std::string	setHordeName() {
	std::cout << BG_GREEN << "🗛  - What name do you want to give to all these beautiful little cute zombies?" << RESET << std::endl;

	std::string	input = getInputLine();
	trimSpaces(input, true);

	return (input);
}