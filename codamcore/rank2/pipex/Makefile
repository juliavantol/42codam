NAME = pipex
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:%.c=%.o)
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	@cd includes/libft && make bonus
	@$(CC) $(CFLAGS) -o pipex $(SRCS) includes/libft/libft.a

clean:
	rm -f *.o
	rm -f *.out
	@cd includes/libft && make clean

fclean: clean
	rm -f $(NAME)
	@cd includes/libft && make fclean

re: fclean all

run: all
	@$(CC) $(CFLAGS) -o pipex $(SRCS) && ./pipex