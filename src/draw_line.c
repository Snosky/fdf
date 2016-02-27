/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:39:12 by tpayen            #+#    #+#             */
/*   Updated: 2016/02/27 17:54:49 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
