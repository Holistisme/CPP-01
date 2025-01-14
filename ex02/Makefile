##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-01/ex02/Makefile                         #
#                   Creation Date: January 14, 2025 01:02 PM                     #
#                    Last Updated: January 14, 2025 03:27 PM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= "HI THIS IS BRAIN"

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SOURCE		= main.cpp

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