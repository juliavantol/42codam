NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lreadline -lcurses
OBJ_DIR	= obj
SRC_DIR	= src
SRC_FILES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Now compiling $(NAME)..."
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(NAME) succesfully compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	@echo "Start compiling libft..."

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re