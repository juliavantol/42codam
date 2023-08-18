NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I inc
SRC = main.c src/utils/ft_atoi.c src/utils/utils.c src/threads.c src/parse.c \
		src/eat.c src/utils/libft.c src/utils/clean.c src/routines.c
OBJ = $(SRC:%.c=%.o)

GREEN   := \033[32;1m
END		= \x1b[0m

all: $(NAME)

%.o: %.c
	@$(CC) $(INCLUDES) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)[$(NAME)]$(END) compiled!"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
