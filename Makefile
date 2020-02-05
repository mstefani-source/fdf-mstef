# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 17:09:34 by mstefani          #+#    #+#              #
#    Updated: 2020/02/03 15:49:30 by mstefani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADERS	=-I fdf.h

SRC = fdf.c \
		ft_veryfy.c \
		ft_mouse_move.c \
		ft_mouse_release.c \
		ft_mouse_pressed.c

LIBOBJ=$(SRC:.c=.o)

LIBNAME = ./libft/libft.a
##MINILIBS = ./minilibx_macos/libmlx.a

CFLAGS = -Wall -Werror -Wextra 
GLFLAGS = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(LIBOBJ)
		make -C ./libft 
##		make -C ./minilibx_macos 
		gcc $(CFLAGS) $(LIBOBJ) $(LIBNAME) $(GLFLAGS) -o $(NAME) 
##		$(HEADERS)

%.o:%.c
	gcc $(CFLAGS) $< -c -o $@

all: $(NAME)
   
clean:
	make -C ./libft clean
	rm -rf $(LIBOBJ)
##	make -C ./minilibx_macos clean
##	rm -rf $(MINILIBS)

fclean: clean
	make -C ./libft fclean
	-rm -f $(NAME)
##	make -C ./minilibx_macos clean

re: fclean all
