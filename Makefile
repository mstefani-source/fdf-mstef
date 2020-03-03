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

HEADERS	= -I fdf.h

SRC = fdf.c \
		ft_mouse_move.c \
		ft_mouse_release.c \
		ft_mouse_pressed.c \
		ft_plot_line.c \
		ft_discover_map.c \
		ft_open_window.c \
		ft_calc_digits.c \
		ft_fill_digits.c \
		ft_fzero.c  \
		ft_draw_map.c \
		ft_draw_lines.c \
		gnl/get_next_line.c \
        ft_transform.c \
        key_win.c \
        ft_put_pixel.c \
        ft_catch_order.c \
        ft_convert.c \
        ft_draw.c

LIBOBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra 
GLFLAGS = -lft -lm -lmlx -framework OpenGL -framework AppKit -L libft

$(NAME): $(LIBOBJ)
		make -C ./libft
		gcc $(CFLAGS) $(LIBOBJ) $(GLFLAGS) -o $(NAME)

%.o:%.c
	gcc $(CFLAGS) -MD -c $<  -o $@

all: $(NAME)
   
clean:
	make -C ./libft clean
	rm -rf $(LIBOBJ)

fclean: clean
	make -C ./libft fclean
	-rm -f $(NAME)

re: fclean all
