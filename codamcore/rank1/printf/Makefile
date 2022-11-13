NAME = libftprintf.a
SRC = main.c printf.c helpers.c hex.c unsigned_ints.c void_pointer.c ints.c unsigned_dec.c decimals.c 
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) libft
	@cd libft && make bonus
	@cp libft/libft.a ./$(NAME)
	@ar r $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: main.c all
	@$(CC) -Wall -Wextra -Werror -o run main.c libftprintf.a && ./run

.PHONY: all clean fclean re libft