/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                   File Name: /CPP-01/ex03/HumanA/HumanA.hpp                    *
*                    Creation Date: January 16, 2025 11:49 AM                    *
*                    Last Updated: January 18, 2025 17:20 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                         Declaration of a human type A                          *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include "./../main.hpp"
#include "./../Weapon/Weapon.hpp"

/********************************************************************************/

/**
 * @brief A human that can spawn with a weapon.
 * 
 */
class HumanA
{
	private:
		std::string	_name;
		Weapon		_weapon;
		size_t		_damage;
	public:
		HumanA(const std::string &name, const Weapon &weapon);

		void		changeWeapon(const Weapon &newWeapon);
		std::string	getName(void) const;
		Weapon		&getWeapon(void);
		void		attack(void);
		int			getDamage(void);
};

/********************************************************************************/

HumanA	setHumanA(void);