NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -framework Cocoa -framework OpenGL -framework IOKit
LIBFT = include/libft/libft.a
INCLUDES = -I include
LIBS	:= MLX42/build/libmlx42.a -Iinclude -lglfw
SRC = include/get_next_line/get_next_line.c include/get_next_line/get_next_line_utils.c \
		src/game/collectibles.c src/map/map_utils.c src/game/window.c src/game/images.c \
		src/game/moves.c src/map/check_path.c src/map/check_map.c src/game/utils.c main.c \
		src/game/food.c src/game/enemies/move_enemy.c \
		src/game/player/animation.c src/game/enemies/spawn_enemies.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(INCLUDES) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(LIBFT) -o $(NAME)

clean:
	@cd include/libft && make clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all

