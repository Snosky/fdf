/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:52:49 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/02 16:53:40 by tpayen           ###   ########.fr       */
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

static void		line_dx_to_dy(t_line line, t_env *env)
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
		ft_px_img(env, line);
		i++;
	}
}

static void		line_dy_to_dx(t_line line, t_env *env)
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
		ft_px_img(env, line);
		i++;
	}
}

void			draw_line(t_px px1, t_px px2, t_env *env)
{
	t_line	line;

	line = calc_line(px1, px2, env);
	if (line.dx > line.dy)
		line_dx_to_dy(line, env);
	else
		line_dy_to_dx(line, env);
}
