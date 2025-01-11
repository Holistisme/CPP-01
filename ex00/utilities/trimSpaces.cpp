/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-01/ex00/utilities/trimSpaces.cpp                *
*                    Creation Date: January 10, 2025 04:01 PM                    *
*                    Last Updated: January 11, 2025 10:47 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                   Managing the deletion of additional spaces                   *
*********************************************************************************/

#include "./../Zombie.hpp"

/********************************************************************************/

static inline void	printConfirmationMessage(const std::string &side);

/********************************************************************************/

/**
 * @brief Removes leading and trailing spaces from a string, with optional user confirmation.
 * 
 * If the `addingAction` parameter is true, the function will prompt the user
 * for confirmation before removing spaces from the front or back.
 * 
 * @param string The string to process.
 * @param isZombieName If true, requests confirmation for each trim; otherwise trims automatically.
 */
void	trimSpaces(std::string &string, const bool &isZombieName) {
	size_t	start = 0;
	size_t	end = string.length();

	while (start < string.length() && std::isspace(string[start]))
		++start;
	while (end > start && std::isspace(string[end - 1]))
		--end;

	if (isZombieName) {
		if (start) {
			printConfirmationMessage("front");
			if (confirmAction()) {
				string = string.substr(start, string.length() - start);
				end -= start;
			}
		}
		if (end < string.length()) {
			printConfirmationMessage("back");
			if (confirmAction())
				string = string.substr(0, end);
		}
	}
	else
		string = string.substr(start, end - start);
}

/**
 * @brief Prints a confirmation request to remove a side filled with space.
 * 
 * @param side The side to be purged ("front" or "back").
 */
static inline void	printConfirmationMessage(const std::string &side) {
	std::cout << "An empty space is present in " << YELLOW << side << RESET
		<< " of the entrance. Do you want " << RED << "to remove it" << RESET << '?' << std::endl;
}