/*********************************************************************************
*                              Author: Alexy Heitz                               *
*               File Name: /CPP-01/ex03/utilities/confirmAction.cpp              *
*                    Creation Date: January 10, 2025 04:02 PM                    *
*                    Last Updated: January 18, 2025 02:58 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                        To be sure of the user's wishes                         *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

static inline bool	matchesAny(const std::string &input, const std::string options[], const size_t &size);

/********************************************************************************/

/**
 * @brief Wait for the user's confirmation.
 * 
 * @return true: if the user confirms the action.
 * @return false: if the user declines the action.
 */
bool	confirmAction(void) {
	const std::string	acceptOptions[] = { "y", "yes", "agree",
		"sure", "why note", "absolutely", "of course", "go for it",
		"do it", "Accept away!" , "ok", "yeah", "yup", "aye", "confirmed",
		"let's go", "do it up!", "+1", "true", "enable", "sure thing",
		"heck yeah!", "go ahead", "yessir", "fine", "alright", "let's do this",
		"To infinity and beyond!", "Make it so!", "Engage!", "Do it like it's hot!",
		"Chop chop!", "Houston, we are go for this!",
		"Yes, my liege!", "Activate protocol!", "Ready to roll!"
	};
	const std::string	declineOptions[] = { "n", "no", "disagree",
		"nah", "nope", "not really", "never", "don't", "stop", "leave it",
		"disable", "false", "negative", "why?", "not today", "hard pass", "forget it",
		"no way", "declined", "I said no", "just no", "abort", "Not on my watch!",
		"Over my dead body!", "Hard no!", "I don't think so, pal.", "Step away from the keyboard!",
		"No means no!", "Abort mission!", "Don't touch my spaces!", "I like my chaos!", "Nah, I'm a rebel like that."
	};

	while (forever) {
		std::string	input = getInputLine();
		trimSpaces(input, false);

		if (matchesAny(input, acceptOptions, sizeof(acceptOptions) / sizeof(*acceptOptions)))
			return erasePreviousLines(1), true;
		else if (matchesAny(input, declineOptions, sizeof(declineOptions) / sizeof(*declineOptions)))
			return erasePreviousLines(1), false;
		else {
			std::cout << '"' << YELLOW << input << RESET <<  '"' << RED << " is not a valid input! " << RESET
				<< "Try something like: " << GREEN << acceptOptions[std::rand() % (sizeof(acceptOptions) / sizeof(*acceptOptions))] << RESET
				<< " or " << RED << declineOptions[std::rand() % (sizeof(declineOptions) / sizeof(*declineOptions))] << RESET << '.' << std::endl;
			sleep(COOLDOWN);
			erasePreviousLines(1);
		}
	};
}

/**
 * @brief Check if a given input matches any option in a list.
 * 
 * @param input The user input to check.
 * @param options The array of valid options.
 * @param size The size of the options array.
 * @return true: if the input matches any option, false otherwise.
 */
static inline bool matchesAny(const std::string &input, const std::string options[], const size_t &size) {
	for (size_t i = 0 ; i < size ; ++i)
		if (equivalentString(input, options[i]))
			return (true);
	return (false);
}