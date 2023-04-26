NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = include/libft/libft.a
SRC = main.c src/utils.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cd include/libft && make bonus
	$(CC) $(CFLAGS) -o so_long $(SRC) $(LIBFT)


clean:
	@cd include/libft && make clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all

