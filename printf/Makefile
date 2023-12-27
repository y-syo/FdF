# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoussou <mmoussou@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 03:48:58 by mmoussou          #+#    #+#              #
#    Updated: 2023/11/16 23:39:51 by mmoussou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_printf_prints.c \
		ft_printf_utils.c \

OBJS = ${SRCS:.c=.o}

INCLUDE = .

CC = gcc

CFLAGS = -Wall -Werror -Wextra



all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCLUDE}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
