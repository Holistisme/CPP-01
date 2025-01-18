/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                  File Name: /CPP-01/ex03/HumanA/setHumanA.cpp                  *
*                    Creation Date: January 18, 2025 04:36 PM                    *
*                    Last Updated: January 18, 2025 05:21 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*            Provides increased ability to dynamically define human A            *
*********************************************************************************/

#include "./HumanA.hpp"

/********************************************************************************/

/**
 * @brief Set an Human A object.
 * 
 * @return HumanA human creates from information.
 */
HumanA	setHumanA(void) {
	static std::string	lastName	= "";
	static std::string	lastWeapon	= "";

	if (!lastName.empty()) {
		std::cout << "You can resurrect the last human on the " << BLUE << "blue team" << RESET
			<< " if you want: " << YELLOW << lastName << RESET << '!' << std::endl;
		if (!confirmAction())
			lastName = "";
	}
	if (lastName.empty()) {
		std::cout << "Let's create a new human for the " << BLUE << "blue team" << RESET
			<< " (" << GREEN << "which has a weapon by default" << RESET
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
	lastWeapon = setWeapon(lastWeapon);
	return HumanA(lastName, Weapon(lastWeapon));
}