#include "../fdf.h"

char	*ft_nextd(char *line)
{
	while (!ft_isdigit(*line) && *line != '\0')
		line++;
	return (line);
}

char	*ft_nexts(char *line)
{
	while (*line != ' ' && *line != '\0')
		line++;
	return (line);
}

int		ft_readcolor(char *line)
{
	char	hexc[6];
	int		i;
	int		color;

	i = 0;
	line = line + 3;
	while (*line != ' ' && *line != '\0')
	{
		hexc[i++] = *line;
		line++;
	}
	hexc[i] = '\0';
	color = ft_atoi_base(hexc, 16);
	return (color);
}

int		ft_fill_line(char *line, t_dot *dots)
{
	int res;
	int x;

	x = 0;
	res = 0;

	line = ft_nextd(line);
	while (*line)
	{
		if (*line >= '0' && *line <= '9')
		{
			res *= 10;
			res = res + (*line - '0');
			line++;
		}
		else if (*line == ' ')
		{
			dots[x].z0 = dots[x].z = res;
			line = ft_nextd(line);
			res = 0;
			x++;
		}
		else if (*line == ',')
		{
			dots[x].c = ft_readcolor(line);
			line = ft_nexts(line);
		}
	}
	return (0);
}

t_dot	**ft_fill_map(t_mlx *mlx, char *filename)
{
	t_dot	**dots;
	char 	*line;
	int		y;
	int 	fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
		exit(1);
	y = 0;
	dots = (t_dot **)malloc(sizeof(t_dot *) * mlx->my);
	while (get_next_line(fd, &line) != 0)
	{
		dots[y] = (t_dot *) malloc(sizeof(t_dot) * mlx->mx);
		ft_fzero(dots[y], y, mlx->mx, mlx);
		ft_fill_line(line, dots[y]);
		y++;
	}
	close(fd);
return (dots);
}