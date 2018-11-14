# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pihouvie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 22:42:57 by pihouvie          #+#    #+#              #
#    Updated: 2018/02/01 17:04:10 by pihouvie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

OBJ = burningship.o mandelbrot.o main.o divers.o julia.o hooks.o

SRC = $(OBJ:.o=.c)

all : $(NAME)

$(NAME) : $(SRC) ftl.h
	make -C libft
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc -o $(NAME) $(OBJ) libft/libft.a -lmlx -framework OpenGL -framework AppKit
	rm -rf $(OBJ)
clean :
	rm -rf $(OBJ)
	make clean -C libft

fclean : clean
	rm -rf $(NAME)
	rm -rf libft/libft.a

re : fclean all

.PHONY : all clean fclean re
