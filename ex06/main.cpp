/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-01/ex06/main.cpp                        *
*                    Creation Date: January 21, 2025 08:19 AM                    *
*                    Last Updated: January 21, 2025 10:39 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     The main program to make Harl complain                     *
*********************************************************************************/

#include "./Harl.hpp"

/********************************************************************************/

/**
 * @brief The main program to make Harl complain.
 * 
 * @return int The end of program status.
 */
int main(void) {
	try {
		Harl	Harl;

		std::cout << "\n🗣  " << BG_BRIGHT_YELLOW <<  "Harl 2.0" << RESET << " arrived at the restaurant! And he's going to complain A LOT!" << " 🗣\n" << std::endl;
		std::srand(std::time(0));
		while (forever) {
			std::cout << "I   - " << GREEN	<< "DEBUG" << RESET << std::endl;
			std::cout << "II  - " << BLUE	<< "INFO" << RESET << std::endl;
			std::cout << "III - " << YELLOW	<< "WARNING" << RESET << std::endl;
			std::cout << "IV  - " << RED	<< "ERROR" << RESET << std::endl;
			std::cout << "🚪  - " << BG_RED	<< "EXIT" << RESET << std::endl;

			std::string	input = getInputLine();
			erasePreviousLines(5);
			trimSpaces(input);

			if (input.find(SIGNAL) != std::string::npos) {
				std::cout << ERROR << "Harl refuses to carry signals!" << RESET << std::endl;
				sleep(COOLDOWN), erasePreviousLines(1);
				continue;
			}
			else if (input.empty()) {
				std::cout << ERROR << "How could Harl complain if he has no reason to suffer?!" << RESET << std::endl;
				sleep(COOLDOWN), erasePreviousLines(1);
				continue;
			}
			else if (equivalentString(input, "EXIT")) {
				erasePreviousLines(2);
				std::cout << EXIT_MESSAGE << '\n' << std::endl;
				return EXIT_SUCCESS;
			}

			Harl.complain(input);
		}
	}	catch (...) {
		std::cout << ERROR << "Something went wrong. I'll blame std::string!" << RESET << std::endl;
		return EXIT_FAILURE;
	}
}