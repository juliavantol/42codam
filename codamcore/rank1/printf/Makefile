NAME = libftprintf.a
SRC = main.c printf.c ft_hex_len.c parser.c ft_itoa_len.c 
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
	@cd libft && make fclean

re: fclean all

run: main.c all
	@$(CC) -Wall -Wextra -Werror -o run main.c libftprintf.a && ./run

.PHONY: all clean fclean re libft