/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:17:50 by tpayen            #+#    #+#             */
/*   Updated: 2016/02/27 18:57:05 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_err_usage(void)
{
	ft_putendl_fd("fdf: Usage: ./fdf <map.fdf>", 2);
	exit(EXIT_FAILURE);
}
#include <stdio.h>
int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		ft_err_usage();
	env = init_env(av[1]);
	get_map(av[1], env);
	draw_map(env);
/*
	t_list	*map = env->map;
	t_px *px;
	while (map)
	{
		px = map->content;
		printf("X: %d, Y: %d, Z: %d\n", px->x, px->y, px->z);
		map = map->next;
	}
*/
	t_list	**map = env->map;
	t_px *px;
	int	i;
i = 0;
	while (map[i])
	{
		while (map[i])
		{
			px = (t_px *)map[i]->content;

			printf("X: %d, Y: %d, Z: %d\n", px->x, px->y, px->z);
			map[i] = map[i]->next;
		}
		i++;
	}
	mlx_loop(env->mlx);
	return (0);
}
