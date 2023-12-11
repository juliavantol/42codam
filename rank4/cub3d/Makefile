NAME = cub3d
CC = cc
INCLUDES = -I include
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR	= obj
SRC_DIR	= src
SRC_FILES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Now compiling $(NAME)..."
	@$(CC) $(CFLAGS) -lreadline $(INCLUDES) -o $@ $^
	@echo "$(NAME) succesfully compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re