/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                   File Name: /CPP-01/ex03/HumanB/HumanB.cpp                    *
*                    Creation Date: January 16, 2025 11:49 AM                    *
*                    Last Updated: January 18, 2025 04:24 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                    The interactive functions of the B human                    *
*********************************************************************************/

#include "./HumanB.hpp"

/********************************************************************************/

/**
 * @brief Construct a new Human B object.
 * 
 * @param name the name of the human.
 */
HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL), _damage(0) {}

/**
 * @brief Variable assignment function.
 */

void	HumanB::changeWeapon(Weapon *newWeapon)	{ _weapon = newWeapon; }

/**
 * @brief Functions to get the value of variables.
 */

std::string	HumanB::getName(void)	 const	{ return _name; }
Weapon		*HumanB::getWeapon(void) const	{ return _weapon; }
int		HumanB::getDamage(void) 			{ return _damage; }

/**
 * @brief Functions to signal and carry out an attack, affecting random damage (or none if disarmed) by human!
 * 
 */
void	HumanB::attack() {
	int			randomDamage = (getWeapon() ? rand() % 10 : 0);
	std::string	attackSource = (getWeapon() ? getWeapon()->getType() : "hands");

	_damage += randomDamage;
	std::cout << RED << getName() << RESET
		<< " attacks with their " << RED << attackSource << RESET << '!' << std::endl;
	std::cout << "It managed to inflict " << MAGENTA << randomDamage << RESET << " damage to his enemy!" << std::endl;
}