/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-01/ex05/Harl.cpp                        *
*                    Creation Date: January 21, 2025 08:20 AM                    *
*                    Last Updated: January 21, 2025 09:35 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     Harl's personality on several levels.                      *
*********************************************************************************/

#include "./Harl.hpp"

/********************************************************************************/

/**
 * @brief The first level of complaint.
 * 
 */
void	Harl::debug(void) {
	const std::string	someComplaints[] = {
		"Why do menus have photos that never look like what I get?",
        "Your ketchup is too red, it can’t be natural.",
        "I saw a fly flying near the kitchen. Not in it, just near it.",
        "My burger is perfect... but I thought it would be even better.",
        "The bread is too round. Can we have square bread?!"
	};

	std::cout << "Harl: " << GREEN << someComplaints[rand() % 5] << RESET << std::endl;
}

/**
 * @brief The second level of complaint.
 * 
 */
void	Harl::info(void) {
	const std::string	someComplaints[] = {
		"I notice you changed the sauce recipe, it's not as good as before.",
        "I think the ice cubes in my soda are melting too quickly.",
        "The napkin paper is not soft enough.",
        "Your air conditioning is a little too cold to be pleasant.",
        "The music is slightly too loud near the cash register."
	};

	std::cout << "Harl: " << BLUE << someComplaints[rand() % 5] << RESET << std::endl;
}

/**
 * @brief The third level of complaint.
 * 
 */
void	Harl::warning(void) {
	const std::string	someComplaints[] = {
		"I don't like waiting more than 5 minutes for a burger.",
        "Your server didn't smile at me, it makes me uncomfortable.",
        "Too much mayonnaise on my sandwich could be dangerous for my health.",
        "Your parking lot is too small, it’s frustrating.",
        "The drink was not cold enough, is this a policy to save energy?"
	};

	std::cout << "Harl: " << YELLOW << someComplaints[rand() % 5] << RESET << std::endl;
}

/**
 * @brief The fourth level of complaint.
 * 
 */
void	Harl::error(void) {
	const std::string	someComplaints[] = {
		"This is unacceptable! My burger arrived lukewarm.",
        "I asked for a straw, and there wasn't one in my bag. How will I drink my soda?",
        "I've been coming here for 10 years, and this is the first time I've been so disappointed.",
        "Your service is a disaster! I waited 6 minutes.",
        "Call your manager immediately. This is a complete outrage!"
	};

	std::cout << "Harl: " << RED << someComplaints[rand() % 5] << RESET << std::endl;
}

/********************************************************************************/

/**
 * @brief The function that allows Harl to dynamically complain.
 * 
 * @param level Harl's level of complaint.
 */
void	Harl::complain(std::string level) {
	const std::string	availableLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	const HarlMethod	methods[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (index i = 0 ; i < 4 ; ++i) {
		if (equivalentString(level, availableLevels[i])) {
			(this->*methods[i])();
			sleep(INTERACTION), erasePreviousLines(1);
			return;
		}
	}

	std::cout << ERROR << "You ask Harl to complain but I think your intellectual level is already complaining about the idiocies you write." << RESET << std::endl;
	sleep(COOLDOWN), erasePreviousLines(1);
}