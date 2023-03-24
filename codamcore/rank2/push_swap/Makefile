# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: juvan-to <juvan-to@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/24 12:19:20 by juvan-to      #+#    #+#                  #
#    Updated: 2023/03/24 13:00:40 by juvan-to      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
MAN_SRC = push_swap.c
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

