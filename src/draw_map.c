/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:45:06 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/01 16:21:00 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_px	gpx(t_list *map)
{
	return (*((t_px *)map->content));	
}

void	draw_map(t_env *env)
{
	t_list	*map;
	t_list	*map_delay;

	map = env->map;
	map_delay = env->map;
	while (map)
	{
		if (map->next != NULL && gpx(map).y == gpx(map->next).y)
			draw_line(gpx(map), gpx(map->next), env);
		if (gpx(map_delay).y != gpx(map).y && gpx(map_delay).x == gpx(map).x)
		{
			draw_line(gpx(map_delay), gpx(map), env);
			map_delay = map_delay->next;
		}
		map = map->next;
	}
	//mlx_put_image_to_window(env->mlx, env->win, env->img.img, env->img.pos_x, env->img.pos_y);
}
