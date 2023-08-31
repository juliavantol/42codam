NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I inc
LIBFT = inc/libft/libft.a
SRCS = pipex.c utils/utils.c utils/ft_split_args.c utils/free.c main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: src/%.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C inc/libft

clean:
	rm -f $(OBJS)
	make clean -C inc/libft

fclean: clean
	rm -f $(NAME)
	make fclean -C inc/libft

re: fclean all

.PHONY: all clean fclean re
