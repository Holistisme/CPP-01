##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-01/ex01/Makefile                         #
#                   Creation Date: January 13, 2025 01:41 PM                     #
#                    Last Updated: January 15, 2025 05:35 PM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= "Moar brainz!"

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

UTILITIES	= ./utilities

SOURCE		= main.cpp							\
			handleSigInt.cpp					\
			Zombie.cpp							\
			zombieHorde.cpp						\
			$(UTILITIES)/confirmAction.cpp		\
			$(UTILITIES)/equivalentString.cpp	\
			$(UTILITIES)/getLines.cpp			\
			$(UTILITIES)/trimSpaces.cpp

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