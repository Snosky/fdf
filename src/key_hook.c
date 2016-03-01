/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 15:24:19 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/01 23:13:06 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_env *env)
{
	if (keycode == 65307)
		env->status = FDF_EXIT;
	else if (keycode == 65362)
	{
		
		env->img.pos_y += 5;
		env->status = FDF_REFRESH;
	}
	else if (keycode == 65361)
	{
		env->img.pos_x += 5;
		env->status = FDF_REFRESH;
	}
	else if (keycode == 65363)
	{
		env->img.pos_x -= 5;
		env->status = FDF_REFRESH;
	}
	else if (keycode == 65364)
	{
		env->img.pos_y -= 5;
		env->status = FDF_REFRESH;
	}
	else if (keycode == 65451)
	{
		env->pxspace += 5;
		env->status = FDF_REFRESH;
	}
	else if (keycode == 65453)
	{
		env->pxspace -= 5;
		env->status = FDF_REFRESH;
	}
	return (0);
}
