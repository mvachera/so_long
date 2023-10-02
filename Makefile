# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 20:17:33 by mvachera          #+#    #+#              #
#    Updated: 2023/07/16 19:11:52 by mvachera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long

CC              = clang

CFLAGS  = -Wall -Wextra -Werror -g3

RM              = rm -f

PRINTF		= ft_printf

FT_PRINTF	= ft_printf/libftprintf.a

SRC     = srcs/main.c srcs/hook.c srcs/move.c srcs/parsing.c srcs/back_tracking.c srcs/get_cell.c srcs/check.c srcs/utils.c srcs/finito.c srcs/image.c gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ	= ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${MAKE} -C ${PRINTF}
	${CC} ${OBJ} ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a -lX11 -lXext -L -lX11 -o ${NAME} ${FT_PRINTF}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
