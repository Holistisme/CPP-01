NAME		= "BraiiiiiiinnnzzzZ"

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

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
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re