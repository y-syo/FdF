# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 16:27:11 by mmoussou          #+#    #+#              #
#    Updated: 2023/12/30 21:28:16 by mmoussou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

MLX_SRC		= MacroLibX
MLX			= libmlx.so

SRCS		= src/main.c \
			  src/draw_line.c \

OBJS		= ${SRCS:.c=.o}

INCLUDE		= include

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
COPTS		= -I ./${INCLUDE} -lSDL2 -lm

all:		${NAME} clean

.c.o:
	@${CC} ${CFLAGS} -o $@ -c $< ${COPTS}

${NAME}:	${OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${SRCS} ${MLX_SRC}/${MLX} printf/libftprintf.a ${COPTS}

${MLX}:
	@make --no-print-directory -C ${MLX_SRC} all

clean:
	@rm -f ${OBJS}

fclean:	clean
	@rm -f ${NAME}

re:	fclean all
