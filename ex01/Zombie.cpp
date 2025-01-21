/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-01/ex01/Zombie.cpp                       *
*                    Creation Date: January 13, 2025 01:41 PM                    *
*                    Last Updated: January 21, 2025 08:13 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                        The source of all deadly action                         *
*********************************************************************************/

#include "./Zombie.hpp"

/********************************************************************************/

/**
 * @brief Construct a new Zombie object.
 * 
 * @param firstName the name to give to the zombie.
 * @param allocated if the zombie is allocated, allows you to track its memory.
 */
void	Zombie::setName(const std::string &firstName) {
	name = firstName;
	announce();
}

/**
 * @brief Destroy the Zombie object.
 * 
 */
Zombie::~Zombie() {
	static const std::string	gasps[] = {"Huhhhh...", "Urrrrgh...", "Whaaaat?!", "Braaaaahh..."};

	std::cout << getName() << RESET << ": " << gasps[rand() % 4] << std::endl;
}

/********************************************************************************/

/**
 * @brief Assesses the name and color for display.
 * 
 * @return std::string The sum of the colorful name.
 */
std::string	Zombie::getName(void) {
	return (BRIGHT_GREEN + (!name.empty() ? name : "An unknown zombie"));
}

/********************************************************************************/

/**
 * @brief The zombie interactively announces itself.
 * 
 */
void	Zombie::announce(void) {
	std::cout << getName() << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/**
 * @brief Allows the zombie to introduce himself and say a random phrase.
 * 
 * @param i the zombie's index within the horde.
 */
void	Zombie::saySomething(const index &i) {
	static const std::string	something[] = {"Hungry... so hungry...", "Must... feed...",
		"More brains...", "Food...", "Where... is... everyone?", "So... tired...", "Why... am I... so slow?",
		"Do zombies pay taxes?", "I miss my coffee... and my brains.", "Do I look pale to you?",
		"Being undead is exhausting!", "I'm not biting... yet!", "I think I lost a limb... again.",
		"Brains... gluten-free ones, please!", "Why does everyone run away from me?", "I remember... being alive...",
		"Why... can't I just rest?", "Do you think zombies can dream?", "I feel so... empty.", "What... was my name?",
		"If a zombie eats a brain in the forest, does it make a sound?", "What... is life... really?", "Do zombies have a soul?",
		"Is being undead... a second chance?", "Why are brains so... delicious?",
		"I’m right behind you...", "You can’t run forever!", "You’ll be one of us soon...", "Brains... yours look... tasty.",
		"I can... smell your fear.", "Join us... it's not so bad.", "We are the future of evolution.", "What... am I doing here?"
		"This place looks... familiar.", "Braiiiiiiinnnzzz?", "No, thanks. I just ate."};

	std::cout << "I am the number " << BLUE << std::setw(2) << std::setfill('0') << i << RESET
		<< " of the horde, my name is " << getName() << RESET
		<< " and I just want to say: " << something[rand() % 35] << std::endl;
}