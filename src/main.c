/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:17:50 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/02 16:46:36 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_err_usage(void)
{
	ft_putendl_fd("fdf: Usage: ./fdf <map.fdf>", 2);
	exit(EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		ft_err_usage();
	env = init_env(av[1]);
	get_map(av[1], env);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
	mlx_mouse_hook(env->win, mouse_hook, env);
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_loop(env->mlx);
	return (0);
}
