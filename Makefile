# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/28 23:38:57 by mmoussou          #+#    #+#              #
#    Updated: 2023/12/28 23:48:52 by mmoussou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# find -type f -name "*.c" | sed "s/\.\///g" | xargs -Iname echo "`printf '\t\t\t'`" name "\\"
SRCS =	main.c \
		draw_line.c \

OBJS = ${SRCS:.c=.o}

OBJS += ./MacroLibX/libmlx.so

CC = gcc

CFLAGS = -Wall -Werror -Wextra -lSDL2

all: ${OBJS}
	${CC} ${OBJS} ${CFLAGS}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f a.out

re:	fclean all

.PHONY:	all clean fclean re
