/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                   File Name: /CPP-01/ex03/Weapon/Weapon.cpp                    *
*                    Creation Date: January 16, 2025 11:48 AM                    *
*                    Last Updated: January 18, 2025 04:34 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     To keep an eye on his weapon carrying                      *
*********************************************************************************/

#include "./Weapon.hpp"

/********************************************************************************/

/**
 * @brief Construct a new Weapon object.
 * 
 * @param newType The name of the weapon.
 */
Weapon::Weapon(const std::string &newType)	{ setType(newType); }

/**
 * @brief Variable assignment function.
 */

void	Weapon::setType(const std::string &newType)	{ type = newType; }

/**
 * @brief Function to get the value of variables.
 */

const std::string	&Weapon::getType(void)	{ return type; }