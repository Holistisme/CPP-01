/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-01/ex03/main.cpp                        *
*                    Creation Date: January 16, 2025 11:47 AM                    *
*                    Last Updated: January 24, 2025 11:11 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                              Main test functions                               *
*********************************************************************************/

#include "./main.hpp"

#include "./HumanA/HumanA.hpp"
#include "./HumanB/HumanB.hpp"

/********************************************************************************/

static inline void	makeChoice(std::string input);
static inline void	play(void);
static inline void	humanInteraction(HumanA &HumanA, HumanB &HumanB, const char &protagonist);

/********************************************************************************/

/**
 * @brief Test program to spread violence.
 * 
 * @return int the status of success or failure.
 */
int main(void) {
	try {
		std::cout << "\n⚔ It's time to play with " << BG_BRIGHT_RED <<  "violence" << RESET << "! ⚔\n" << std::endl;
		std::srand(std::time(0));

		while (forever) {
			std::cout << "🏹 - " << GREEN << "PLAY" << RESET << ": to start making two guys hit!" << std::endl;
			std::cout << "🗶  - " << RED << "EXIT" << RESET << ": to leave because you're too cowardly to fight!" << std::endl;
			makeChoice(getInputLine());
		}
	} catch (...) {
		std::cout << ERROR << "an unexpected error has occurred!" << RESET << std::endl;
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief Reacts to the choice made by the user to instruct the program.
 * 
 * @param input user input.
 */
static inline void	makeChoice(std::string input) {
	trimSpaces(input, false);
	erasePreviousLines(2);

	if (equivalentString(input, "PLAY"))
		play();
	else if (equivalentString(input, "EXIT")) {
		erasePreviousLines(2);
		std::cout << EXIT_MESSAGE << '\n' << std::endl;
		exit(EXIT_SUCCESS);
	}
	else {
		std::cout << ERROR << "Like the barbarians who play video games, you have neither intelligence nor wisdom!" << RESET << std::endl;
		sleep(COOLDOWN), erasePreviousLines(1);
	}
}

/**
 * @brief Initiate two humans for a duel in which the user is guilty!
 * 
 */
static inline void	play(void) {
	HumanA	blueHuman = setHumanA();
	HumanB	redHuman  = setHumanB();

	std::cout << BG_BLUE << blueHuman.getName() << RESET
		<< " and " << BG_RED << redHuman.getName() << RESET
		<< " are face to face, ready to kill each other!\n" << std::endl;

	while (forever) {
		std::cout << "🔵 - " << BLUE << "BLUE" << RESET << " to control the blue human!" << std::endl;
		std::cout << "🔴 - " << RED << "RED" << RESET << " to control the red human!" << std::endl;
		std::cout << "🕊  - " << READABLE_BG_BRIGHT_WHITE << "END" << RESET << " to end the battle!" << std::endl;

		std::string	input;
		input = getInputLine();
		trimSpaces(input, false);
		erasePreviousLines(3);

		if (equivalentString(input, "BLUE"))
			humanInteraction(blueHuman, redHuman, 'A');
		else if (equivalentString(input, "RED"))
			humanInteraction(blueHuman, redHuman, 'B');
		else if (equivalentString(input, "END"))
			break;
	}
	erasePreviousLines(2);

	std::cout << "🔥 End of the Fight! 🔥" << std::endl;
	sleep(INTERACTION), erasePreviousLines(1);
	if ((equivalentString(blueHuman.getName(), "RICK") or equivalentString(blueHuman.getName(), "ASTLEY"))
		and (equivalentString(redHuman.getName(), "RICK") or equivalentString(redHuman.getName(), "ASTLEY"))
		and !equivalentString(blueHuman.getName(), redHuman.getName())) {
		#ifdef __linux__
			system("xdg-open https://www.youtube.com/watch?v=dQw4w9WgXcQ > /dev/null 2>&1");
		#elif _WIN32
			system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ > nul 2>&1");
		#elif __APPLE__
			system("open https://www.youtube.com/watch?v=dQw4w9WgXcQ > /dev/null 2>&1");
		#endif
	}
	if (blueHuman.getDamage() > redHuman.getDamage())
		std::cout << "🔵 Blue Victory! 🔵" << std::endl;
	else if (blueHuman.getDamage() == redHuman.getDamage())
		std::cout << "⚐ White Flag! ⚐" << std::endl;
	else
		std::cout << "🔴 Red Victory! 🔴" << std::endl;
	sleep(INTERACTION), erasePreviousLines(1);
}

/**
 * @brief interaction of humans with each other at the will of the user.
 * 
 * @param HumanA the type A human previously initiated.
 * @param HumanB the type B human previously initiated.
 * @param protagonist the type of human chosen to act.
 */
static inline void	humanInteraction(HumanA &HumanA, HumanB &HumanB, const char &protagonist) {
	if (protagonist == 'A')
		std::cout << "You control " << (protagonist == 'A' ? BG_BLUE : BG_RED)
			<< (protagonist == 'A' ? HumanA.getName() : HumanB.getName()) << RESET << ":\n" << std::endl;
	else
		std::cout << "You control " << BG_RED << HumanB.getName() << RESET << ":\n" << std::endl;

	while (forever) {
		std::cout << "🩸 - " << RED << "ATTACK" << RESET << " to inflict damage on his opponent!" << std::endl;
		std::cout << "↻  - " << YELLOW << "ARSENAL" << RESET << " to pick up a new weapon!" << std::endl;
		std::cout << "⎘  - " << GREEN << "NEXT" << RESET << " to finish his interactions!" << std::endl;
		std::cout << MOVE_CURSOR_UP << (protagonist == 'A' ? BLUE : RED) << std::endl;

		std::string	input = getInputLine();
		std::cout << RESET << MOVE_CURSOR_UP << std::endl;
		erasePreviousLines(3);
		trimSpaces(input, false);

		if (equivalentString(input, "ATTACK")) {
			protagonist == 'A' ? HumanA.attack() : HumanB.attack();
			sleep(INTERACTION * 2);
			erasePreviousLines(2);
		}
		else if (equivalentString(input, "ARSENAL")) {
			if (protagonist == 'A')
				HumanA.getWeapon().setType(setWeapon(""));
			else {
				if (HumanB.getWeapon())
					HumanB.getWeapon()->setType(setWeapon(""));
				else {
					Weapon	newWeapon(setWeapon(""));
					HumanB.changeWeapon(&newWeapon);
				}
			}
		}
		else if (equivalentString(input, "NEXT"))
			break ;
	}
	erasePreviousLines(2);
}