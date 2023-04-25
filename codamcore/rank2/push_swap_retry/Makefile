# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: juvan-to <juvan-to@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/03/24 12:19:20 by juvan-to      #+#    #+#                  #
#    Updated: 2023/04/25 15:13:40 by juvan-to      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
MAN_SRC = ft_atoi_max.c push_swap.c input.c stack.c\
			operations.c sort_big.c utils.c sort_small.c
BONUS_SRC = ft_atoi_max.c push_swap_bonus.c input.c stack.c\
			operations.c sort_big.c utils.c sort_small.c

ifdef BONUS
SRC = $(BONUS_SRC)
else
SRC = $(MAN_SRC)
endif
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	cd libft && make bonus
	$(CC) $(CFLAGS) -o push_swap $(SRC) $(LIBFT)

bonus:
	@make BONUS=1 all

clean:
	@cd libft && make clean
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all

