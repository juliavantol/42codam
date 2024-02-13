NAME = horde
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
CC = c++
SRC = main.cpp Zombie.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(INCLUDES) -c -o $@ $< $(CFLAGS)

clean:
	@rm -r $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re