NAME = pipex
LIBFT = includes/libft/libft.a
PRINTF = includes/printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:%.c=%.o)
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	@cd includes/libft && make bonus
	@cd includes/printf && make
	@$(CC) $(CFLAGS) -o pipex $(SRCS) $(LIBFT) $(PRINTF)

clean:
	rm -f *.o
	rm -f *.out
	@cd includes/libft && make clean
	@cd includes/printf && make clean

fclean: clean
	rm -f $(NAME)
	@cd includes/libft && make fclean
	@cd includes/printf && make fclean

re: fclean all

run: all
	@$(CC) $(CFLAGS) -o pipex $(SRCS) && ./pipex