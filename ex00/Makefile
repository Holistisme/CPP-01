##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-01/ex00/Makefile                         #
#                   Creation Date: January 10, 2025 12:36 AM                     #
#                    Last Updated: January 15, 2025 03:03 AM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= "BraiiiiiiinnnzzzZ"

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

UTILITIES	= ./utilities

SOURCE		= main.cpp							\
			handleSigInt.cpp					\
			newZombie.cpp						\
			randomChump.cpp						\
			Zombie.cpp							\
			$(UTILITIES)/confirmAction.cpp		\
			$(UTILITIES)/equivalentString.cpp	\
			$(UTILITIES)/manageLines.cpp		\
			$(UTILITIES)/trimSpaces.cpp

OBJECTS		= $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CXX) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re