/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:39:12 by tpayen            #+#    #+#             */
/*   Updated: 2016/02/26 15:12:40 by tpayen           ###   ########.fr       */
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
/*
int		main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_SX, WIN_SY, "fdf");
	//Make a square
	int y = 50;
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
	}

	int cx1 = WIN_SX / 100  * 25;
	int cy1 = WIN_SY / 100 * 25;
	int cx2 = WIN_SX / 100 * 75;
	int cy2 = WIN_SY / 100 * 25;
	int cx3 = WIN_SX / 100 * 75;
	int cy3 = WIN_SY / 100 * 75;
	int cx4 = WIN_SX / 100 * 25;
	int cy4 = WIN_SY / 100 * 75;
	// Draw a line
	draw_line(cx1, cy1, cx2, cy2, mlx, win);
	draw_line(cx2, cy2, cx3, cy3, mlx, win);
	draw_line(cx3, cy3, cx4, cy4, mlx, win);
	draw_line(cx4, cy4, cx1, cy1, mlx, win);

	mlx_key_hook(win, key_hook, 0);
	mlx_loop(mlx);
	return (0);
}
*/
int		main(void)
{
	char	file[5][5] = {
							{0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0}
						};
	t_env	*env;

	//TODO : lire le fichier et le verifier

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_SX, WIN_SY, "fdf");

	// Test affichage point
	//int	line_size = ft_strlen(file[0]);

	mlx_loop(env->mlx);
	return (0);
}
