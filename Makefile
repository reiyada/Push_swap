# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryada <ryada@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 17:05:33 by ryada             #+#    #+#              #
#    Updated: 2025/02/05 15:46:58 by ryada            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
PRINTF_DIR = ft_printf/
OBJ_DIR = obj/
SRC_DIR = src/

SRC_FILES = error.c \
			main.c \
			rule_p.c \
			rule_r.c \
			rule_rr.c \
			rule_s.c \
			set_node.c \
			set_stack.c \
			tiny_sort.c \
			turk_sort.c \
			turk_util.c \
			update_node.c \
			update_stack.c \
			util.c
SRC_PATHS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_FILES = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

INCLUDE = -I includes -L $(LIBFTDIR) -lft -L $(PRINTF_DIR) -lftprintf

all: $(NAME)
	@echo "🚀 Compilation started..."
	@echo "📦 Building executable: $(NAME)"
	@echo "-----------------------------------"

$(NAME): $(OBJ_FILES)
	@make -C $(LIBFTDIR) --silent
	@make -C $(PRINTF_DIR) --silent
	@$(CC) $(FLAGS) -no-pie $(OBJ_FILES) -o $(NAME) $(INCLUDE)
	@echo "✅ Compilation successful!"
	@echo "🎯 Run with: ./$(NAME)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "🔨 Compiling: $<"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_FILES) 
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFTDIR) --silent
	@make clean -C $(PRINTF_DIR) --silent
	@echo "🧹 Cleaned object files of $(NAME)!"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFTDIR) --silent
	@make fclean -C $(PRINTF_DIR) --silent
	@echo "🗑️  Removed executable and object files of $(NAME)!"

re: fclean all
	@echo "🔄 Recompiling the project..."
