NAME = cub3d
CC = cc
INCLUDES = -I include
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR	= obj
SRC_DIR	= src
SRC_FILES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

BLUE	= \033[34;1m
GREEN	= \033[36;1m
END		= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Now compiling $(BLUE)$(NAME)$(END)..."
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^
	@echo "$(BLUE)$(NAME)$(END)$(GREEN) succesfully compiled! $(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re	