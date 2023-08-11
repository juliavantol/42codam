NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PRINTF = inc/printf/libftprintf.a
INCLUDES = -I inc
SRC = main.c src/utils/error.c src/utils/utils.c src/parse.c \
		inc/printf/printf.c inc/printf/ft_hex_len.c inc/printf/parser.c inc/printf/ft_itoa_len.c
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
	@cd inc/printf && make
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)
	@echo "$(GREEN)[$(NAME)] compiled!$(END)"

clean:
	@cd inc/printf && make clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
