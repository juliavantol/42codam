NAME = pipex
CC = gcc
LIBFT = includes/libft/libft.a
CFLAGS = -Wall -Wextra -Werror
MAN_SRCS = pipex.c utils.c ft_split_args.c free.c
BONUS_SRCS = pipex_bonus.c utils_bonus.c ft_split_args_bonus.c free_bonus.c

ifdef BONUS
SRC = $(BONUS_SRCS)
else
SRC = $(MAN_SRCS)
endif

OBJS	= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@cd includes/libft && make bonus
	@$(CC) $(CFLAGS) -o pipex $(SRC) $(LIBFT)

bonus:
	@make BONUS=1 all

clean:
	@rm -f *.o
	@rm -f *.out
	@rm -f output.txt
	@rm -f input.txt
	@cd includes/libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd includes/libft && make fclean

re: fclean all

.PHONY:	all clean fclean re
