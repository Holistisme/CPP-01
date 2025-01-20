/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-01/ex04/main.cpp                        *
*                    Creation Date: January 18, 2025 05:54 PM                    *
*                    Last Updated: January 20, 2025 03:53 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                     To replace occurrences like a big boy                      *
*********************************************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>

/********************************************************************************/

#define	FILENAME		1
#define	OLD_OCCURENCE	2
#define	NEW_OCCURENCE	3

#define GREEN			"\033[32m"
#define YELLOW			"\033[33m"
#define CYAN			"\033[36m"
#define BG_GREEN		"\033[42m"

#define RESET			"\033[0m"
#define RED				"\033[31m"
#define BG_RED			"\033[41m"
#define ERROR			BG_RED "ERROR:" RESET RED " "

/********************************************************************************/

static inline void			checkArguments(int argc);
static inline std::string	readAndReplaceFile(char *argv[]);
static inline std::string	findAndReplace(std::string &line, char *argv[]);
static inline void			writeOutput(const std::string &newContent, const char *file);

/********************************************************************************/

/**
 * @brief A simple program replacing the second parameter in the first argument file with the third.
 * 
 * @param argc The number of arguments entered into the program.
 * @param argv The value of the program arguments.
 * @return int The exit code.
 */
int main(int argc, char *argv[]) {
	try {
		checkArguments(argc);

		std::string	newFile = std::string(argv[FILENAME]) + ".replace";
		writeOutput(readAndReplaceFile(argv), newFile.c_str());

		std::cout << BG_GREEN << "GOT YOU:" << RESET << " "
			<< CYAN << argv[FILENAME] << RESET << " was scanned: all "
			<< RED << argv[OLD_OCCURENCE] << RESET << " occurrences have been changed to "
			<< GREEN << argv[NEW_OCCURENCE] << RESET " and everything was saved in "
			<< YELLOW << newFile << RESET << "!" << std::endl;

		return EXIT_SUCCESS;
	} catch (...) {
		std::cout << ERROR << "Something went wrong. I'll blame std::string!" << RESET << std::endl;
		return EXIT_FAILURE;
	}
}

/**
 * @brief Checks if the correct number of arguments is provided, otherwise exits the program.
 * 
 * @param argc The number of program arguments.
 */
static inline void	checkArguments(int argc) {
	if (argc == 4)	return ;

	std::cout << ERROR << "the number of arguments does not allow a reasoned comparison. Maybe it's time to go to primary school?" << RESET << std::endl;
	exit(EXIT_FAILURE);
}

/**
 * @brief Opens a file to replace the occurrences of the arguments.
 * 
 * @param argv The program arguments.
 * @return std::string The new contents of the file.
 */
static inline std::string	readAndReplaceFile(char *argv[]) {
	std::ifstream	input(argv[FILENAME]);
	if (!input.is_open()) {
		std::cout << ERROR << "I couldn't open the request file!" << RESET << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string	nextLine;
	std::ostringstream	newContent;
	while (std::getline(input, nextLine)) {
		if (newContent.tellp() > 0)
			newContent << '\n';
		newContent << findAndReplace(nextLine, argv);
	}
	input.close();
	return newContent.str();
}

/**
 * @brief Searches the line for an occurrence and replaces it.
 * 
 * @param line The target line.
 * @param argv The program arguments.
 * @return std::string The line with the changed occurrences.
 */
static inline std::string	findAndReplace(std::string &line, char *argv[]) {
	static size_t		occurrenceLength = std::string(argv[OLD_OCCURENCE]).length();
	std::ostringstream	newLine;
	size_t				start = 0;
	size_t				pos = 0;

	while ((pos = line.find(argv[OLD_OCCURENCE], start)) != std::string::npos) {
		newLine << line.substr(start, pos - start);
		newLine << argv[NEW_OCCURENCE];
		start = pos + occurrenceLength;
	}
	newLine << line.substr(start);

	return newLine.str();
}

/**
 * @brief Creates a new file if possible to write the new content to it.
 * 
 * @param newContent The content to save in the new file.
 * @param file The name of the replacing file.
 */
static inline void	writeOutput(const std::string &newContent, const char *file) {
	std::ofstream	output(file);

	if (!output.is_open()) {
		std::cout << ERROR << "the replacement file could not be initiated!" << RESET << std::endl;
		exit(EXIT_FAILURE);
	}

	output << newContent;
	if (output.fail()) {
		std::cout << ERROR << "I broke my pen and couldn't write in the file!" << RESET << std::endl;
		exit(EXIT_FAILURE);
	}
	output.close();
}