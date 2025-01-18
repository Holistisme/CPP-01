#include "./Weapon.hpp"

/********************************************************************************/

/**
 * @brief Set the Weapon object.
 * 
 * @param lastWeapon the name of the last weapon used.
 * @return std::string the name of the new weapon.
 */
std::string	setWeapon(const std::string &lastWeapon) {
	if (!lastWeapon.empty()) {
		std::cout << "You can use the latest weapon of this team if you want: "
			<< YELLOW << lastWeapon << RESET << '!' << std::endl;
		if (confirmAction())
			return lastWeapon;
	}

	std::cout << "Let's create a " << YELLOW << "new object" << RESET << " with which to chat with the enemy or "
		<< CYAN << "leave blank for a random arsenal" << RESET << "!" << std::endl;
	std::string	input = getInputLine();
	trimSpaces(input, true);
	if (input.empty()) {
		const std::string	randomWeapons[] = {
		"Sword", "Axe", "Bow", "Spear", "Dagger",
        "Mace", "Shield", "Pistol", "Rifle", "Sniper Rifle",
        "Grenade", "Machine Gun", "Excalibur", "Flaming Sword",
        "Thunder Axe", "Dragon Slayer", "Magic Wand",
        "Rubber Chicken", "Frying Pan", "Toilet Brush",
        "Giant Pencil", "Banana", "Brick", "Broken Bottle",
        "Chair", "Stick", "Rock"
		};

		input = randomWeapons[rand() % 27];
	}

	erasePreviousLines(1);
	return input;
}