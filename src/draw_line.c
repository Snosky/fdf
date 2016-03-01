
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

static t_line	calc_line(t_px px1, t_px px2, t_env *env)
{
	t_line	line;
	int		x2;
	int		y2;

	x2 = (px2.x - px2.y) * (env->pxspace / 2) + env->img.pos_x;
	y2 = (px2.x + px2.y - px2.z) * (env->pxspace / 4) + env->img.pos_y;
	line.x = (px1.x - px1.y) * (env->pxspace / 2) + env->img.pos_x;
	line.y = (px1.x + px1.y - px1.z) * (env->pxspace / 4) + env->img.pos_y;
	line.dx = abs(x2 - line.x);
	line.dy = abs(y2 - line.y);
	line.xinc = ((x2 - line.x) > 0) ? 1 : -1;
	line.yinc = ((y2 - line.y) > 0) ? 1 : -1;
	return (line);
}

static void	line_dx_to_dy(t_line line, t_env *env)
{
	int	cumul;
	int	i;

	cumul = line.dx / 2;
	i = 1;
	while (i <= line.dx)
	{
		line.x += line.xinc;
		cumul += line.dy;
		if (cumul >= line.dx)
		{
			cumul -= line.dx;
			line.y += line.yinc;
		}
		//ft_px_img(env, line);
		mlx_pixel_put(env->mlx, env->win, line.x, line.y, 0x00FFFFFF);
		i++;
	}
}

static void	line_dy_to_dx(t_line line, t_env *env)
{
	int	cumul;
	int	i;

	cumul = line.dy / 2;
	i = 1;
	while (i <= line.dy)
	{
		line.y += line.yinc;
		cumul += line.dx;
		if (cumul >= line.dy)
		{
			cumul -= line.dy;
			line.x += line.xinc;
		}
		//ft_px_img(env, line);
		mlx_pixel_put(env->mlx, env->win, line.x, line.y, 0x00FFFFFF);
		i++;
	}

}

void	draw_line(t_px px1, t_px px2, t_env *env)
{
	t_line	line;
	
	/*px1.x = (px1.x + env->img.pos_x) * env->ratio;
	px1.y = (px1.y + env->img.pos_y) * env->ratio;
	px2.x = (px2.x + env->img.pos_x) * env->ratio;
	px2.y = (px2.y + env->img.pos_y) * env->ratio;*/
	px1.x = (px1.x) * env->ratio;
	px1.y = (px1.y) * env->ratio;
	px2.x = (px2.x) * env->ratio;
	px2.y = (px2.y) * env->ratio;
	//Reste le Z

	line = calc_line(px1, px2, env);
	if (line.dx > line.dy)
		line_dx_to_dy(line, env);
	else
		line_dy_to_dx(line, env);
}
/*
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
}*/
