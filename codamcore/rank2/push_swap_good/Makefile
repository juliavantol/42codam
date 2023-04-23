# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: juvan-to <juvan-to@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/24 12:19:20 by juvan-to      #+#    #+#                  #
#    Updated: 2023/04/22 11:40:47 by juvan-to      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
MAN_SRC = fill_stack.c ft_atoi_long.c push_swap.c input.c stack.c\
			operations.c sort.c utils.c small_stack.c
CC = gcc

SRC = $(MAN_SRC)
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && make bonus
	@$(CC) $(CFLAGS) -o push_swap $(SRC) $(LIBFT)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all

