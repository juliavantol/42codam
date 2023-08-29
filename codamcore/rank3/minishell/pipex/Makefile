NAME = pipex
CC = gcc
LIBFT = inc/libft/libft.a
INCLUDES = -I inc
CFLAGS = -Wall -Wextra -Werror
SRC = pipex.c utils.c ft_split_args.c free.c
OBJ_DIR	:= obj
OBJS	= $(SRC:%.c=$(OBJ_DIR)/%.o)

GREEN   := \033[32;1m
PURPLE	:= \033[35;1m
RED		:= \033[31;1m
BLUE	:= \033[34;1m
END		= \x1b[0m

all: directories $(NAME)

$(NAME): $(OBJS)
	@echo "Start compiling $(PURPLE)libft$(END)..."
	@cd inc/libft && make
	@echo "Now compiling $(PURPLE)$(NAME)$(END)..."
	@$(CC) $(INCLUDES) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(GREEN)$(NAME)$(END) succesfully compiled!"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(INCLUDES) -c -o $@ $< $(CFLAGS)

directories:
	@mkdir -p $(OBJ_DIR)

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
