/*********************************************************************************
*                              Author: Alexy Heitz                               *
*             File Name: /CPP-01/ex03/utilities/equivalentString.cpp             *
*                    Creation Date: January 10, 2025 03:58 PM                    *
*                    Last Updated: January 18, 2025 03:33 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                  Compares the similarity between two strings                   *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

/**
 * @brief Compare two strings case-insensitively.
 * 
 * This function checks if two strings are alphabetically identical,
 * ignoring differences in capitalization.
 * 
 * @param first The first string to compare.
 * @param second The second string to compare.
 * @return true: if the strings are identical (case-insensitive), false otherwise.
 */
bool	equivalentString(const std::string &first, const std::string &second) {
	if (first.length() != second.length())
		return (false);

	for (size_t i = 0; i < first.length(); i++) {
		char firstCurrentChar	= (first[i] >= 'a' && first[i] <= 'z')   ? (first[i] - 'a' + 'A')  : first[i];
		char secondCurrentChar	= (second[i] >= 'a' && second[i] <= 'z') ? (second[i] - 'a' + 'A') : second[i];

		if (firstCurrentChar != secondCurrentChar)
			return (false);
	}
	return (true);
}