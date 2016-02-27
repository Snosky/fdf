/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:22:38 by tpayen            #+#    #+#             */
/*   Updated: 2016/02/27 17:16:02 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_env_init_err(void)
{
	ft_putendl_fd("fdf: Error on environment initialization", 2);
	exit(EXIT_FAILURE);
}

t_env	*init_env(char	*filename)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		ft_env_init_err();
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_SX, WIN_SY, filename);
	env->map = NULL;
	env->px.y = 0;
	env->max_y_map = 0;
	env->max_x_map = 0;
	env->ratio = 1;
	return (env);
}
