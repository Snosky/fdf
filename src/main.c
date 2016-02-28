/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:17:50 by tpayen            #+#    #+#             */
/*   Updated: 2016/02/28 17:43:52 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_err_usage(void)
{
	ft_putendl_fd("fdf: Usage: ./fdf <map.fdf>", 2);
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		ft_err_usage();
	env = init_env(av[1]);
	get_map(av[1], env);
	draw_map(env);
	mlx_loop(env->mlx);
	return (0);
}
