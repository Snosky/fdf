/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 15:24:19 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/02 17:04:11 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move_y(int i, t_env *env)
{
	env->status = FDF_REFRESH;
	env->img.pos_y += i;
}

static void	move_x(int i, t_env *env)
{
	env->status = FDF_REFRESH;
	env->img.pos_x += i;
}

int			key_hook(int keycode, t_env *env)
{
	if (keycode == 65307 || keycode == 53)
		env->status = FDF_EXIT;
	else if (keycode == 65362 || keycode == 126)
		move_y(5, env);
	else if (keycode == 65361 || keycode == 123)
		move_x(5, env);
	else if (keycode == 65363 || keycode == 124)
		move_x(-5, env);
	else if (keycode == 65364 || keycode == 125)
		move_y(-5, env);
	else if (keycode == 65451 || keycode == 69)
	{
		env->pxspace += 5;
		env->status = FDF_REFRESH;
	}
	else if (keycode == 65453 || keycode == 78)
	{
		if (env->pxspace - 5 > 0)
		{
			env->pxspace -= 5;
			env->status = FDF_REFRESH;
		}
	}
	return (0);
}
