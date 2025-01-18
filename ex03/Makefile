##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-01/ex03/Makefile                         #
#                   Creation Date: January 16, 2025 10:59 AM                     #
#                    Last Updated: January 18, 2025 05:22 PM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= "Unnecessary violence"

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

HUMANA		= ./HumanA
HUMANB		= ./HumanB
UTILITIES	= ./utilities
WEAPON		= ./Weapon

SOURCE		= main.cpp							\
			$(HUMANA)/HumanA.cpp				\
			$(HUMANA)/setHumanA.cpp				\
			$(HUMANB)/HumanB.cpp				\
			$(HUMANB)/setHumanB.cpp				\
			$(UTILITIES)/confirmAction.cpp		\
			$(UTILITIES)/equivalentString.cpp	\
			$(UTILITIES)/manageLines.cpp		\
			$(UTILITIES)/trimSpaces.cpp			\
			$(WEAPON)/Weapon.cpp				\
			$(WEAPON)/setWeapon.cpp	

OBJECTS		= $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re