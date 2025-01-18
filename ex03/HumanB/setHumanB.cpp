/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                  File Name: /CPP-01/ex03/HumanB/setHumanB.cpp                  *
*                    Creation Date: January 18, 2025 04:36 PM                    *
*                    Last Updated: January 18, 2025 17:22 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*            Provides increased ability to dynamically define human B            *
*********************************************************************************/

#include "./HumanB.hpp"

/********************************************************************************/

/**
 * @brief Set an Human B object.
 * 
 * @return HumanB human creates from information.
 */
HumanB	setHumanB(void) {
	static std::string	lastName	= "";

	if (!lastName.empty()) {
		std::cout << "You can resurrect the last human on the " << RED << "red team" << RESET
			<< " if you want: " << YELLOW << lastName << RESET << '!' << std::endl;
		if (!confirmAction())
			lastName = "";
	}
	if (lastName.empty()) {
		std::cout << "Let's create a new human for the " << RED << "red team" << RESET
			<< " (" << RED << "which does not have a weapon by default" << RESET
			<< "), or leave it empty if we don't care!" << std::endl;
		trimSpaces(lastName = getInputLine(), true);
		if (lastName.empty()) {
			if (rand() % 2)
				lastName = "An unknown male human";
			else
				lastName = "An unknown female human";
		}
		erasePreviousLines(1);
	}
	return HumanB(lastName);
}