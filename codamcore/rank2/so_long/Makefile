NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -framework Cocoa -framework OpenGL -framework IOKit
LIBFT = include/libft/libft.a
LIBS	:= MLX42/build/libmlx42.a -Iinclude -lglfw3
SRC = main.c src/utils.c include/get_next_line/get_next_line.c include/get_next_line/get_next_line_utils.c \
		src/collectibles.c src/map_validity.c src/window.c src/images.c src/moves.c \
		src/find_path.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(LIBFT) -o $(NAME)
	

clean:
	@cd include/libft && make clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all

