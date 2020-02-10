# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 17:09:34 by mstefani          #+#    #+#              #
#    Updated: 2020/02/09 19:38:06 by mstefani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

HEADERS	=-I fdf.h

SRC = fdf.c \
		ft_veryfy.c \
		ft_mouse_move.c \
		ft_mouse_release.c \
		ft_mouse_pressed.c \
		ft_plot_line.c \
		ft_discover_map.c \
		gnl/get_next_line.c

LIBOBJ=$(SRC:.c=.o)

LIBNAME = ./libft/libft.a

CFLAGS = -Wall -Werror -Wextra 
GLFLAGS = -lm -lmlx -framework OpenGL -framework AppKit

$(NAME): $(LIBOBJ)
		make -C ./libft
		gcc $(CFLAGS) $(LIBOBJ) $(LIBNAME) $(GLFLAGS) -o $(NAME)

%.o:%.c
	gcc $(CFLAGS) $< -c -o $@

all: $(NAME)
   
clean:
	make -C ./libft clean
	rm -rf $(LIBOBJ)

fclean: clean
	make -C ./libft fclean
	-rm -f $(NAME)

re: fclean all
