#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etexier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 11:32:12 by etexier           #+#    #+#              #
#    Updated: 2019/11/18 18:36:14 by etexier          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS		= 	fillit.c \
				fillit_utils1.c \
				fillit_utils2.c \
				fillit_utils3.c \
				get_next_line.c \
				tetrino_lst.c \
				tetrino_bound.c \
				fillit_grid.c \
				tetrino_print.c \
				tetrino_world.c

OBJS		= ${SRCS:.c=.o}

CC			= clang

CFLAGS		= -Wall -Wextra -Werror -I./libft/includes

LDFLAGS		= -lft -L./libft

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

NAME		=  fillit

AR			= ar rc

RM			= rm -f

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} ${LDFLAGS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
