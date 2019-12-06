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
				fillit_utils.c \
				fillit_utils1.c \
				fillit_utils2.c \
				fillit_utils3.c \
				get_next_line.c \
				tetrino_lst.c \
				tetrino_bound.c \
				fillit_grid.c \
				fillit_grid_bt.c \
				tetrino_print.c \
				tetrino_world.c \
				gbox.c 

DEPENDS		:= $(patsubst %.c,%.d,$(SRCS))

OBJS		= ${SRCS:.c=.o}

CC			= clang

CFLAGS		= -Wall -Wextra -Werror -I../fillit/libft/includes -I. -DDUMMY_BT

LDFLAGS		= -lft -L../fillit/libft

.c.o:
			${CC} ${CFLAGS} -MMD -MP -c $< -o ${<:.c=.o}

NAME		=  fillit_bt

AR			= ar rc

RM			= rm -f

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS} ${LDFLAGS} ${CFLAGS}

all:		parking

parking:	$(OBJS)
			$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

-include $(DEPENDS)

clean:
			${RM} ${OBJS} ${DEPENDS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean re
