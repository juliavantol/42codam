NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = include/libft/libft.a
SRC = main.c src/utils.c include/get_next_line/get_next_line.c include/get_next_line/get_next_line_utils.c \
		src/map_validity.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cd include/libft && make bonus
	@$(CC) $(CFLAGS) -o so_long $(SRC) $(LIBFT)

clean:
	@cd include/libft && make clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all

