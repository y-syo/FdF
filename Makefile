# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 07:21:18 by mmoussou          #+#    #+#              #
#    Updated: 2024/02/12 18:05:15 by mmoussou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash

CC = gcc

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_INCLUDE = $(LIBFT_DIR)/include

CFLAGS = -Wall -Werror -Wextra -lSDL2 -lm 

INCLUDE = ./include

NAME = fdf

#find -type f -name "*.c" | sed "s/\.\///g" | xargs -Iname echo "`printf '\t\t\t'`" name "\\"
SRCS =

OBJS = $(SRCS:.c=.o)

MLX_SRC		= ./MacroLibX

MLX			= $(MLX_SRC)/libmlx.so


all: $(NAME)

$(LIBFT_DIR):
	@git clone -q https://github.com/y-syo/libft $(LIBFT_DIR)
	@printf " \x1B[1;34m[  ]\x1B[0m Cloned libft.\n"

$(MLX_SRC):
	@git clone -q https://github.com/seekrs/macrolibx $(MLX_SRC)
	@printf " \x1B[1;34m[  ]\x1B[0m Cloned MacroLibX.\n"

$(MLX): $(MLX_SRC)
	@make -s -j16 -C $(MLX_SRC) all

$(LIBFT): $(LIBFT_DIR)
	@make -s -C $(LIBFT_DIR)

%.o: %.c
	@printf "\x1B[2K\r \x1B[1;32m[ 󱌣 ]\x1B[0m Compiling Objects... : $<"
	@$(CC) $(CFLAGS) -I$(INCLUDE) $< -c -o $@

$(NAME): $(LIBFT) $(OBJS) $(MLX)
	@printf "\x1B[2K\r \x1B[1;32m[ 󱌣 ]\x1B[0m Objects Compiled."
	@printf "\n \x1B[1;33m[ 󱉟 ]\x1B[0m Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -I$(INCLUDE) -I$(LIBFT_INCLUDE) -o $(NAME)
	@printf "\x1B[2K\r \x1B[1;33m[ 󱉟 ]\x1B[0m $(NAME) Compiled.\n"

clean:
	@make -s -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@printf " \x1B[1;31m[  ]\x1B[0m Deleted Objects.\n"

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@printf " \x1B[1;31m[  ]\x1B[0m Deleted $(NAME).\n"

re: fclean all

.PHONY: all server client clean fclean re
