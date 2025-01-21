/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-01/ex05/utilities/trimSpaces.cpp                *
*                    Creation Date: January 10, 2025 04:01 PM                    *
*                    Last Updated: January 21, 2025 08:31 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                   Managing the deletion of additional spaces                   *
*********************************************************************************/

#include "./../Harl.hpp"

/********************************************************************************/

/**
 * @brief Removes leading and trailing spaces from a string, with optional user confirmation.
 * 
 * @param string The string to process.
 */
void	trimSpaces(std::string &string) {
	size_t	start = 0;
	size_t	end = string.length();

	while (start < string.length() && std::isspace(string[start]))
		++start;
	while (end > start && std::isspace(string[end - 1]))
		--end;

	string = string.substr(start, end - start);
}