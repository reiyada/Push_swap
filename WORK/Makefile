# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryada <ryada@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 17:05:33 by ryada             #+#    #+#              #
#    Updated: 2025/01/23 10:43:31 by ryada            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g
LIBFTDIR = libft/
PRINTF_DIR = ft_printf/
OBJ_DIR = obj/
SRC_DIR = src/

SRC_FILES = error.c \
			main.c \
			push_stack.c \
			rule_p.c \
			rule_r.c \
			rule_s.c \
			sort_small.c \
			Turk.c
SRC_PATHS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_FILES = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

INCLUDE = -I includes -L $(LIBFTDIR) -lft -L $(PRINTF_DIR) -lftprintf

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C $(LIBFTDIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME) $(INCLUDE)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_FILES)
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFTDIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFTDIR)
	@make fclean -C $(PRINTF_DIR)

re: fclean all
