# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rei <rei@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 15:16:05 by ryada             #+#    #+#              #
#    Updated: 2024/12/31 13:52:35 by rei              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
PRINTF_DIR = ft_printf/
OBJ_DIR = obj/
SRC_DIR = src/

SRC_FILES = main.c/
			error.c/
			push_stack.c/
SRC_PATHS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_FILES = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

INCLUDE = -I includes -L $(LIBFTDIR) -lft -L $(PRINTF_DIR) -lftprintf

# Rules
all: $(NAME)

# Target to create the binary
$(NAME): $(OBJ_FILES)
	@make -C $(LIBFTDIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME) $(INCLUDE)

# Rule to compile .c files into .o files, ensuring directories exist
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

# Cleaning object files and libraries
clean:
	$(RM) $(OBJ_FILES)
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFTDIR)
	@make clean -C $(PRINTF_DIR)

# Cleaning everything including the binary
fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFTDIR)
	@make fclean -C $(PRINTF_DIR)

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re

