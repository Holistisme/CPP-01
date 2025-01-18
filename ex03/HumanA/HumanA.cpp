/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                   File Name: /CPP-01/ex03/HumanA/HumanA.cpp                    *
*                    Creation Date: January 16, 2025 11:49 AM                    *
*                    Last Updated: January 18, 2025 03:43 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                    The interactive functions of the A human                    *
*********************************************************************************/

#include "./HumanA.hpp"

/********************************************************************************/

/**
 * @brief Construct a new Human A object.
 * 
 * @param name the name of the human.
 * @param weapon the weapon carried by human.
 */
HumanA::HumanA(const std::string &name, const Weapon &weapon) : _name(name), _weapon(weapon), _damage(0) {}

/**
 * @brief Variable assignment function.
 */

void	HumanA::changeWeapon(const Weapon &newWeapon)	{ _weapon = newWeapon; }

/**
 * @brief Functions to get the value of variables.
 */

std::string	HumanA::getName(void) const	{ return _name; }
Weapon		&HumanA::getWeapon(void)	{ return _weapon; }
int			HumanA::getDamage(void)		{ return _damage; }

/**
 * @brief Functions to signal and carry out an attack, affecting random damage by human!
 * 
 */
void	HumanA::attack() {
	int	randomDamage = rand() % 10;

	_damage += randomDamage;
	std::cout << BLUE << getName() << RESET << " attacks with their "
		<< RED << getWeapon().getType() << RESET << '!' << std::endl;
	std::cout << "It managed to inflict " << MAGENTA << randomDamage << RESET << " damage to his enemy!" << std::endl;
}