NAME = pipex
LIBFT = includes/libft/libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c helpers.c
OBJS = $(SRCS:%.c=%.o)
CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	@cd includes/libft && make bonus
	@$(CC) $(CFLAGS) -o pipex $(SRCS) $(LIBFT)

clean:
	@rm -f *.o
	@rm -f *.out
	@cd includes/libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd includes/libft && make fclean

re: fclean all

.PHONY:	all clean fclean re
