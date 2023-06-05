NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = include/libft/libft.a
INCLUDES = -I include
MLX42 = MLX42/build/libmlx42.a
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw3
SRC = include/get_next_line/get_next_line.c include/get_next_line/get_next_line_utils.c \
		src/game/collectibles.c src/map/map_utils.c src/game/window.c src/game/images.c \
		src/game/player/move_player.c src/map/check_path.c src/map/init_game.c \
		src/game/utils.c main.c src/game/enemies/move_enemy.c \
		src/game/player/animation.c src/game/enemies/spawn_enemies.c
OBJ = $(SRC:%.c=%.o)

BLUE	:= \033[34;1m
END		= \x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)Start compiling $(NAME) using $(CFLAGS)$(END)"
	@cd include/libft && make bonus
	@make -C MLX42/build
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42) $(MLXFLAGS)
	@echo "$(BLUE)Done!$(END)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $^

bonus: ${NAME}

clean:
	@cd include/libft && make clean
	@rm -rf $(MLX42)
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus