# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eryanik <eryanik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 22:23:42 by eryanik           #+#    #+#              #
#    Updated: 2023/07/16 23:37:08 by eryanik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=		main.c	ft_atoi.c parsing2.c list.c others.c parsing.c testnum.c

OBJS	= ${SRCS:.c=.o}

NAME 	= rush02

CC 		= cc
RM		= rm -f

CFlags = -Wall -Werror -Wextra

.c.o :
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
					${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
					${RM} ${OBJS}

fclean:			clean
					${RM} ${NAME}

re:					fclean all
