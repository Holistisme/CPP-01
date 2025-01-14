/********************************************************************************/

#include <cstdlib>
#include <csignal>
#include <iostream>

#define RESET		"\033[0m"

#define GREEN		"\033[32m"
#define BLUE		"\033[34m"
#define BG_YELLOW	"\033[43m"

#define ERASE_LINE	"\33[2K\r"
#define RED			"\033[31m"
#define BG_RED		"\033[41m"

/********************************************************************************/

/**
 * @brief A simple educational program!
 * 
 * @return int Returns the end-of-program status.
 */
int main(void) {
	try {
		std::string	stringVariable	= "HI THIS IS BRAIN";
		std::string	*stringPTR		= &stringVariable;
		std::string	&stringREF(stringVariable);

		std::cout << GREEN << &stringVariable << RESET
				<< " is the memory address of stringVariable." << std::endl
				<< "This is "
				<< BG_YELLOW << "where this variable is stored" << RESET
				<< " in memory." << std::endl << std::endl;

		std::cout << GREEN << stringPTR << RESET
				<< " is the memory address held by stringPTR." << std::endl
				<< "This is a pointer that "
				<< BG_YELLOW << "holds the address" << RESET
				<< " of the original variable." << std::endl << std::endl;

		std::cout << GREEN << &stringREF << RESET 
				<< " is the memory address held by stringREF." << std::endl
				<< "This is a reference (alias) to the original variable. It allows "
				<< BG_YELLOW << "direct access without creating a copy" << RESET
				<< ", especially useful in functions." << std::endl << std::endl;

		std::cout << BLUE << stringVariable << RESET
				<< " is the value of stringVariable." << std::endl
				<< "This is the "
				<< BG_YELLOW << "actual content" << RESET << " of the original variable." << std::endl << std::endl;

		std::cout << BLUE << *stringPTR << RESET
				<< " is the value of stringPTR." << std::endl
				<< "This is the content accessed by dereferencing the pointer, and it "
				<< BG_YELLOW << "matches the value" << RESET
				<< " of the original variable." << std::endl << std::endl;

		std::cout << BLUE << stringREF << RESET
				<< " is the value of stringREF." << std::endl
				<< "This is the content of the reference, which "
				<< BG_YELLOW << "directly mirrors" << RESET
				<< " the original variable." << std::endl;

		return EXIT_SUCCESS;
	} catch (...) {
		std::cout << BG_RED << "ERROR:" << RESET
			<< RED << " Something went wrong!" << RESET << std::endl;
		return EXIT_FAILURE;
	}
}