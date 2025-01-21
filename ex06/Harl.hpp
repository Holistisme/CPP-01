/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-01/ex06/Harl.hpp                        *
*                    Creation Date: January 21, 2025 08:20 AM                    *
*                    Last Updated: January 21, 2025 10:43 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                              All of Harl's hatred                              *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include "./output.hpp"

/********************************************************************************/

#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

/********************************************************************************/

#define forever			 1

#define INTERACTION		3
#define COOLDOWN		3

#define SIGNAL			'\033'
#define EXIT_MESSAGE	"🗣  Thanks for getting all the employees fired by complaining " BG_YELLOW "Harl 2.0" RESET "! 🗣"

/********************************************************************************/

typedef int		index;

class	Harl {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		void	complain(std::string level);
};

typedef void	(Harl::*HarlMethod)();

/********************************************************************************/

bool		equivalentString(const std::string &first, const std::string &second);
std::string	getInputLine(void);
void		erasePreviousLines(const size_t &count);
void		trimSpaces(std::string &string);