NAME = convert
CPPFLAGS = -Wall -Wextra -Werror -std=c++11 -fsanitize=address
INC = -I include
CC = c++
SRC = src/Main.cpp src/ScalarConverter.cpp src/Helpers.cpp
OBJ_DIR = obj/
SRC_DIR = src/
OBJ = $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

GREEN=\033[0;32m
END=\033[0m
BOLD=\033[1m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "---------$(BOLD)Linking...$(END)---------"
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(BOLD)["$(NAME)"]$(END)" "ready for execution!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	@echo "$(BOLD)Compiling$(END) $(GREEN)$< $(END)"
	@$(CC) $(CPPFLAGS) $(INC) -c $< -o $@

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	echo "$(BOLD)Cleaning $(END)$(GREEN)obj folder$(END)"; \
	fi
	@rm -rf $(OBJ_DIR)

fclean: clean
	@if [ -f "$(NAME)" ]; then \
	echo "$(BOLD)Cleaning $(END)$(GREEN)executable$(END)"; \
	fi
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re