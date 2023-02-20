# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: juvan-to <juvan-to@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/21 10:59:12 by juvan-to      #+#    #+#                  #
#    Updated: 2023/02/20 11:53:10 by juvan-to      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
SRC = printf.c ft_hex_len.c parser.c ft_itoa_len.c
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && make bonus
	@cp libft/libft.a ./$(NAME)
	@ar r $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -c -o $@ $< $(CFLAGS)

clean:	
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re