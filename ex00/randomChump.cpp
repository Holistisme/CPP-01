#include "./Zombie.hpp"

void	Zombie::randomChump(std::string name) {
	Zombie	chump;

	erasePreviousLines(1);
	chump.name = name;
	chump.setZombieColor();
	chump.announce();
	chump.canDie = true;
	std::cout << "Sorry " << chump.getColoredName() << RESET
		<< ", but you're not able to get out of this function!" << std::endl;
	sleep(INTERACTION), erasePreviousLines(1);
}