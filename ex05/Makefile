##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-01/ex05/Makefile                         #
#                   Creation Date: January 21, 2025 08:21 AM                     #
#                    Last Updated: January 21, 2025 09:12 AM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= "Harl 2.0"

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

UTILITIES	= ./utilities

SOURCE		= main.cpp							\
			Harl.cpp							\
			$(UTILITIES)/equivalentString.cpp	\
			$(UTILITIES)/manageLines.cpp		\
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