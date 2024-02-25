NAME = brains
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I include
CC = c++
OBJ_DIR = obj
SRC_DIR = src
SRC = src/main.cpp src/newZombie.cpp src/Zombie.cpp src/randomChump.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(INCLUDES) -c -o $@ $< $(CFLAGS)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
