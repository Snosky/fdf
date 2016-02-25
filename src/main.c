/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:39:12 by tpayen            #+#    #+#             */
/*   Updated: 2016/02/25 18:03:44 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(EXIT_SUCCESS);

	return (0);
}

void	draw_line(int xi, int yi, int xf, int yf, void *mlx, void *win)
{
	int	dx;
	int	dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;

	x = xi;
	y = yi;
	dx = xf - xi;
	dy = yf - yi;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(mlx, win, x, y, 0x0000FF00);
	if (dx > dy)
	{
		cumul = dx / 2;
		i = 1;
		while (i <= dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yinc;
			}
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			i++;
		}
	}
	else
	{
		cumul = dy / 2;
		i = 1;
		while (i <= dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			i++;
		}
	}
}

int		main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "fdf");
	//Make a square
	/*int y = 50;
	int x;
	while (y < 150)
	{
			x = 50;
		while (x < 150)
		{	
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}*/
	
	int cx1 = 50;
	int cy1 = 50;
	int cx2 = 250;
	int cy2 = 50;
	int cx3 = 250;
	int cy3 = 250;
	int cx4 = 50;
	int cy4 = 250;
	// Draw a line
	draw_line(cx1, cy1, cx2, cy2, mlx, win);
	draw_line(cx2, cy2, cx3, cy3, mlx, win);
	draw_line(cx3, cy3, cx4, cy4, mlx, win);
	draw_line(cx4, cy4, cx1, cy1, mlx, win);

	mlx_key_hook(win, key_hook, 0);
	mlx_loop(mlx);
	return (0);
}
/*
int		main(int ac, char **av)
{
	int	fd; //Map File Descriptor
	char	*line;
	t_env	*env;

	if (ac != 2)
	{
		ft_putendl_fd("fdf: Usage: ./fdf <map.fdf>", 2);
		exit (EXIT_FAILURE);
	}
	
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("fdf: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putendl_fd(": No such file", 2);
		exit (EXIT_FAILURE);
	}

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 500, 500, "fdf");

	while (get_next_line(fd, &line))
	{
		ft_putendl(line);		
	}

	close(fd);
	mlx_loop(env->mlx);
	return (0);
}*/
