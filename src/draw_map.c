/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:45:06 by tpayen            #+#    #+#             */
/*   Updated: 2016/02/27 18:42:22 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_env	*env)
{
/*	t_list	*map = env->map;
	t_px	*px;
	int		x;
	int		y;
	t_px	*pxn;
	int		x2;
	int		y2;

	while (map->next)
	{
		px = (t_px *)map->content;
		pxn = (t_px *)map->next->content;
		if (px->y == pxn->y)
		{

			x = (px->x - px->y) * (PX_SPACE / 2);
			x2 = (pxn->x - pxn->y) * (PX_SPACE / 2);
			y = (px->x + px->y - px->z) * ((PX_SPACE / 2) / 2);
			y2 = (pxn->x + pxn->y - pxn->z) * ((PX_SPACE / 2) / 2);
			//mlx_pixel_put(env->mlx, env->win, x, y, 0x00FFFFFF);
			draw_line(x, y, x2, y2, env->mlx, env->win);
		}
		map = map->next;
	}	*/
(void)env;
}
