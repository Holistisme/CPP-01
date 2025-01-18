/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                   File Name: /CPP-01/ex03/Weapon/Weapon.hpp                    *
*                    Creation Date: January 16, 2025 11:48 AM                    *
*                    Last Updated: January 18, 2025 04:27 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                 What better way to communicate than a weapon?                  *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

/**
 * @brief A weapon that has its type (thus allowing it to be identified in an outing).
 * 
 */
class Weapon {
	private:
		std::string	type;
	public:
		Weapon(const std::string &newType);

		void				setType(const std::string &newType);
		const std::string	&getType(void);
};

/********************************************************************************/

std::string	setWeapon(const std::string &lastWeapon);