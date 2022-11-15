NAME = libftprintf.a
SRC = printf.c ft_hex_len.c parser.c ft_itoa_len.c
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && make bonus
	@cp libft/libft.a ./$(NAME)
	ar r $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus