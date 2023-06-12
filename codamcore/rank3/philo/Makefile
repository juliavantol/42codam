NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I inc
SRC = main.c src/utils/error.c src/utils/ft_atoi.c src/utils/ft_strlen.c src/utils/utils.c \
		src/utils/ft_putnum.c
OBJ = $(SRC:%.c=%.o)

RED     := \033[31;1m
GREEN   := \033[32;1m
YELLOW  := \033[33;1m
BLUE    := \033[34;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
END		= \x1b[0m

all: $(NAME)

%.o: %.c
	@$(CC) $(INCLUDES) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)[$(NAME)] compiled!$(END)"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
