/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                        File Name: /CPP-01/ex03/main.hpp                        *
*                    Creation Date: January 16, 2025 11:47 AM                    *
*                    Last Updated: January 18, 2025 05:50 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*               All the essential information to assault an enemy                *
*********************************************************************************/

#pragma once

/********************************************************************************/

#include "./output.hpp"

/********************************************************************************/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <ctime>

/********************************************************************************/

typedef int	index;

/********************************************************************************/

#define forever			true

#define INTERACTION		2
#define COOLDOWN		3

#define EXIT_MESSAGE	"⚔ Thanks for using " BG_BRIGHT_RED "Unnecessary violence" RESET " ! ⚔"
#define SIGNAL			'\033'

/********************************************************************************/

bool		confirmAction(void);
bool		equivalentString(const std::string &first, const std::string &second);
std::string	getInputLine(void);
void		erasePreviousLines(const size_t &count);
void		trimSpaces(std::string &string, const bool &isTrimable);