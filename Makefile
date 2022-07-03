# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 14:03:47 by ghenaut-          #+#    #+#              #
#    Updated: 2022/07/03 15:04:19 by ghenaut-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all bonus clean fclean re

NAME		= fdf
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3
HEADER		= fdf.h

B_NAME		= fdf_bonus

LIBFT	= libft.a
MLX		= mlx.a
IFT		= -Ilibft -Llibft -lft
IMLX	= -Imlx -Lmlx -lmlx -lXext -lX11

SRCS	= 	fdf.c \
			init_game.c \
			exit.c \
			draw.c \
			print_debug.c  # remove when done


B_SRCS	=   

OBJSDIR	= ./obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})
B_OBJS	= $(addprefix ${OBJSDIR}/, ${B_SRCS:%.c=%.o})

all: ${NAME}
	@make clean
bonus: ${NAME}_bonus

${NAME}: ${OBJSDIR} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${IFT} ${IMLX} -o $@

${NAME}_bonus: ${OBJSDIR} ${B_OBJS}
	${CC} ${CFLAGS} ${B_OBJS} ${IFT} ${IMLX} -o $@

${OBJSDIR}:
	mkdir -p $@

${OBJS}: | ${LIBFT} ${MLX}
${B_OBJS}: | ${LIBFT} ${MLX}

${OBJSDIR}/%.o: src/%.c src/fdf.h Makefile
	${CC} ${CFLAGS} -c $< -o $@

${OBJSDIR}/%.o: bonus/%.c bonus/fdf_bonus.h Makefile
	${CC} ${CFLAGS} -c $< -o $@

${LIBFT}: | libft
	${MAKE} -C libft/

${MLX}: | mlx
	${MAKE} -C mlx/

libft:
	git clone https://github.com/GabrielHenaut/libft.git

mlx:
	git clone https://github.com/42Paris/minilibx-linux.git mlx

clean:
	${MAKE} clean -C libft
	${MAKE} clean -C mlx
	rm -rf ${OBJSDIR}

fclean: clean
	rm -rf libft mlx ${NAME} ${NAME}_bonus

re: fclean all