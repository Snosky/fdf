
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:39:12 by tpayen            #+#    #+#             */
/*   Updated: 2016/02/28 17:16:33 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static void	calc_line(t_px *px1, t_px *px2, t_env *env)
{
	t_line	*line;
	int		x2;
	int		y2;

	line = &(env->line);
	x2 = (px2->x - px2->y) * (PX_SPACE / 2);
	y2 = (px2->x + px2->y - px2->z) * (PX_SPACE / 4);
	line->x = (px1->x - px1->y) * (PX_SPACE / 2);
	line->y = (px1->x + px1->y - px1->z) * (PX_SPACE / 4);
	line->dx = abs(x2 - line->x);
	line->dy = abs(y2 - line->y);
	line->xinc = ((x2 - line->x) > 0) ? 1 : -1;
	line->yinc = ((y2 - line->y) > 0) ? 1 : -1;*
}
*/
void	draw_line(t_px *px1, t_px *px2, t_env *env)	
//void	draw_line(int xi, int yi, int xf, int yf, void *mlx, void *win)
{
	int	dx;
	int	dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;
	int	x2;
	int	y2;

	x = (px1->x - px1->y) * (PX_SPACE / 2);
	y = (px1->x + px1->y - px1->z) * (PX_SPACE / 4);
	x2 = (px2->x - px2->y) * (PX_SPACE / 2);
	y2 = (px2->x + px2->y - px2->z) * (PX_SPACE / 4);
	dx = x2 - x;
	dy = y2 - y;
	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	mlx_pixel_put(env->mlx, env->win, x, y, 0x0000FF00);
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
			mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
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
			mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
			i++;
		}
	}
}
