# Default base directories
BASE_DIR_DEFAULT = /home/juvan-to
BASE_DIR_HOME = /Users/Julia/Documents

# Select base directory (default to codam if neither 'make home' nor 'make codam' is used)
BASE_DIR ?= $(BASE_DIR_DEFAULT)

WP_DATA = $(BASE_DIR)/data/wordpress
DB_DATA = $(BASE_DIR)/data/mariadb

# Define colors
YELLOW = \033[1;33m
RED = \033[1;31m
GREEN = \033[1;32m
NC = \033[0m  # No Color

# Home and codam targets to set BASE_DIR
home:
	$(MAKE) BASE_DIR=$(BASE_DIR_HOME) all

codam:
	$(MAKE) BASE_DIR=$(BASE_DIR_DEFAULT) all

# Default target
all: build up

# Start the building process
up:
	@mkdir -p $(WP_DATA)
	@mkdir -p $(DB_DATA)
	docker-compose -f ./srcs/docker-compose.yml up -d

# Build the containers
build:
	docker-compose -f ./srcs/docker-compose.yml build

# Stop the containers
down:
	docker-compose -f ./srcs/docker-compose.yml down

# Start the containers
start:
	docker-compose -f ./srcs/docker-compose.yml start

kill:
	docker-compose -f ./srcs/docker-compose.yml kill

wp:
	docker exec -it wordpress bash

mariadb:
	docker exec -it mariadb bash

logs:
	docker-compose -f ./srcs/docker-compose.yml logs

# Clean the containers
clean:
	@echo -e "$(YELLOW)Stopping all running containers...$(NC)"
	@docker stop $$(docker ps -qa) || true
	@echo -e "$(YELLOW)Removing all containers...$(NC)"
	@docker rm $$(docker ps -qa) || true
	@echo -e "$(YELLOW)Removing all images...$(NC)"
	@docker rmi -f $$(docker images -qa) || true
	@echo -e "$(YELLOW)Removing all volumes...$(NC)"
	@docker volume rm $$(docker volume ls -q) || true
	@echo -e "$(YELLOW)Removing all networks...$(NC)"
	@docker network rm $$(docker network ls -q) || true
	@echo -e "$(RED)Removing WordPress data directory: $(WP_DATA)$(NC)"
	@sudo rm -rf $(WP_DATA) || true
	@echo -e "$(RED)Removing MariaDB data directory: $(DB_DATA)$(NC)"
	@sudo rm -rf $(DB_DATA) || true
	@echo -e "$(GREEN)Clean-up completed.$(NC)"

# Clean and start the containers
re: clean up

# Prune the containers
prune: clean
	@docker system prune -a --volumes -f
