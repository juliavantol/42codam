NAME = megaphone
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp
OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	@rm -f *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re