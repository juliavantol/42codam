NAME = minishell
CC = gcc
LIBFT = inc/libft/libft.a
INCLUDES = -I inc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR	= obj
SRC_DIR	= src
SRC_FILES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Now compiling $(NAME)..."
	@$(CC) $(CFLAGS) -lreadline $(INCLUDES) $(LIBFT) -o $@ $^
	@echo "$(NAME) succesfully compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	@echo "Start compiling libft..."
	@cd inc/libft && make

clean:
	@rm -rf $(OBJ_DIR)
	@cd inc/libft && make clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re