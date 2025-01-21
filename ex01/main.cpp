/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-01/ex00/main.cpp                        *
*                    Creation Date: January 10, 2025 12:36 AM                    *
*                    Last Updated: January 21, 2025 08:13 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                                Test the zombies                                *
*********************************************************************************/

#include "./Zombie.hpp"

/********************************************************************************/

static inline int			setHordeSize();
static inline std::string	setHordeName();
static inline void			everybodySaysSomething(Zombie *horde, const size_t &zombieCount);

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

		std::cout << std::endl <<"🧟 " << GREEN <<  "Moar brainz!" << RESET << " 🧟\n" << std::endl;
		while (forever) {
			Zombie	*horde = NULL;
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
				horde = zombieHorde(hordeMembers, newName);
				everybodySaysSomething(horde, hordeMembers);
			}

			std::cout << std::endl;
			deleteHordes(NULL);
			std::cout << '\n' << BG_BRIGHT_YELLOW << "⛐  - It's time to choose if you want to recreate a horde!" << RESET << std::endl;
			if (!confirmAction()) {
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
static inline void	everybodySaysSomething(Zombie *horde, const size_t &zombieCount) {
	std::cout << std::endl;
	for (size_t index = 0 ; index < zombieCount ; index++)
		horde[index].saySomething(index + 1);
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