/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 15:29:30 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/02 17:09:31 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_mapdel(void *px, size_t size)
{
	(void)size;
	free(px);
}

int			loop_hook(t_env *env)
{
	if (env->status == FDF_REFRESH)
	{
		ft_bzero(env->img.data, WIN_SX * WIN_SY * 4);
		mlx_clear_window(env->mlx, env->win);
		draw_map(env);
		env->status = FDF_WAIT;
	}
	else if (env->status == FDF_EXIT)
	{
		ft_lstdel(&(env->map), ft_mapdel);
		mlx_destroy_image(env->mlx, env->img.img);
		mlx_destroy_window(env->mlx, env->win);
		free(env->mlx);
		free(env);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
