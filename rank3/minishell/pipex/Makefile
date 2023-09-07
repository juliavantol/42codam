NAME = pipex
CC = gcc
LIBFT = inc/libft/libft.a
INCLUDES = -I inc
CFLAGS = -Wall -Wextra -Werror
SRC_FILES = src/pipex.c src/utils/utils.c src/utils/ft_split_args.c src/utils/exit_clean.c src/main.c \
			src/utils/join_str.c src/utils/envp.c src/heredoc.c \
			src/utils/get_next_line/get_next_line.c src/utils/get_next_line/get_next_line_utils.c \
			src/input.c
OBJ_DIR	= obj
SRC_DIR	= src
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

GREEN   = \033[32;1m
PURPLE	= \033[35;1m
RED		= \033[31;1m
BLUE	= \033[34;1m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Now compiling $(NAME)..."
	@$(CC) $(CFLAGS) -o $@ $^ $(INCLUDES) $(LIBFT)
	@echo "$(GREEN) $(NAME) succesfully compiled! $(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	@echo "Start compiling libft..."
	@cd inc/libft && make

clean:
	@rm -f *.o
	@rm -rf $(OBJ_DIR)
	@rm -f output.txt
	@cd inc/libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd inc/libft && make fclean

re: fclean all

.PHONY:	all clean fclean re