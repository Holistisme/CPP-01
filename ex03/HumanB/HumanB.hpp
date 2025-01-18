/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                   File Name: /CPP-01/ex03/HumanB/HumanB.hpp                    *
*                    Creation Date: January 16, 2025 11:48 AM                    *
*                    Last Updated: January 18, 2025 17:20 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                         Declaration of a human type B                          *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include "./../main.hpp"
#include "./../Weapon/Weapon.hpp"

/********************************************************************************/

/**
 * @brief A human not spawning with a weapon.
 * 
 */
class HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;
		int			_damage;
	public:
		HumanB(const std::string &name);

		void		changeWeapon(Weapon *newWeapon);
		std::string	getName(void) const;
		Weapon		*getWeapon(void) const;
		void		attack(void);
		int			getDamage(void);
};

/********************************************************************************/

HumanB		setHumanB(void);