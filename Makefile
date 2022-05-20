# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkailany <lkailany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 16:15:41 by lkailany          #+#    #+#              #
#    Updated: 2022/03/31 12:31:15 by lkailany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = so_long

CFLAGS = -Wall -Wextra -Werror 

MINILIBX = -L minilibx -lmlx -framework OpenGL -framework AppKit

SRCS = src/ft_printf.c src/character.c src/check_data.c src/get_next_line.c src/get_next_line_utils.c src/init_game.c src/main.c src/parsing.c src/end_msg.c src/utils.c

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
		make -C minilibx
		mv minilibx/libmlx.dylib .
		$(CC) ${OBJS} ${MINILIBX} -o $(NAME)

all: ${NAME}

clean:
		rm -rf *.o
		make clean -C minilibx
	
fclean: clean
		rm -f ${OBJS} ${NAME} libmlx.dylib

re: fclean ${NAME}