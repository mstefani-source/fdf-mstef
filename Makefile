NAME = fdf

SRC = fdf.c \
	src/ft_open_window.c \
	src/ft_key_win.c \
	src/ft_draw_map.c \
	src/ft_discover_map.c \
	src/ft_catch_order.c \
	src/ft_set_constants.c \
	src/ft_fzero.c \
	src/ft_convert.c \
	src/ft_calc_digits.c \
	src/ft_draw.c \
	src/ft_draw_lines.c \
	src/ft_fill_digits.c \
	src/ft_mouse_move.c \
	src/ft_mouse_pressed.c \
	src/ft_mouse_release.c \
	src/ft_plot_line.c \
	src/ft_put_pixel.c \
	src/ft_transform.c \
	gnl/get_next_line.c

INCLUDES = /usr/local/include

LIBOBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

$(NAME): $(LIBOBJ)
		make -C ./libft
		gcc $(CFLAGS) $(LIBOBJ) -L./libft -I $(INCLUDES) -lXext -lX11 -lmlx -lm -lft -o $(NAME)
%.o:%.c
		gcc -MD -c $<  -o $@

all: $(NAME)


clean:
	make -C ./libft clean
	rm -rf $(LIBOBJ)

fclean: clean
	make -C ./libft fclean
	-rm -f $(NAME)

re: fclean all
