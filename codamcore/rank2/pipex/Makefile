NAME = pipex
CC = gcc
LIBFT = includes/libft/libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c helpers.c ft_split_quote.c
BONUS_SRCS = pipex_bonus.c
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)
OBJS	= $(SRCS:%.c=%.o)

ifdef BONUS
OBJ_F = $(BONUS_OBJS) $(OBJS)
else
OBJ_F = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	@cd includes/libft && make bonus
	@$(CC) $(CFLAGS) -o pipex $(SRCS) $(LIBFT)

bonus:
	@make BONUS=1 all

clean:
	@rm -f *.o
	@rm -f *.out
	@rm -f output.txt
	@cd includes/libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd includes/libft && make fclean

re: fclean all

.PHONY:	all clean fclean re
