NAME = pipex
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o pipex $(SRCS)

clean:
	rm -f *.o
	rm -f *.out

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

run: all
	@$(CC) $(CFLAGS) -o pipex $(SRCS) && ./pipex